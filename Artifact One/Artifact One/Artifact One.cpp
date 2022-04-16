//============================================================================
// Name        : Artifcat One.cpp
// Author      : Kevin Tormey
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;
void CheckUserPermissionAccess();
void ChangeCustomerChoice(std::list<string> List);
void DisplayInfo(std::list<string> List);
void AddNewCustomer(std::list<string> List);
void RemoveCustomer(std::list<string> List);

int main()
{
	std::list<string> clients{"Bob Jones", "Sarah Davis", "Amy Friendly", "Johnny Smith", "Carol Spears"};
	cout << "Created by Kevin Tormey" << endl;
	cout << "Hello! Welcome to our Investment Company" << endl;
	CheckUserPermissionAccess();
	int choice = 0; // Uninitialized Variable, changed to default to 0
	while (choice != 3)
	{
		cout << "What would you like to do?" << endl;
		cout << "DISPLAY the client list (enter 1)" << endl;
		cout << "CHANGE a client's choice (enter 2)" << endl;
		cout << "ADD new client (enter 3)" << endl;
		cout << "REMOVE a client (enter 4)" << endl;
		cout << "Exit the program (enter 5)" << endl;
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
		else if (choice == 3)
		{
			cout << "You chose 3" << endl;
			AddNewCustomer(clients);
		}
		else if (choice == 4)
		{
			cout << "You chose 4" << endl;
			RemoveCustomer(clients);
		}
		else if (choice == 5)
		{
			cout << "You chose 5" << endl;
			break;
		}
	}
	return 0;
}
void CheckUserPermissionAccess()
{
	string username = " "; // Uninitialized Variable, changed to be a space by default
	string password = " "; // Uninitialized Variable, changed to be a space by default
	string check = "CompanyInvestments0156%"; // Too Simple of a Password, changed to new required password of CompanyInvestments0156%
	string userCheck = "admin"; // Accepted user for the database
	while (1)
	{
		cout << "Enter Username" << endl;
		cin >> username; // No Check for correct or valid user, created loop to use as a check and created a new username to be required titled admin
		if (username == userCheck)
		{
			while (1)
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
			break;
		}
		else
		{
			cout << "Invalid username" << endl;
		}
	}
}

void ChangeCustomerChoice(std::list<string> List) // Method to add if client's service has shifted
{
	cout << "Client's Name Service Selected (1 = Brokerage, 2 = Retirement" << endl;
	int selection = 0; // Uninitialized Variable, changed to be set to 0 by default
	cin >> selection;
	cout << "Selected " << selection << endl;
	cout << "Enter the number of the client you wish to change (accepted values 1-5)" << endl; // Added line stating size 1-5
	int client = 0; // Uninitialized Variable, changed to be set to 0 by default
	cin >> client; // Potential Buffer Overflow, loop created to fix potential overflow error
	while (client > 5 || client < 1)
	{
		cout << "Invalid input please input a value from 1 to 5" << endl;
		cin >> client;
	}
	client--; // Changed to be -- instead to prevent overflow
	string clientName = List{client};
	if (selection == 1)
	{
		List{client} = clientName + " Brokerage";
	}
	else if (selection == 2)
	{
		List{client} = clientName + " Retired";
	}
}
void DisplayInfo(std::list<string> List) // Quick function to display the list of clients
{
	for (string n : List)
	{
		std::cout << n << endl;
	}
}
void AddNewCustomer(std::list<string> List) //Function to Add new Client 
{
	cout << "Enter the name of the new client." << endl;
	string newClient;
	cin >> newClient;
	List.push_back(newClient);
	cout << newClient << " has been added to the client list." << endl;
}
void RemoveCustomer(std::list<string> List) // Function to Remove a Client
{
	cout << "Enter the name of the client to be removed" << endl;
	string lostClient;
	cin >> lostClient;
	List.remove(lostClient);
	cout << lostClient << " has been removed from the client list." << endl;
}