#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void comparison(int Playerchose, int Computerchose, int &Playerscore, int &Computerscore)
{
    if (Playerchose == Computerchose)
    {
        cout << "Draw" << endl;
    }
    else if (Playerchose == 1 && Computerchose == 2)
    {
        cout << "Win" << endl;
        Playerscore++;
    }
    else if (Playerchose == 2 && Computerchose == 1)
    {
        cout << "Loss" << endl;
        Computerscore++;
    }
    else if (Playerchose == 1 && Computerchose == 3)
    {
        cout << "Loss" << endl;
        Computerscore++;
    }
    else if (Playerchose == 3 && Computerchose == 1)
    {
        cout << "Win" << endl;
        Playerscore++;
    }
    else if (Playerchose == 3 && Computerchose == 2)
    {
        cout << "Loss" << endl;
        Computerscore++;
    }
    else if (Playerchose == 2 && Computerchose == 3)
    {
        cout << "Win" << endl;
        Playerscore++;
    }
}

string chose(int x)
{
    switch (x)
    {
    case 1:
        return "Paper";
    case 2:
        return "Rock";
    case 3:
        return "Scissors";
    default:
        return "Unknown";
    }
}

int main()
{
    int Playerchose;
    int Computerchose;
    int Playerscore = 0;
    int Computerscore = 0;
    int result;
    bool game = true;

    srand(time(0));

    while (game)
    {
        result = rand() % 3 + 1;
        Computerchose = result;

        cout << "=================================" << endl;
        cout << "|    Rock Paper Scissors Game   |" << endl;
        cout << "=================================" << endl;
        cout << "| [1] Paper                     |" << endl;
        cout << "| [2] Rock                      |" << endl;
        cout << "| [3] Scissors                  |" << endl;
        cout << "| [4] Exit                      |" << endl;
        cout << "=================================" << endl;
        cout << "Enter Your Choice: ";

        cin >> Playerchose;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Enter again: " << endl;
            cin >> Playerchose;
        }

        cout << endl;

        while (Playerchose < 1 || Playerchose > 4)
        {
            cout << "Invalid choice. Enter again: ";
            cin >> Playerchose;
        }

        if (Playerchose == 4)
        {
            game = false;
            break;
        }

        comparison(Playerchose, result, Playerscore, Computerscore);

        cout << "\n---------------------------------" << endl;
        cout << " Computer Choice : " << chose(result) << endl;
        cout << " Your Choice     : " << chose(Playerchose) << endl;
        cout << "---------------------------------" << endl;
        cout << " Your Score      : " << Playerscore << endl;
        cout << " Computer Score  : " << Computerscore << endl;
        cout << "---------------------------------" << endl;

        system("pause");
        system("cls");
    }

    return 0;
}