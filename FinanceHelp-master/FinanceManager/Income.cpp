#include<iostream>
#include<fstream>
#include <string>
#include "Income.h"
#include "UUDate.h"

using namespace std;
void Income::AddIncome() {
	cout << "\n============================\n"
		<< "	Add Income "
		<< "\n============================" << endl;
	int temp = 0;
	double amount;
	string i;
	string des;
	string t;

	//asking the user to enter the amount of money
		cout << "Enter amount: $";
		cin >> amount;
		while (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Please enter a valid amount: $";
			cin >> amount;
		}


	getline(cin, t);

	cout << "Enter a date recieved [dd/mm/yyyy]: ";
	getline(cin, i);

	UUDate d{ i };
	i = d.GetDate();

	cout << "Enter a Description: ";
	getline(cin, des);

	//open file for registration
	ofstream g("Income.txt", ios::app);
	ofstream h("Total.txt", ios::app);
	if (!g.is_open())

	{
		std::cout << "could not open file\n";

	}
	h << amount;
	h << '\n';
	g << '$'<< amount;
	g << '\t';
	g <<"Date: " <<i;
	g << '\t';
	g << "Description: "<< des << "\n";
	g.close();
	cout << "Income Successfully Added!\n";
	cout << "You will now be returned to the menu\n\n";
}

void Income::viewAllIncomes() {
	{
		cout << "\n============================\n"
			<< "   View All Income "
			<< "\n============================" << endl;
		ifstream f("Income.txt", ios::app);
		if (f.is_open())
		
			cout << "----------------------------------------------------------------\n";
			cout << f.rdbuf();
			cout << "----------------------------------------------------------------\n";
			cout << "All entries shown above." << endl;
			cout << "You will now be returned to the main menu.\n" << endl;
		
	}

}
void Income::clearAll() {
	ofstream g("Income.txt");
}