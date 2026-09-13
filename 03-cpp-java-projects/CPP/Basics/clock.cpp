#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;
void AutoClock()
{
    while (true)
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        system("cls");
        cout << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
        Sleep(1000);
    }
}
void ManualClock()
{
    int Hour = 00;
    int Sec = 00;
    int Min = 00;
    cout << "Enter Hour : ";
    cin >> Hour;
    cout << endl
         << "Enter Min : " << endl;
    cin >> Min;
    cout << endl
         << "Enter Sec : ";
    cin >> Sec;
    while (true)
    {
        system("cls");

        Sec++;
        if (Sec == 59)
        {
            Min++;
            Sec = 0;
        }
        else if (Min == 59)
        {
            Hour++;
            Min = 0;
        }
        else if (Hour == 24)
        {
            Hour = 0;
            Min = 0;
            Sec = 0;
        }
        cout << Hour << ":" << Min << ":" << Sec << endl;

        Sleep(1000);
    }
}
int main()
{

    int chose;

    cout << "Choose 1 for Auto Clock\nChoose 2 for Manual Clock\n";
    cin >> chose;
    while (cin.fail() || (chose != 1 && chose != 2))
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cout << "Wrong input. Please enter 1 or 2:" << endl;
        cin >> chose;
    }
    if (chose == 1)
    {
        AutoClock();
    }
    else if (chose == 2)
    {
        ManualClock();
    }
    return 0;
}