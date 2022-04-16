//============================================================================
// Name        : ProjectOne.cpp
// Author      : Kevin Tormey
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
void CheckUserPermissionAccess();
void ChangeCustomerChoice(string List[]);
void DisplayInfo(string List[]);

int main()
{
	string clients[5];
	clients[0] = "Bob Jones";
	clients[1] = "Sarah Davis";
	clients[2] = "Amy Friendly";
	clients[3] = "Johnny Smith";
	clients[4] = "Carol Spears";
	cout << "Created by Kevin Tormey" << endl;
	cout << "Hello! Welcome to our Investment Company" << endl;
	CheckUserPermissionAccess();
	int choice;
	while(choice != 3)
	{
		cout << "What would you like to do?" << endl;
		cout << "DISPLAY the client list (enter 1)" << endl;
		cout << "CHANGE a client's choice (enter 2)" << endl;
		cout << "Exit the program (enter 3)" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "You chose 1" << endl;
			DisplayInfo(clients);
		}
		else if (choice == 2)
		{
			cout << "You chose 2" << endl;
			ChangeCustomerChoice(clients);
		}
	}
	return 0;
}
void CheckUserPermissionAccess()
{
	string username;
	string password;
	string check = "123";
	cout << "Enter Username" << endl;
	cin >> username;
	while(1)
	{
		cout << "Enter your password" << endl;
		cin >> password;
		if (password != check)
		{
			cout << "Invalid Password Please Try Again" << endl;
			cin >> password;
		}
		else
		{
			break;
		}
	}
}
void ChangeCustomerChoice(string List[])
{
	cout << "Client's Name Service Selected (1 = Brokerage, 2 = Retirement" << endl;
	int selection;
	cin >> selection;
	cout << "Selected " << selection << endl;
	cout << "Enter the number of the client you wish to change" << endl;
	int client;
	cin >> client;
	client++;
	string clientName = List[client];
	if (selection == 1)
	{
		List[client] = clientName + " Brokerage";
	}
	else if (selection == 2)
	{
		List[client] = clientName + " Retired";
	}
}
void DisplayInfo(string List[])
{
	int i = 0;
	while (i < 5)
	{
		cout << List[i] << endl;
		i++;
	}
}
