#include <iostream>
#include <cmath>

using namespace std;

float math(float a, char op, float b)
{
	switch (op)
	{
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		if (b == 0)
		{
			cout << "Error: Division by zero!" << endl;
			return 0;
		}
		return a / b;
		break;
	default:
		return 0;
	}
}
float mathpro(string h, float n = 0, float k = 0)
{
	if (h == "max")
	{
		return max(n, k);
	}
	else if (h == "power")
	{
		return pow(n, k);
	}
	else if (h == "min")
	{
		return min(n, k);
	}
	else if (h == "sqrt")
	{
		if (n < 0)
		{
			cout << "Error : you are Entering a negative Namber !" << endl;
			return 0;
		}
		return sqrt(n);
	}
	else if (h == "sin")
	{
		return sin(n);
	}
	else if (h == "cos")
	{
		return cos(n);
	}
	else if (h == "tan")
	{
		return tan(n);
	}
	else if (h == "log")
	{
		if (n <= 0)
		{
			cout << "Error: log of non-positive number" << endl;
			return 0;
		}
		return log(n);
	}
	return 0;
}

int fact(int n)
{
	if (n < 0)
		return 0; // Error case
	if (n == 0 || n == 1)
		return 1;
	else
		return n * fact(n - 1);
}

int main()
{
	float a;
	char ob;
	float b;
	int chose;
	int nam1;
	char x = 'y';
	cout << "1) Regular calculator " << endl;
	cout << "2) Professional calculator " << endl;
	cout << "Enter your Chose" << endl;
	cin >> chose;
	if (chose == 1)
	{
		while (x == 'y' || x == 'Y')
		{
			cout << "Enter your calculation : ";
			cin >> a >> ob >> b;
			cout << "your calculation : " << math(a, ob, b) << endl;
			cout << "Do you want to perform another calculation? (y/n): ";
			cin >> x;
		}
	}
	else if (chose == 2)
	{
		string mathematical;
		cout << "Enter your mathematical equation :" << endl;
		while (x == 'y' || x == 'Y')
		{
			cout << "\nChoose: max, min, log, sqrt, sin, cos, tan, power, fact" << endl;
			cin >> mathematical;
			if (mathematical == "fact")
			{
				cout << "Enter one Nambers : " << endl;
				cin >> nam1;
				cout << "fact is : " << fact(nam1) << endl;
			}
			else if (mathematical == "max" || mathematical == "min" || mathematical == "power")
			{
				cout << "Enter two Nambers : " << endl;
				cin >> a >> b;
				cout << "Answer is : " << mathpro(mathematical, a, b) << endl;
			}
			else if (mathematical == "sqrt" || mathematical == "log" || mathematical == "sin" || mathematical == "cos" || mathematical == "tan")
			{
				cout << "Enter one Nambers : " << endl;
				cin >> a;
				cout << "Answer is : " << mathpro(mathematical, a) << endl;
			}
			else
			{
				cout << "Unknown operation!" << endl;
			}
			cout << "Do you want to perform another calculation? (y/n): ";
			cin >> x;
		}
	}
	return 0;
}
