#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

int main()
{
    // تغيير عنوان النافذة

    // تغيير لون النص إلى الأخضر الفاتح (A) والخلفية سوداء (0)
    // هذا الأمر يستخدم أوامر نظام ويندوز
    system("color 0A");

    srand(time(0));

    // الأحرف التي ستظهر على الشاشة (ثنائي + حروف)
    char matrixChars[] = "01010101XYERGDWSGFSDGWESDGFSSDfGSGDEWZA";
    int len = sizeof(matrixChars) - 1;
    char x;
    // حلقة لا نهائية للعرض المستمر
    while (true)
    {
        // طباعة سطر مليء بالأحرف العشوائية
        for (int i = 0; i < 30; i++)
        {
            // احتمالية طباعة حرف أو مسافة فارغة لخلق تأثير الأعمدة
            if (rand() % 10 > 2)
            {
                cout << matrixChars[rand() % len] << " ";
            }
            else
            {
                cout << "  ";
            }
        }

        if (_kbhit())
        {
            x = _getch();
        }

        if (x == 'x')
        {
            break;
        }
        // التحكم بالسرعة (كلما قل الرقم زادت السرعة)
        Sleep(1);
    }

    return 0;
}