#pragma once
#include <string>
#include "Status.h"
using namespace std;
class MainMenu
{
private:
	string
		command,
		name, password,
		inName, inPassword,
		registerName, registerPassword;
	string pass = "";
	char ch;
public:
	//default constructor
	MainMenu();

	int menu();
};
