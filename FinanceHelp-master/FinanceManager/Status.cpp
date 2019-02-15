#include <iostream>
#include <string>
#include <fstream>
#include "Status.h"
#include <vector>
#include <numeric>

using namespace std;
void Status::viewStatus()
{
	cout << "\n============================\n"
		<< "	Status "
		<< "\n============================\n";

	ifstream in("Total.txt");
	ifstream inB("TotalBill.txt");
	vector<double> vIncome;
	while (in >> readNumber)
	{
		vIncome.push_back(readNumber);
	}
	vector<double> vBill;
	while (inB >> readNumber1)
	{
		vBill.push_back(readNumber1);
	}




	//gets the total of all the values in the vector
	totalIncome = accumulate(vIncome.begin(), vIncome.end(), 0);
	avIncome = totalIncome / vIncome.size();
	//gets the total and average values from the bill vector
	totalBill = accumulate(vBill.begin(), vBill.end(), 0);
	avBill = totalBill / vBill.size();

	//calculating how much has to be paid
	toPaid = totalBill - totalIncome;
	if (toPaid < 0)
	{
		toPaid = 0;
	}
	toIncome = totalIncome - totalBill;
	if (toIncome < 0)
	{
		toIncome = 0;
	}

	//the data is then outputted to the console
	cout << "The number of entered incomes is: " << vIncome.size() << endl;
	cout << "The total income is: $" << totalIncome << endl;
	cout << "The average income is: $" << avIncome << endl;
	cout << "\n";
	cout << "The number of entered bills is: "  <<vBill.size()<< endl;
	cout << "The total for all bills is: $" << totalBill << endl;
	cout << "The average bill costs: $" << avBill << endl;
	cout << "\n";
	cout << "Total payble: $" << totalIncome << endl;
	cout << "Amount you will have left: $" << toIncome << endl;
	cout << "Total to be paid: $" << toPaid << endl;
}