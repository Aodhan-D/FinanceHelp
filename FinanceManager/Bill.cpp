#include <iostream>
#include <string>
#include <fstream>
#include "Bill.h"

using namespace std;
void Bill::AddBill() {
	cout << "\n============================\n"
		<< "	Add Bill "
		<< "\n============================" << endl;
	int temp = 0;
	double amount;
	string i;
	string des;
	string t;

	//asking the user to enter the amount of money
	cout << "Enter amount that needs to be paid: $";
	cin >> amount;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Please enter a valid amount: ";
		cin >> amount;
	}


	getline(cin, t);

	cout << "Enter the date it must be paid by [dd/mm/yyyy]: ";
	getline(cin, i);

	cout << "Enter what it is for: ";
	getline(cin, des);

	//open file for registration
	ofstream g("Bill.txt", ios::app);
	ofstream h("TotalBill.txt", ios::app);
	if (!g.is_open())

	{
		std::cout << "could not open file\n";

	}
	h << amount;
	h << '\n';
	g << '$' << amount;
	g << '\t';
	g << "Date: " << i;
	g << '\t';
	g << "Description: " << des << "\n";
	g.close();
	cout << "Bill Successfully Added!\n";
	cout << "You will now be returned to the menu\n\n";
}

void Bill::viewAllBills() {
	{
		cout << "\n============================\n"
			<< "   View All Bills "
			<< "\n============================" << endl;

		ifstream f("Bill.txt");

		if (f.is_open())
			cout << "----------------------------------------------------------------\n";
		cout << f.rdbuf();
		cout << "----------------------------------------------------------------\n";
		cout << "All entries shown above." << endl;
		cout << "You will now be returned to the main menu.\n" << endl;
	}

}
void Bill::clearAll() {
	ofstream g("Bill.txt");
	g << "";
}