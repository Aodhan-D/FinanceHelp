#include "MainMenu.h"
#include "Income.h"
#include "Bill.h"
#include<iostream>
#include <string>

using namespace std;

int main()
{
	MainMenu m;
	int temp = m.menu();
	if (temp != 1)
	{
		while (1)
		{
			int choice;
			cout << "\n============================\n"
				<< "	Main Menu "
				<< "\n============================" << endl;

			cout << "Would you like to add/view Income(s)[0] or add/view a Bill(s)[1] or view your Financial Status[2]? Enter any other number to exit."<<endl;
			cin >> choice;
			while (!cin.good())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Please enter a valid number: ";
				cin >> choice;
			}
			if (choice == 0)
			{
				int c;
				//Add an Income
				Income i;
				cout << "Would you like to Add an Income[0], View all incomes[1] or delete all Entries[2]?" << endl;
				cin >> c;
				while (!cin.good())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "Please enter a valid number: ";
					cin >> c;
				}
				//if statment to see if the user wants to add an income or view all
				if (c == 0)
				{
					i.AddIncome();
				}
				else if (c == 1)
				{
					i.viewAllIncomes();
				}
				else if (c == 2)
				{
					char ans;
					cout << "Are you sure you wish to clear all entries[y/n]?\n";
					cin >> ans;
					if (ans == 'y')
					{
						i.clearAll();
						cout << "The file was succsessfully cleared";
					}
					else
					{
						cout << "The file was not cleared you will be returned to the main menu.\n" << endl;
					}

				}

			}
			else if (choice == 1)
			{
				int c;
				//Add an Income
				Bill b;
				cout << "Would you like to Add a Bill[0], View all Bills[1] or delete all Entries[2]?" << endl;
				cin >> c;
				while (!cin.good())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "Please enter a valid number: ";
					cin >> c;
				}
				//if statment to see if the user wants to add an income or view all
				if (c == 0)
				{
					b.AddBill();
				}
				else if (c == 1)
				{
					b.viewAllBills();
				}
				else if (c == 2)
				{
					char ans;
					cout << "Are you sure you wish to clear all entries[y/n]?\n";
					cin >> ans;
					if (ans == 'y')
					{
						b.clearAll();
						cout << "The file was succsessfully cleared";
					}
					else
					{
						cout << "The file was not cleared you will be returned to the main menu.\n" << endl;
					}

				}
			}
			else if (choice == 2)
			{
				Status s;
				s.viewStatus();
			}
			else
			{
				return 1;
			}
		}
		cout << "\nThanks for using My Finance Helper.";
	}
	return 0;
}

