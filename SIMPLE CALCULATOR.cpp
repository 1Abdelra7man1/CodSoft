#include <iostream>
using namespace std;
void options()
{
	cout << "Options : " << endl;
	cout << "1 : +" << endl;
	cout << "2 : -" << endl;
	cout << "3 : *" << endl;
	cout << "4 : /" << endl;
}
int main()
{
	int firstNumber, SecondNumber;
	cout << "Welcom to to the simple calculator program" << endl;
	cout << "Please Enter Two Numbers" << endl;
	cin >> firstNumber >> SecondNumber;
	options();
	cout << "Choose the Arithmetic Operation Number you want" << endl;
	int arithmetic_operations_number; cin >> arithmetic_operations_number;
	if (arithmetic_operations_number == 1)
	{
		cout << "The sum of the two numbers = " << firstNumber + SecondNumber << endl;
	}
	else if (arithmetic_operations_number == 2)
	{
		cout << "subtracting the two numbers = " << firstNumber - SecondNumber << endl;
	}
	else if (arithmetic_operations_number == 3)
	{
		cout << " multiplication the two numbers = " << firstNumber * SecondNumber << endl;
	}
	else if (arithmetic_operations_number == 4)
	{
		cout << "Division the two numbers = " << firstNumber / SecondNumber << endl;
	}
}
