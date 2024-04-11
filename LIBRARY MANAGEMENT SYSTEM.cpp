#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct book
{
	string title;
	string author;
	int isbn;
	bool available = true;
};
vector <book> lib;
struct borrowers
{
	string name;
	string book_title;
	string book_author;
	int fine = 0;
	bool Return = false;
};
vector <borrowers> borr;
void options()
{
	cout << " _______________________" << "\t" << " ________________________" << "\t" << " ________________________" << endl;
	cout << "| 1- Store Book         |" << "\t" << "| 2- View Books          |" << "\t" << "| 3- Add Borrowers       |" << endl;
	cout << "\"-----------------------\"" << "\t" << "\"------------------------\"" << "\t" << "\"------------------------\"" << endl;

	cout << " _______________________" << "\t" << " ________________________" << "\t" << " ________________________" << endl;
	cout << "| 4- View Borrowers     |" << "\t" << "| 5 - Add fine           |" << "\t" << "| 6 - Find a Book        | " << endl;
	cout << "\"-----------------------\"" <<"\t" << "\"------------------------\"" << "\t" << "\"------------------------\"" << endl;

	cout <<"\t\t" << " _______________________" << "\t" << " ________________________" << endl;
	cout << "\t\t"<<"|    7- Book Returns    |" << "\t" << "|        8- Exit         |" << endl;
	cout << "\t\t"<<"\"-----------------------\"" << "\t" << "\"------------------------\"" << endl;
}
void store()
{
	string title, author;
	cout << "Enter book information :" << endl;
	cout << "Title : ";
	cin >> title;
	cout << "Author : ";
	cin >> author;
	cout << "ISBN : ";
	int isbn; cin >> isbn;
	lib.push_back({ title,author,isbn,true });
	while (true)
	{
		cout << "do you want store more Books ? ( y / n )" << endl;
		string answer; cin >> answer;
		if (answer == "y" || answer == "Y")
		{
			cout << "Enter book information :" << endl;
			cout << "Name : ";
			cin >> title;
			cout << "Author : ";
			cin >> author;
			cout << "ISBN : ";
			int isbn; cin >> isbn;
			lib.push_back({ title,author,isbn,true });
		}
		else if (answer == "n" || answer == "N")
		{
			return;
		}
	}
}
void view_books()
{
	cout << "----------------" << endl;
	for (size_t i = 0; i < lib.size(); i++)
	{
		cout << "Book " << i + 1 << endl;
		cout << "Title : " << lib[i].title << endl;
		cout << "Author: " << lib[i].author << endl;
		cout << "ISBN  : " << lib[i].isbn << endl;
		cout << "Availability  : ";
		if (lib[i].available == true)
		{
			cout << "Available" << endl;
		}
		else
		{
			cout << "Not Available" << endl;
		}
		cout << "----------------" << endl;
	}
}
void search()
{
	string title; cin >> title;
	int pos = -1;
	for (size_t i = 0; i < lib.size(); i++)
	{
		int found = lib[i].title.find(title);
		if (found == 0)
		{
			pos = i;
			break;
		}
	}
	if (pos == -1)
	{
		cout << "Book not found" << endl;
		return;
	}
	cout << "----------------" << endl;
	cout << "Book " << pos + 1 << endl;
	cout << "Title : " << lib[pos].title << endl;
	cout << "Author: " << lib[pos].author << endl;
	cout << "ISBN  : " << lib[pos].isbn << endl;
	cout << "----------------" << endl;
}
void availability(string title)
{
	for (size_t i = 0; i < lib.size(); i++)
	{
		int found = lib[i].title.find(title);
		if (found == 0)
		{
			lib[i].available == false;
			break;
		}
	}
}
void add_borrowers()
{
	cout << "Enter Borrower's Information" << endl;
	string name, book_title, book_author;
	cout << "Name: "; cin >> name;
	cout << "Book Title: "; cin >> book_title;
	availability(book_title);
	cout << "Book Author: "; cin >> book_author;
	borr.push_back({ name,book_title,book_author,0,false });
	while (true)
	{
		cout << "do you want add more borrowers ? (y / n)" << endl;
		string answer; cin >> answer;
		if (answer == "y" || answer == "Y")
		{
			cout << "Enter Borrower's Information" << endl;
			string name, book_title, book_author;
			int fine;
			cout << "Name: "; cin >> name;
			cout << "Book Title: "; cin >> book_title;
			availability(book_title);
			cout << "Book Author: "; cin >> book_author;
			cout << "Fine: "; cin >> fine;
			borr.push_back({ name,book_title,book_author,fine,false });
		}
		else if (answer == "n" || answer == "N")
		{
			return;
		}
	}
}
void view_borrowers()
{
	cout << "--------------------------" << endl;
	for (size_t i = 0; i < borr.size(); i++)
	{
		cout << "Borrower " << i + 1 << endl;
		cout << "Borrower's Name: " << borr[i].name << endl;
		cout << "Book Title     : " << borr[i].book_title << endl;
		cout << "Book Author    : " << borr[i].book_author << endl;
		cout << "Borrower's Fine: " << borr[i].fine << endl;
		if (borr[i].Return == false)
		{
			cout << "__________________________" << endl;
			cout << "The book was not returned" << endl;
		}
		else
		{
			cout << "__________________________" << endl;
			cout << "The book has been returned" << endl;
		}
		cout << "--------------------------" << endl;
	}
}
void add_fine()
{
	cout << "Enter name the borrower" << endl;
	string name;
	cout << "Name : "; cin >> name;
	int pos = -1;
	int fine;
	for (size_t i = 0; i < borr.size(); i++)
	{
		int found = borr[i].name.find(name);
		if (found == 0)
		{
			pos = i;
			cout << "Enter Fine : "; cin >> fine;
			borr[pos].fine = fine;
			break;
		}
	}
	if (pos == -1)
	{
		cout << "Borrower not found" << endl;
		return;
	}
}
void Return_book()
{
	cout << "Enter name the borrower" << endl;
	string name;
	cout << "Name : "; cin >> name;
	int pos = -1;
	for (size_t i = 0; i < borr.size(); i++)
	{
		int found = borr[i].name.find(name);
		if (found == 0)
		{
			pos = i;
			borr[pos].Return = true;
			cout << "The changes were saved successfully" << endl;
			break;
		}
	}
	if (pos == -1)
	{
		cout << "Borrower not found" << endl;
		return;
	}
}
int main()
{
	cout << "Welcome to the LIBRARY MANAGEMENT SYSTEM" << endl;
	int choice = 0;
	while (choice != 8)
	{
		options();
		cout << "Enter your Choice" << endl;
		cin >> choice;
		if (choice == 1)
		{
			store();
		}
		else if (choice == 2)
		{
			view_books();
		}
		else if (choice == 3)
		{
			add_borrowers();
		}
		else if (choice == 4)
		{
			view_borrowers();
		}
		else if (choice == 5)
		{
			add_fine();
		}
		else if (choice == 6)
		{
			cout << "Enter Book title that you want to search" << endl;
			search();
		}
		else if (choice == 7)
		{
			Return_book();
		}
	}
}
