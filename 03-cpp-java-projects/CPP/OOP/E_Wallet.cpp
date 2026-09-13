#include <iostream>
#include <windows.h>
using namespace std;

class Wallet
{
private:
    float balance;
    string Username = "Waleed";
    string password = "1234";
    int PIN = 1234;

public:
    Wallet() : balance(0)
    {
    }
    Wallet(float x)
    {
        balance = x;
    }
    bool accont(string User, string pass, int P)
    {

        if (Username == User && password == pass && PIN == P)
        {

            return true;
        }
        else
        {

            return false;
        }
    }
    float deposit(float amount)
    {
        return balance += amount;
    }
    float withdraw(float amount)
    {
        if (amount > balance)
        {
            cout << "Your Balance < Amount " << endl;
            cout << "Your Balance : " << balance << endl;

            system("pause");
            return balance;
        }
        else
            return balance -= amount;
    }
    float getBalance()
    {
        return balance;
    }
};
void InputUser(string &User, string &pass, int &PIN)
{

    cout << "Please Enter Your UserName ";
    getline(cin, User);

    cout << "Please Enter Your Password ";
    getline(cin, pass);
    cout << "Please Enter Your PIN ";
    cin >> PIN;
    cin.ignore(1000, '\n'); // Clear buffer logic correction
}

void Menu(Wallet &Waleed) // Passed by reference
{
    int chose;
    int amount;

    while (true)
    {
        system("cls");
        cout << "(1) Deposit " << endl;
        cout << "(2) Withdraw " << endl;
        cout << "(3) Check Balance " << endl;
        cout << "(4) Exit " << endl;

        cout << "Enter Your Choice : ";
        cin >> chose;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Wrong Enter. Please Enter Again : ";
            cin >> chose;
        }

        switch (chose)
        {
        case 1:
            cout << "Enter Amount : ";
            cin >> amount;
            while (amount <= 0 || cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                if (amount <= 0)
                {
                    cout << "Please Enter a Namber greater than 0" << endl;
                    cin >> amount;
                }
                else
                {
                    cout << "Wrong Enter. Please Enter Again : ";
                    cin >> amount;
                }
            }
            Waleed.deposit(amount);
            break;
        case 2:
            cout << "Enter Amount : ";
            cin >> amount;
            while (amount <= 0 || cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                if (amount <= 0)
                {
                    cout << "Please Enter a Namber greater than 0" << endl;
                    cin >> amount;
                }
            }
            Waleed.withdraw(amount);
            break;
        case 3:
            cout << "Your Balance : " << Waleed.getBalance() << endl;
            system("pause");
            break;
        case 4:
            return;
            break;
        }
    }
}
void Chacklogin(Wallet &Waleed, string UserName, string Pass, int PIN) // Passed by reference
{
    while (!Waleed.accont(UserName, Pass, PIN))
    {
        cout << "Access Denied: Wrong Credentials!" << endl;

        InputUser(UserName, Pass, PIN);
        if (Waleed.accont(UserName, Pass, PIN))
        {
            break;
        }
    }

    if (Waleed.accont(UserName, Pass, PIN))
    {
        Menu(Waleed);
    }
}
int main()
{

    Wallet Waleed(0.0);

    string UserName;
    string Pass;
    int PIN;
    InputUser(UserName, Pass, PIN);
    Chacklogin(Waleed, UserName, Pass, PIN);
    return 0;
}