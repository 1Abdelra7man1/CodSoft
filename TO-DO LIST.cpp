#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct tasks 
{
	string task;
	bool check = false;
};
vector <tasks> to_do;
void options()
{
	cout << "1- Add Tasks" << endl;
	cout << "2- View Tasks" << endl;
	cout << "3- Remove Tasks" << endl;
	cout << "4- Mark Task as Completed" << endl;
	cout << "5- End the program" << endl;
}
void display()
{
	cout << "----------------------------" << endl;
	for (size_t i = 1; i <= to_do.size(); i++)
	{
		cout << i << "- ";
		cout << (to_do[i - 1].check == true ? "[X] " : "[ ] ");
		cout << to_do[i - 1].task << endl;
	}
	cout << "----------------------------" << endl;
}
void add()
{
	string task;
	cout << "Enter your task :" << endl;
	cin >> task;
	to_do.push_back({ task, false });
	while (true)
	{
		cout << "do you want add another task ? ( y / n )" << endl;
		string answer; cin >> answer;
		if (answer == "y" || answer == "Y")
		{
			cout << "Enter your task :" << endl;
			cin >> task;
			to_do.push_back({ task, false });
		}
		else if (answer == "n" || answer == "N")
		{
			return;
		}
	}
}
void remove()
{
	cout << "Enter task number you want to remove" << endl;
	int task_num; cin >> task_num;
	to_do.erase(to_do.begin() + task_num - 1);
}
void mark()
{
	cout << "Enter task number you want to mark as comblete" << endl;
	int task_num; cin >> task_num;
	to_do[task_num-1].check = true;
	cout << "Task marked as completed." << endl;
}
int main()
{
	int choic = 0;
	while (choic != 5)
	{
		options();
		cin >> choic;
		if (choic == 1)
		{
			add();
		}
		else if (choic == 2)
		{
			display();
		}
		else if (choic == 3)
		{
			remove();
		}
		else if (choic == 4)
		{
			mark();
		}
		else if (choic == 5)
		{
			cout << "program finished" << endl;
			return 0;
		}
	}
}
