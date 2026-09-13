#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int Hour = 00;
    int Sec = 00;
    int Min = 00;
    char Timer = 'y';
    while (Timer == 'Y' || Timer == 'y')
    {
        cout << "Enter Hour : ";
        cin >> Hour;
        cout << endl;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Wrong Enter . Please Enter Again : ";
            cin >> Hour;

            cout << endl;
        }

        cout << "Enter min : ";
        cin >> Min;

        cout << endl;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Woring Entring . Enter Min Again";
            cin >> Min;
            cout << endl;
        }

        cout << "Enter Sec : ";
        cin >> Sec;
        cout << endl;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Wrong Enter . Please Enter Again : ";
            cin >> Sec;
            cout << endl;
        }

        while (true)
        {
            system("cls");
            if (Hour == 0 && Min == 0 && Sec == 0)
            {
                Beep(2000, 440);
                break;
            }
            cout << Hour << ":" << Min << ":" << Sec << endl;

            if (Sec == 0 && Min > 00)
            {
                Min--;
                Sec = 59;
            }
            else if (Min == 0 && Sec == 0 && Hour > 0)
            {
                Hour--;
                Min = 59;
                Sec = 59;
            }
            else if (Sec > 0)
                Sec--;
            Sleep(1000);
        }
        cout << "Taimer is end\n if uoy want to use taimer agine enter Y if you dont enter N" << endl;
        cin >> Timer;
        while (Timer != 'y' && Timer != 'Y' && Timer != 'N' && Timer != 'n')
        {
            cout << "filed enter . please enter again .";
            cin >> Timer;
        }
        if (Timer == 'N' || Timer == 'n')
        {
            break;
        }
    }
    return 0;
}