#include "MainMenu.h"
#include<iostream>
#include<fstream>
#include <conio.h>

using namespace std;
MainMenu::MainMenu() {

}

int MainMenu::menu()
{
	while (1)
	{
		cout << "============================\n"
			<< "Welcome to My Finace Helper. "
			<< "\n============================" << endl;
		cout << "Would you like to register, login or exit?\n" << "Enter Command: ";
		
		getline(cin, command);

		if (command == "exit") {
			return 1;
		}
		if (command == "register")
		{
			//open file for registration
			ofstream g("registration.txt"); 

			if (!g.is_open()) 

			{
				cout << "could not open file\n";
				
				return 0;
			}
			cout << "New Username: ";
			getline(cin, registerName); //input from keyboard will go into registerName
			cout << "New Password: ";
			getline(cin, registerPassword); //input from keyboard will go into registerPassword
			g << registerName; 

			g << '\n'; //and now there will be a new line
			g << registerPassword; //and now the password
								   //all placed safely in the file that g opened
			g.close(); //always make sure you close the file, or else you might end up with some nasty
					   //stuff in the memory
		}
		if (command == "login") //(for C strings) if (!strcmp(command, "login"))
		{
			//open file, and then put the name and password into the strings
			ifstream f("registration.txt"); //ifstream is the one for getting data from the file, and
											//let us assume you've already created a file called "registration.txt"
			if (!f.is_open()) //if it's not open, then there is no such file with the given name inside
							  //the folder (that is, in the folder where the .exe file is going to be)
			{
				cout << "could not open file\n"; //just so that you know why it won't work if it doesn't
				return 0;
			}
			getline(f, name, '\n'); //reads the user name from file f (which is using "registration.txt")
			getline(f, password, '\n'); //reads the password from file f (which is using "registration.txt")
										//also, if you tell the file to get you that text up until '\n', that's when you know it reads
										//the whole line at most, and won't go any further
										//and that is done by the 3rd parameter
			f.close(); //you don't need it open now, since you have the name and password from the file

					   //login
			while (1)
			{
				//you are going to input the name and password here
				cout 
					<< "Enter Username: ";
				getline(cin, inName);
				cout << "Enter Password: ";
				
				getline(cin, inPassword);

				if (inName == name && inPassword == password)
				{
					cout << "\nLogin Successful\n" //the '\n' is a character, so that's why I can add it 
												 //and it will automatically output a newline in console, alongside the string
						<< "Welcome, "
						<< inName;
					break; //just exit the while loop if you've entered the valid account
				}
				cout << "incorrect name or password\n"; //if you haven't entered the valid account,
														//then the while loop is not done yet. So that's why this output is without condition
			}
			break;
		}

	}
	return 0;
}