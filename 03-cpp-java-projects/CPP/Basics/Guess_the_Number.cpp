#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	char rab = 'y';
	srand(time(0));
	int secret = rand() % 100 + 1;
	int x;
	cout << "Guess a number between 1~100" << endl;
	int tries = 0;
	do
	{

		cin >> x;
		tries++;
		if (secret < x)
			cout << "too high" << endl
				 << "Enter agein ." << endl;

		else if (secret > x)
			cout << "too low" << endl
				 << "Enter agein." << endl;
		else if (secret == x)
		{
			cout << "Correct! You won in " << tries << " tries" << endl;

			break;
		}

	} while (x != secret);
	if (tries >= 1 && tries <= 3)
		cout << "you are Genius" << endl;
	else if (tries >= 3 && tries <= 7)
		cout << "you are Good" << endl;
	else
		cout << "you won by lucky" << endl;

	return 0;
}
