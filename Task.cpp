#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	cout << "Welcome to the NUMBER GUESSING GAME" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Guess a number between 1 to 100 : " << endl;
	srand(time(0));
	int number = rand() % 100 + 1;
	int guess = 0;
	while (guess != number)
	{
		cin >> guess;
		if (number == guess)
		{
			cout << endl;
			cout << "You Won!" << endl;
		}
		else if (guess - number >= 30)
		{
			cout << "Guess is too High " << endl;
		}
		else if (number - guess >= 30)
		{
			cout << "Guess is too Low " << endl;
		}
		else if (number > guess)
		{
			cout << "Guess a bigger number " << endl;
		}
		else if (guess > number )
		{
			cout << "Guess a lower number " << endl;
		}
	}
}
