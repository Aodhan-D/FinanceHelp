#pragma once
#include <string>

class UUDate
{

private:
	//Date data
	int day_;
	int month_;
	int year_;
	std::string date_;

	int numOfDays[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 }; // array holding the last day of each month

public:
	UUDate(); //Default constructor sets date to 1/1/2000


	UUDate(int day, int month, int year); //Non default constructors
	UUDate(std::string date); //Should accept "2/8/2018" or "02/08/2018

	int Between(UUDate date); //Return # days between object and date
	std::string GetDate() const; //Return date as a string in correct format

								 //Getters and Setters, remember to validate input to setters
	int GetDay() const;
	void SetDay(int day);
	int GetMonth() const;
	void SetMonth(int month);
	int GetYear() const;
	void SetYear(int year);
	void SetDate(std::string date);
	void validation(int day, int month, int year); //Validation method for validating inputs

	void IncrementDate();//Increment the current date by one day

};