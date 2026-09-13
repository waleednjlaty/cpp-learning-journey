#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>

using namespace sf;

// حجم المربع الواحد (بالبكسل)
const int blockSize = 30;
// عدد المربعات في العرض والطول
const int width = 20;
const int height = 20;

// اتجاهات الحركة
int dir = 0; // 1:Left, 2:Right, 3:Up, 0:Down

struct SnakeSegment
{
    int x, y;
};

struct Fruit
{
    int x, y;
} apple;

int main()
{
    // إنشاء نافذة اللعبة
    // حجم النافذة = عدد المربعات * حجم المربع
    RenderWindow window(VideoMode(width * blockSize, height * blockSize), "Snake Game SFML");

    // تحديد معدل الإطارات (FPS)
    window.setFramerateLimit(60);

    // --- تحميل الصور (اختياري) ---
    // لاستخدام صور حقيقية، قم بإلغاء التعليق عن الأسطر التالية وتأكد من وجود الصور بجانب ملف exe
    /*
    Texture tSnake, tApple, tBackground;
    tSnake.loadFromFile("snake.png");
    tApple.loadFromFile("apple.png");
    tBackground.loadFromFile("bg.png");

    Sprite sSnake(tSnake);
    Sprite sApple(tApple);
    Sprite sBackground(tBackground);
    */
    // ---------------------------

    srand(time(0));

    // إعداد الثعبان الأولي
    std::vector<SnakeSegment> snake;
    snake.push_back({10, 10}); // الرأس
    snake.push_back({10, 11}); // ذيل
    snake.push_back({10, 12}); // ذيل

    // مكان التفاحة
    apple.x = rand() % width;
    apple.y = rand() % height;

    Clock clock;
    float timer = 0, delay = 0.1f; // سرعة اللعبة

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        // 1. معالجة الأحداث (Events) مثل إغلاق النافذة
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

        // 2. قراءة المدخلات (لوحة المفاتيح)
        if (Keyboard::isKeyPressed(Keyboard::Left) && dir != 2)
            dir = 1;
        if (Keyboard::isKeyPressed(Keyboard::Right) && dir != 1)
            dir = 2;
        if (Keyboard::isKeyPressed(Keyboard::Up) && dir != 0)
            dir = 3;
        if (Keyboard::isKeyPressed(Keyboard::Down) && dir != 3)
            dir = 0;

        // 3. المنطق (Logic) - يتم تحديثه بناءً على المؤقت
        if (timer > delay)
        {
            timer = 0;

            // حركة الذيل (كل قطعة تأخذ مكان التي قبلها)
            for (int i = snake.size() - 1; i > 0; --i)
            {
                snake[i].x = snake[i - 1].x;
                snake[i].y = snake[i - 1].y;
            }

            // حركة الرأس
            if (dir == 0)
                snake[0].y += 1; // Down
            if (dir == 1)
                snake[0].x -= 1; // Left
            if (dir == 2)
                snake[0].x += 1; // Right
            if (dir == 3)
                snake[0].y -= 1; // Up

            // الاصطدام بالتفاحة
            if (snake[0].x == apple.x && snake[0].y == apple.y)
            {
                // زيادة حجم الثعبان
                snake.push_back({-1, -1}); // سيتم تحديث موقعها في الإطار القادم
                apple.x = rand() % width;
                apple.y = rand() % height;
            }

            // الاصطدام بالجدران (التفاف حول الشاشة)
            if (snake[0].x >= width)
                snake[0].x = 0;
            if (snake[0].x < 0)
                snake[0].x = width - 1;
            if (snake[0].y >= height)
                snake[0].y = 0;
            if (snake[0].y < 0)
                snake[0].y = height - 1;

            // الاصطدام بالذيل (خسارة)
            for (size_t i = 1; i < snake.size(); i++)
            {
                if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
                {
                    // إعادة اللعبة
                    snake.clear();
                    snake.push_back({10, 10});
                    snake.push_back({10, 11});
                    snake.push_back({10, 12});
                    dir = 0; // توقف أو اتجاه افتراضي
                }
            }
        }

        // 4. الرسم (Drawing)
        window.clear(); // مسح الشاشة القديمة

        // رسم الخلفية (اختياري)
        // window.draw(sBackground);

        // رسم التفاحة
        RectangleShape appleShape(Vector2f(blockSize, blockSize));
        appleShape.setFillColor(Color::Red);
        appleShape.setPosition(apple.x * blockSize, apple.y * blockSize);
        window.draw(appleShape);
        // إذا كنت تستخدم صور:
        // sApple.setPosition(apple.x * blockSize, apple.y * blockSize);
        // window.draw(sApple);

        // رسم الثعبان
        for (size_t i = 0; i < snake.size(); i++)
        {
            RectangleShape snakeShape(Vector2f(blockSize, blockSize));
            if (i == 0)
                snakeShape.setFillColor(Color::Green); // الرأس
            else
                snakeShape.setFillColor(Color(0, 155, 0)); // الذيل أغمق قليلاً

            snakeShape.setPosition(snake[i].x * blockSize, snake[i].y * blockSize);
            window.draw(snakeShape);

            // إذا كنت تستخدم صور:
            // sSnake.setPosition(snake[i].x * blockSize, snake[i].y * blockSize);
            // window.draw(sSnake);
        }

        window.display(); // عرض كل ما تم رسمه
    }

    return 0;
}
