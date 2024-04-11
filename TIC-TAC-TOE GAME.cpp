#include <iostream>
using namespace std;
char currentPlayer = 'X';
int c = 4;
char Check(char arr[4][4])
{

	/*
		    1 2 3        1 2 3
		  1 . . X      1 . . O
		  2 . X .      2 . O .
		  3 X . .      3 O . .
	*/

	int player_1_count = 0, player_2_count = 0;
	for (size_t i = 0; i < 4; i++)
	{
		if (arr[i][c - i] == currentPlayer)
		{
			player_1_count++;
		}
		else if (arr[i][c - i] == currentPlayer)
		{
			player_2_count++;
		}
		if (player_1_count == 3)
		{
			return 'X';
		}
		else if (player_2_count == 3)
		{
			return 'O';
		}
	}
	player_1_count = 0; player_2_count = 0;

	/*
		    1 2 3        1 2 3
		  1 X . .      1 O . .
		  2 . X .      2 . O .
		  3 . . X      3 . . O
	*/

	for (size_t i = 1; i < 4; i++)
	{

		if (arr[i][i] == currentPlayer)
		{
			player_1_count++;
		}
		else if (arr[i][i] == currentPlayer)
		{
			player_2_count++;
		}
		if (player_1_count == 3)
		{
			return 'X';
		}
		else if (player_2_count == 3)
		{
			return 'O';
		}
	}


	/*
		    1 2 3        1 2 3        1 2 3        1 2 3        1 2 3        1 2 3
		  1 X X X      1 . . .      1 . . .      1 O O O      1 . . .      1 . . .
		  2 . . .      2 X X X      2 . . .      2 . . .      2 O O O      2 . . .
		  3 . . .      3 . . .      3 X X X      3 . . .      3 . . .      3 O O O
	*/

	for (size_t i = 1; i < 4; i++)
	{
		int player_1_count = 0, player_2_count = 0;
		for (size_t j = 1; j < 4; j++)
		{
			if (arr[i][j] == currentPlayer)
			{
				player_1_count++;
			}
			else if (arr[i][j] == currentPlayer)
			{
				player_2_count++;
			}
		}
		if (player_1_count == 3)
		{
			return 'X';
		}
		else if (player_2_count == 3)
		{
			return 'O';
		}
	}

	/*
		    1 2 3        1 2 3        1 2 3        1 2 3        1 2 3        1 2 3
		  1 X . .      1 . X .      1 . . X      1 O . .      1 . O .      1 . . O
		  2 X . .      2 . X .      2 . . X      2 O . .      2 . O .      2 . . O
		  3 X . .      3 . X .      3 . . X      3 O . .      3 . O .      3 . . O
	*/

	for (size_t i = 1; i < 4; i++)
	{
		int player_1_count = 0, player_2_count = 0;
		for (size_t j = 1; j < 4; j++)
		{
			if (arr[j][i] == currentPlayer)
			{
				player_1_count++;
			}
			else if (arr[j][i] == currentPlayer)
			{
				player_2_count++;
			}
		}
		if (player_1_count == 3)
		{
			return 'X';
		}
		else if (player_2_count == 3)
		{
			return 'O';
		}
	}
}
bool checkDraw(char arr[4][4]) {
	for (size_t i = 1; i < 4; i++)
	{
		for (size_t j = 1; j < 4; j++)
		{
			if (arr[i][j] == '.')
				return false;
		}
	}
	return true;
}
char switchPlayer(char currentPlayer) {
	return (currentPlayer == 'X') ? 'O' : 'X';
}
void display(char arr[4][4])
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void process()
{
	char arr[4][4] = { {' ','1','2','3'},
			   {'1','.','.','.'},
			   {'2','.','.','.'},
			   {'3','.','.','.'} };
	cout << "Welcom to TIC-TAC-TOE GAME " << endl;
	int loops = 9;
	while (loops--)
	{
		system("cls");
		display(arr);
		cout << "Player ( " << currentPlayer << " ) Please Enter your Move position : " << endl;
		int row, column;
		cout << "Row number = "; cin >> row;
		cout << "Column number = "; cin >> column;
		if (row < 1 || row >= 4 || column < 1 || column >= 4 || arr[row][column] != '.') {
			loops++;
			cout << endl;
			cout << "******* Invalid move. Try again player ( " << currentPlayer << " ) *******" << endl;
			continue;
		}

		arr[row][column] = currentPlayer;
		if (Check(arr) == 'X')
		{
			cout << "-------------------------------" << endl;
			cout << "Player ( " << currentPlayer << " ) WIN " << endl;
			break;
		}
		if (checkDraw(arr)) {
			cout << "-------------------------------" << endl;
			cout << "It's a Draw" << endl;
			break;
		}
		currentPlayer = switchPlayer(currentPlayer);
	}
}
int main()
{
	process();
	int choice = 0;
	while (choice != 2)
	{
		cout << "Do you want play again ? " << endl;
		cout << "1- Yes		" << "2- No" << endl;
		cin >> choice;
		if (choice == 1)
		{
			process();
		}
		else if (choice == 2)
		{
			cout << "Game Finished" << endl;
			return 0;
		}
	}
}
