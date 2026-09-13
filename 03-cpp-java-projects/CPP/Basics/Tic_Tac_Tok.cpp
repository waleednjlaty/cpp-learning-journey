#include <iostream>
#include <windows.h>
using namespace std;
char bord[3][3] = {{'1', '2', '3'},
				   {'4', '5', '6'},
				   {'7', '8', '9'}};
char bord1[3][3] = {{'1', '2', '3'},
					{'4', '5', '6'},
					{'7', '8', '9'}};

//-------------------------------------------------------------------------

void drowbord()
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			cout << " | " << bord[i][j] << " | ";
		}
		cout << endl;
	}
}

//-------------------------------------------------------------------------

void inputPlayer(int x, char symbol)
{
	int r = (x - 1) / 3;
	int c = (x - 1) % 3;
	bord[r][c] = symbol;
}

//-------------------------------------------------------------------------

void chackchose(int &x)
{
	int r = (x - 1) / 3; // حساب الصف
	int c = (x - 1) % 3; // حساب العمود
	while (x < 1 || x > 9 || bord[r][c] == 'x' || bord[r][c] == 'o')
	{
		if (x < 1 || x > 9)
		{
			cout << "Wronig Enter. Please Enter Again : ";
			cin >> x;
		}
		else if (bord[r][c] == 'x' || bord[r][c] == 'o')
		{
			cout << "This Place is booked. Please Chose Another Place : ";
			cin >> x;
		}

		r = (x - 1) / 3;
		c = (x - 1) % 3;
	}
}

//-------------------------------------------------------------------------

bool checkFull()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (bord[i][j] != 'x' && bord[i][j] != 'o')
			{
				return false;
			}
		}
	}
	return true;
}

//-------------------------------------------------------------------------

char checkWinner()
{
	for (int i = 0; i < 3; i++)
	{
		if (bord[i][0] == bord[i][1] && bord[i][1] == bord[i][2])
			return bord[i][0]; // فحص الصفوف
		if (bord[0][i] == bord[1][i] && bord[1][i] == bord[2][i])
			return bord[0][i]; // فحص الأعمدة
	}
	if (bord[0][0] == bord[1][1] && bord[1][1] == bord[2][2])
		return bord[0][0]; // القطر الأول
	if (bord[0][2] == bord[1][1] && bord[1][1] == bord[2][0])
		return bord[0][2]; // القطر الثاني
	return ' ';
}

//-------------------------------------------------------------------------

void resetBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			bord[i][j] = bord1[i][j];
	}
}

//-------------------------------------------------------------------------
int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int chose1;
	int chose2;
	int player1 = 0;
	int player2 = 0;
	char Start = 'Y';
	while (Start == 'Y' || Start == 'y')
	{

		drowbord();

		SetConsoleTextAttribute(hConsole, 12);
		cout << "Player 1 Score : " << player1 << endl;
		cout << "Player 2 Score : " << player2 << endl;
		SetConsoleTextAttribute(hConsole, 1);
		cout << "Player1 (X) :\nEnter Your Chose 1~9 : ";
		SetConsoleTextAttribute(hConsole, 7);
		cin >> chose1;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Wronig Enter. Please Enter Again : ";
			cin >> chose1;
		}

		chackchose(chose1);
		inputPlayer(chose1, 'x'); // تفعيل دالة الإدخال بعد التحقق
		system("cls");

		drowbord();
		cout << "Player 1 Score : " << player1 << endl;
		cout << "Player 2 Score : " << player2 << endl;

		if (checkWinner() == 'x')
		{
			cout << "Player 1 is WiN " << endl;
			player1++;
			cout << "Do you want to play again? Y/N." << endl;
			cin >> Start;
			while (Start != 'y' && Start != 'Y' && Start != 'n' && Start != 'N')
			{
				cin.ignore();
				cout << "Wronig Enter. Please Enter Again : ";
				cin >> Start;
			}
			if (Start == 'y' || Start == 'Y')
			{
				resetBoard();
				continue;
			}
			else
				break;
		}
		if (checkFull())
		{
			cout << "Draw!!!!!" << endl;
			cout << "Do you want to play again? Y/N." << endl;
			cin >> Start;
			while (Start != 'y' && Start != 'Y' && Start != 'n' && Start != 'N')
			{
				cin.ignore();
				cout << "Wronig Enter. Please Enter Again : ";
				cin >> Start;
			}
			if (Start == 'y' || Start == 'Y')
			{
				resetBoard();
				continue;
			}
			else
				break;
		}

		SetConsoleTextAttribute(hConsole, 2);
		cout << "Player2 (O):\nEnter Your Chose 1~9 : ";
		SetConsoleTextAttribute(hConsole, 7);
		cin >> chose2;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Wronig Enter. Please Enter Again : ";
			cin >> chose2;
		}

		chackchose(chose2);

		inputPlayer(chose2, 'o');
		system("cls");
		drowbord();
		if (checkWinner() == 'o')
		{
			cout << "Player 2 is WiN " << endl;
			player2++;
			cout << "Do you want to play again? Y/N." << endl;
			cin >> Start;
			while (Start != 'y' && Start != 'Y' && Start != 'n' && Start != 'N')
			{
				cin.ignore();
				cout << "Wronig Enter. Please Enter Again : ";
				cin >> Start;
			}
			if (Start == 'y' || Start == 'Y')
			{
				resetBoard();
				continue;
			}
			else
				break;
		}
		if (checkFull())
		{
			cout << "Draw!!!!!" << endl;
			cout << "Do you want to play again? Y/N." << endl;
			cin >> Start;
			while (Start != 'y' && Start != 'Y' && Start != 'n' && Start != 'N')
			{
				cin.ignore();
				cout << "Wronig Enter. Please Enter Again : ";
				cin >> Start;
			}
			if (Start == 'y' || Start == 'Y')
			{
				resetBoard();
				continue;
			}
			else
				break;
		}
	}
	return 0;
}
