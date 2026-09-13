#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

struct flight
{
    int nam;
    string Destination;
    int Seatprice;
    int seatsavailable;
};

struct rese
{
    string name;
    int namber;
    int seat;
};

//--------------------------------------------

void typeText(const string &text, int delay_ms)
{
    for (char c : text)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
    cout << endl;
}
//--------------------------------------------
void Facility()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 11);

    string logo = R"(
========================================
     __        __     _               _ 
     \ \      / /_ _| | ___  ___  __| |
      \ \ /\ / / _` | |/ _ \/ _ \/ _` |
       \ V  V / (_| | |  __/  __/ (_| |
        \_/\_/ \__,_|_|\___|\___|\__,_|
                                       
                                        
                                                                    
      Waleed's Oasis Hotal
         Location: Damascus
 ========================================
    )";
    cout << logo << endl;
    SetConsoleTextAttribute(hConsole, 7);
}
void FlightsInfo(flight fli[5])
{

    fli[0].nam = 1;
    fli[0].Destination = "Damascus";
    fli[0].Seatprice = 1500;
    fli[0].seatsavailable = 15;

    fli[1].nam = 2;
    fli[1].Destination = "Aleppo";
    fli[1].Seatprice = 1800;
    fli[1].seatsavailable = 12;

    fli[2].nam = 3;
    fli[2].Destination = "Latakia";
    fli[2].Seatprice = 2000;
    fli[2].seatsavailable = 20;

    fli[3].nam = 4;
    fli[3].Destination = "Qamishli";
    fli[3].Seatprice = 3000;
    fli[3].seatsavailable = 8;

    fli[4].nam = 5;
    fli[4].Destination = "Daraa";
    fli[4].Seatprice = 1200;
    fli[4].seatsavailable = 18;
}

//--------------------------------------------
void printflight(flight fli[5])

{
    cout << left << setw(16) << " Flight Number"
         << "| " << setw(15) << "Destination"
         << "| " << setw(15) << "Seat Price"
         << "| " << setw(18) << "Seats Available" << "|\n";
    cout << string(71, '-') << "\n";
    for (int i = 0; i < 5; i++)
    {
        cout << " " << left << setw(15) << fli[i].nam
             << "| " << setw(15) << fli[i].Destination
             << "| " << setw(15) << fli[i].Seatprice
             << "| " << setw(18) << fli[i].seatsavailable << "|\n";
    }
}

//--------------------------------------------
void Bookflight(rese res[50], flight fli[5], int &resCount)
{

    bool find = false;

    cout << "\nAvailable flights:\n";
    printflight(fli);
    cout << "\n-----------------------------\n\n";

    cout << "Enter your name: ";

    cin >> ws;
    getline(cin, res[resCount].name);

    cout << "Enter the flight number: ";
    cin >> res[resCount].namber;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Incorrect entry. Please enter again: ";
        cin >> res[resCount].namber;
    }

    for (int i = 0; i < 5; i++)
    {

        if (res[resCount].namber == fli[i].nam)
        {
            find = true;
            cout << "Enter number of seats: ";
            cin >> res[resCount].seat;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Incorrect entry. Please enter again: ";
                cin >> res[resCount].seat;
            }
            if (res[resCount].seat == 0)
            {
                cout << "The required number of seats is not available.\n";
                break;
            }
            if (res[resCount].seat <= fli[i].seatsavailable)
            {
                fli[i].seatsavailable -= res[resCount].seat;
                resCount++;
                cout << "The flight has been booked.\n";
            }
            else
            {
                cout << "The required number of seats is not available.\n";
            }
            break;
        }
    }

    if (!find)
    {
        cout << "Flight number not found.\n";
    }
}

//--------------------------------------------
void viewres(rese res[50], int resCount)
{
    system("cls");
    Facility();

    if (resCount == 0)
    {
        cout << "No reservations yet.\n";
        return;
    }

    for (int i = 0; i < resCount; i++)
    {
        cout << "\nReservation " << i + 1 << ":\n";
        cout << "Name: " << res[i].name << endl;
        cout << "Flight number: " << res[i].namber << endl;
        cout << "Number of reserved seats: " << res[i].seat << endl;
        cout << "-----------------------------\n";
    }
}

//--------------------------------------------
int Calculat(flight fli[5], rese res[50], int resCount, int index = 0)
{
    if (index == resCount)
        return 0;

    int flightPrice = 0;
    for (int i = 0; i < 5; i++)
    {
        if (fli[i].nam == res[index].namber)
        {
            flightPrice = fli[i].Seatprice;
            break;
        }
    }

    return (res[index].seat * flightPrice) + Calculat(fli, res, resCount, index + 1);
}
int CalculateTotalSeats(rese res[50], int resCount, int index = 0)
{

    if (index == resCount)
        return 0;

    return res[index].seat + CalculateTotalSeats(res, resCount, index + 1);
}
//--------------------------------------------
int main()
{
    int resCount = 0;
    flight fli[5];
    rese res[50];
    int chose;
    FlightsInfo(fli);

    Facility();
    //--------------------------------------------وهي من جي بي تي بس الاكم سطر تحت هدول
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    cout << "=======================================" << endl;
    string message = "*** WELCOME TO WALEED'S OASIS *** \n";
    // استدعاء الدالة وطباعة الرسالة بتأخير 100 ملي ثانية بين كل حرف
    typeText(message, 100);

    //--------------------------------------------
    cout << "========================================" << endl;

    system("pause");
    system("cls");
    Facility();

    while (true)
    {
        cout << "1) View all flights\n";
        cout << "2) Book a flight\n";
        cout << "3) View all reservations\n";
        cout << "4) Calculating the total amount reserved and seats\n";
        cout << "5) Exit\n";
        cin >> chose;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Incorrect entry. Please enter again: ";
            cin >> chose;
        }
        if (chose == 1)
        {
            printflight(fli);
            system("pause");
            system("cls");
            Facility();
        }
        else if (chose == 2)
        {
            Bookflight(res, fli, resCount);
            system("pause");
            system("cls");
            Facility();
        }
        else if (chose == 3)
        {
            viewres(res, resCount);
            system("pause");
            system("cls");
            Facility();
        }
        else if (chose == 4)
        {
            int total = Calculat(fli, res, resCount);
            int steat = CalculateTotalSeats(res, resCount);
            cout << "The total amount reserved: " << total << " NSYP" << endl;
            cout << "The total seats " << steat << endl;
            system("pause");
            system("cls");
            Facility();
        }
        else if (chose == 5)
            break;
        else
            cout << "Invalid choice! Please select again.\n";
    }
    SetConsoleTextAttribute(hConsole, 11);

    string exitMessage = "\nThank you for choosing Waleed's Oasis!\n"
                         "We hope you have a safe and pleasant journey. Goodbye!\n\n";
    cout << exitMessage;

    return 0;
}