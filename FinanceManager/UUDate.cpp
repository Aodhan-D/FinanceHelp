#include "UUDate.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>


UUDate::UUDate() {
	//default constructors
	day_ = 01;
	month_ = 01;
	year_ = 2000;
}

UUDate::UUDate(int day, int month, int year) {
	//running the inputs through the set methods as they will validate the input values
	validation(day, month, year);
}

UUDate::UUDate(std::string date) {
	{
		//parsing the string to find the seperate day,month and year in it
		std::string full, ToParse(date);
		//intialising a string stream
		std::istringstream StrStream(ToParse);
		//temperory array to hold the values
		int dates[3];
		int x = 0;

		//loop that runs through the string stream parsing the data and saving it to the array
		while (x < 3)
		{
			getline(StrStream, full, '/');
			std::stringstream strm(full);
			strm >> dates[x];
			x++;
		}
		//setting day,month and year to equal the data in the array
		day_ = dates[0];
		month_ = dates[1];
		year_ = dates[2];
		//running the validation method to ensure the inputs are correct
		validation(day_, month_, year_);
	}
}

void UUDate::IncrementDate() {
	//creating a variable for the number of days in the month using the numOfDays[] array
	int noOfDays = numOfDays[GetMonth() - 1];

	//setting the noOfDays to 29 if its a leap year and febuary
	if (GetYear() % 4 == 0 && GetMonth() == 2)
	{
		noOfDays = 29;
	}
	//checking if the day is surpasing the end of the month 
	if ((GetDay() + 1) > noOfDays)
	{
		SetDay(1);

		if (GetMonth() + 1 == 13)
		{
			SetMonth(1);
			SetYear(GetYear() + 1);
		}
		else
		{
			SetMonth(GetMonth() + 1);
		}
	}
	else
	{
		day_ = (day_ + 1);
	}
}

int UUDate::Between(UUDate date) {
	int count = 0;
	bool i = false;
	std::string smaller;
	//while loop to find which year needs to be incremented
	while (i != true)
	{
		if (GetYear() > date.GetYear())
		{
			i = true;
			smaller = date.GetDate();
			break;
		}
		else if (date.GetYear() > GetYear())
		{
			i = true;
			smaller = GetDate();
			break;
		}
		//if years are equal months are compared
		if (GetMonth() > date.GetMonth())
		{
			i = true;
			smaller = date.GetDate();
			break;
		}
		else if (date.GetMonth() > GetMonth())
		{
			i = true;
			smaller = GetDate();
			break;
		}
		//if the months are equal then the years are compared
		if (GetDay() > date.GetDay())
		{
			i = true;
			smaller = date.GetDate();
			break;
		}
		if (date.GetDay() > GetDay())
		{
			i = true;
			smaller = GetDate();
			break;
		}
		//default to break the loop if the dates are equal
		else {
			i = true;
			break;
		}
	}

	if (smaller == GetDate())

		while (day_ < date.GetDay() || month_ < date.GetMonth() || year_ < date.GetYear())
		{
			//incrementing the stored date by one day until both dates are equal
			IncrementDate();
			count++;
		}
	else {
		while (date.GetDay() < GetDay() || date.GetMonth() < GetMonth() || date.GetYear() < GetYear())
		{
			//incrementing the inputted date by one day until both dates are equal
			date.IncrementDate();
			count++;
		}
	}
	return count;
}

int UUDate::GetDay() const {
	return day_;
}

void UUDate::SetDay(int day) {
	//checking which month is being entered and ensuring the day rules are applied
	int temp = numOfDays[GetMonth() - 1];

	if (GetMonth() == 2 && GetYear() % 4 == 0)
	{
		temp = 29;
	}

	if (day <= temp && day > 0)
	{
		day_ = day;
	}

}

int UUDate::GetMonth() const {
	return month_;
}

void UUDate::SetMonth(int month) {
	//only months between 1 and 12 are valid if invalid the month is set to default
	if (month >= 1 && month <= 12)
	{
		month_ = month;
	}
}

int UUDate::GetYear() const {
	return year_;
}

void UUDate::SetYear(int year) {
	//simple validation ensuring the year is not 0 or below
	if (year > 0)
	{
		year_ = year;
	}
}

void UUDate::SetDate(std::string date) {
	date_ = date;
}

std::string UUDate::GetDate() const
{
	std::string str, str2, str3;
	//converting the Day, Month and Year intergers to strings
	str = std::to_string(GetDay());
	if (str.length() == 1)
	{
		str = std::to_string(0) + str;
	}
	str2 = std::to_string(GetMonth());
	if (str2.length() == 1)
	{
		str2 = std::to_string(0) + str2;
	}
	str3 = std::to_string(GetYear());

	std::string temp = str + '/' + str2 + '/' + str3;


	date_ == temp;

	return temp;
}

void UUDate::validation(int day, int month, int year)
{
	//validation for the month
	if (month >= 1 && month <= 12)
	{
		month_ = month;
	}
	else
	{
		month_ = 01;
	}

	//validation for the year
	if (year > 0)
	{
		year_ = year;
	}
	else
	{
		year_ = 2000;
	}

	//validation for the days in the year
	int c = numOfDays[month_ - 1];

	if (month_ == 2 && year_ % 4 == 0)
	{
		c = 29;
	}
	if (day <= c && day > 0)
	{
		day_ = day;
	}
	else
	{
		day_ = 1;
	}
}