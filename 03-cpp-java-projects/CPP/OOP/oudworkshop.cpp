#include <iostream>
#include <windows.h>
using namespace std;

class OudWorkShop
{
private:
    float Money;
    int wood;
    int strings;
    int oudsinStock;

public:
    OudWorkShop()
    {
        Money = 500;
        wood = 3;
        strings = 3;
        oudsinStock = 1;
    }
    float getMoney()
    {
        return Money;
    }
    int getWood()
    {
        return wood;
    }
    int getStrings()
    {
        return strings;
    }
    int getOudsinStock()
    {
        return oudsinStock;
    }
    void buildOud()
    {
        if (wood > 0 && strings > 0)
        {
            cout << "Build Oud Successfully" << endl;
            wood -= 1;
            strings -= 1;
            oudsinStock += 1;
        }
        else
        {
            cout << "Go to shop, You dont have enough materials" << endl;
        }
    }
    void sellOud()
    {
        if (oudsinStock > 0)
        {
            cout << "You Sall one oud " << endl;
            oudsinStock -= 1;
            Money += 5000;
        }
        else
        {
            cout << "You dont have any oud" << endl;
        }
    }
    void bayMaterials(int x, int y)
    {
        int amontwood = x * 10;
        int amontstrings = y * 5;
        int amontboth = amontwood + amontstrings;
        if (Money > 0)
        {
            if (amontboth > Money)
            {
                cout << "You dont have enough money" << endl;
            }
            else
            {

                Money -= amontboth;

                wood += x;
                strings += y;
            }
        }
    }
};
void Centrol(int &chose, OudWorkShop &Waleed)
{

    int wood, strings;
    switch (chose)
    {
    case 1:
        Waleed.buildOud();
        break;
    case 2:
        Waleed.sellOud();
        break;
    case 3:
        cout << "How Match You want to bay wood ? one wood = 10 NSYP" << endl;
        cin >> wood;
        cout << "How Match You Want to bay strings ? one string = 5 NSYP" << endl;
        cin >> strings;

        Waleed.bayMaterials(wood, strings);
        break;

    default:

        break;
    }
}
void Menu(OudWorkShop &Waleed)
{
    int chose;
    int x;
    while (true)
    {
        system("cls");
        cout << "You Have " << Waleed.getMoney() << " NSYP" << endl;
        cout << "You Have " << Waleed.getWood() << " Wood" << endl;
        cout << "You Have " << Waleed.getStrings() << " Strings" << endl;
        cout << "You Have " << Waleed.getOudsinStock() << " Oud" << endl
             << endl;
        cout << "(1) Build Oud" << endl;
        cout << "(2) Sell Oud" << endl;
        cout << "(3) Bay Materials" << endl;
        cin >> chose;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Wrong Enter. Please Enter Again : ";
            cin >> chose;
        }
        Centrol(chose, Waleed);
        system("pause");
    }
}

int main()
{
    OudWorkShop Waleed;
    Menu(Waleed);
    return 0;
}
