#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

int Headx, Heady;
const int height = 20, width = 20;
bool Gameover;
int AppleX, AppleY;
int score;
enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
Direction dir;
int TailX[100];
int TailY[100];
int nTail;

// دالة لإخفاء المؤشر لمنع الوميض
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

// دالة لتحريك المؤشر بدلاً من مسح الشاشة
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// دالة لتغيير الألوان
void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Setup()
{
    Gameover = false;
    dir = STOP;
    srand(time(0));
    Headx = width / 2;
    Heady = height / 2;
    AppleX = rand() % width;
    AppleY = rand() % height;
    score = 0;
    ShowConsoleCursor(false);
}
//-------------------------------------------------
void Draw()
{
    gotoxy(0, 0); // استبدال system("cls") لمنع الوميض

    SetColor(11); // لون الإطار (سماوي)
    // السقف
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;

    // الخريطة
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                SetColor(11);
                cout << "#"; // الجدار الأيسر
            }

            if (j == Headx && i == Heady)
            {
                SetColor(10); // لون الرأس (أخضر فاتح)
                cout << "O";  // رأس الدودة
            }
            else if (j == AppleX && i == AppleY)
            {
                SetColor(12); // لون التفاحة (أحمر)
                cout << "@";  // التفاحة
            }
            else
            {
                // --- إضافة رسم الذيل هنا ---
                bool printTail = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (TailX[k] == j && TailY[k] == i)
                    {
                        SetColor(2); // لون الذيل (أخضر غامق)
                        cout << "o"; // رسم قطعة من الذيل
                        printTail = true;
                    }
                }
                // إذا لم نطبع ذيل أو رأس أو تفاحة، نطبع مسافة
                if (!printTail)
                    cout << " ";
                // ---------------------------
            }

            if (j == width - 1)
            {
                SetColor(11);
                cout << "#"; // الجدار الأيمن
            }
        }
        cout << endl;
    }

    // الأرضية
    SetColor(11);
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    SetColor(7); // استعادة اللون الأبيض
    cout << "Score : " << score << endl;
}

void Logic()
{
    // 1. حركة الذيل
    for (int i = nTail - 1; i > 0; i--)
    {
        TailX[i] = TailX[i - 1];
        TailY[i] = TailY[i - 1]; // تصحيح: تأخذ مكان القطعة التي تسبقها
    }

    TailX[0] = Headx;
    TailY[0] = Heady;

    // 2. حركة الرأس
    switch (dir)
    {
    case LEFT:
        Headx--;
        break;
    case RIGHT:
        Headx++;
        break;
    case UP:
        Heady--;
        break;
    case DOWN:
        Heady++;
        break;
    }

    // 3. الاصطدام بالجدران
    if (Headx >= width || Headx < 0 || Heady >= height || Heady < 0)
    {
        Gameover = true;
    }

    // 4. الاصطدام بالذيل
    for (int i = 0; i < nTail; i++)
    {
        // تصحيح: نقارن موقع الذيل بموقع الرأس
        if (TailX[i] == Headx && TailY[i] == Heady)
        {
            Gameover = true;
        }
    }

    // 5. أكل التفاحة
    if (Headx == AppleX && Heady == AppleY)
    {
        score += 10;
        nTail++; // حلك الصحيح
        AppleX = rand() % width;
        AppleY = rand() % height;
    }
}

void input()
{
    if (_kbhit())
    {

        char key = _getch();

        switch (key)
        {

        case 'a':
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case 'w':
            if (dir != DOWN)
                dir = UP;
            break;
        case 's':
            if (dir != UP)
                dir = DOWN;
            break;
        case 'd':
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 'x':
            Gameover = true;
        }
    }
}

int main()
{

    Setup();
    while (Gameover == false)
    {
        Draw();
        input();
        Logic();
        Sleep(100); // زيادة السرعة قليلاً لتناسب الرسم الجديد
    }

    return 0;
}
