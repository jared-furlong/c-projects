// Jared Furlong
// CISC 187 - Spring 2017
// Program Assignment - Chapter 18 Queues
// 4/25/17

// This program uses a custom class to create a dynamic queue of names, with the option to add a name to the front.
// A menu is used to access all of the member functions.

#include <iostream>
#include <sstream>
#include "DynStrQueue.h"
#include <string>
using namespace std;

// Function Prototypes
int getInt();
string getStr(int);
int menu();
void enqueue(DynStrQueue &);
void dequeue(DynStrQueue &);
void makeFront(DynStrQueue &);
void display(DynStrQueue &);

int main()
{
	int choice;
	DynStrQueue list;
	
	do
	{
		// Call the menu function and return the menu choice.
		choice = menu();

		// Switch to choosen menu option.
		switch (choice)
		{
		case 1:		// Enqueue a string.

			enqueue(list);
			break;

		case 2:		// Dequeue a string.

			dequeue(list);
			break;

		case 3:		// Add a string to the front of the queue.

			makeFront(list);
			break;
		
		case 4:		// Display the list

			display(list);
			break;
		
		case 5:		// Exit the menu.

			cout << "Thank you for using my program!";
			break;
		}
	} while (choice != 5);

	system("pause>nul");
	return 0;
}

/**********************************************************************
Function: getInt
Purpose: Prompts user to enter a number. Converts to int, dropping any
decimal places.
Parameters: none
Returns: int
**********************************************************************/

int getInt()
{
	int number;
	string input;

	while (true)
	{
		getline(cin, input);

		// This code converts from string to int safely.
		stringstream stream(input);
		if (stream >> number)
		{
			return number;
		}

		cout << "Invalid integer, please try again: ";
	}
}

/**********************************************************************
Function: getStr
Purpose: Prompts user to enter a string. Validates for not empty and
		 less than a max size.
Parameters: int
Returns: string
**********************************************************************/

string getStr(int max)
{
	int number;
	string input;

	while (true)
	{
		getline(cin, input);

		if (input.length() != 0 && input.length() <= max)
		{
				return input;
		}

		cout << "Invalid input, please enter between 1 and " << max << " characters: ";
	}
}

/**********************************************************************
Function: menu
Purpose: Displays menu of options, validates and returns choice.
Parameters: none
Returns: int
**********************************************************************/

int menu()
{
	int choice;

	// Display the menu and store user's choice.
	cout << "Choose an action to perform:\n"
		<< "1. Add a name to the end of the list.\n"
		<< "2. Let one person into the club.\n"
		<< "3. Add a name to the front of the list.\n"
		<< "4. Display the list of names.\n"
		<< "5. Exit.\n\n"
		<< "Enter your choice (1-5): ";
	choice = getInt();

	// Validate the menu choice.
	while (choice < 1 || choice > 5)
	{
		cout << "Please enter a valid choice (1-5): ";
		choice = getInt();
	}

	cout << endl;
	return choice;
}

/**********************************************************************
Function: enqueue
Purpose: Gets a name and adds it to the end of the list.
Parameters: DynStrQueue
Returns: none
**********************************************************************/

void enqueue(DynStrQueue &list)
{
	string name;

	cout << "Name to add to the end of the list: ";
	name = getStr(15);

	list.enqueue(name);
	cout << name << " has been added to the end of the list.\n\n";
}

/**********************************************************************
Function: dequeue
Purpose: Removes a name from the front of the list.
Parameters: DynStrQue
Returns: none
**********************************************************************/

void dequeue(DynStrQueue &list)
{
	int error;
	string name;

	error = list.dequeue(name);

	if (error == -1)
		cout << "List is empty.\n\n";
	else
	{
		cout << name << " has been removed from the front of the list.\n\n";
	}
}

/**********************************************************************
Function: makeFront
Purpose: Gets a name and adds it to the front of the list.
Parameters: DynStrQueue
Returns: none
**********************************************************************/

void makeFront(DynStrQueue &list)
{
	string name;

	cout << "Name to add to the front of the list: ";
	name = getStr(15);

	list.makeFront(name);
	cout << name << " has been added to the front of the list.\n\n";
}

/**********************************************************************
Function: display
Purpose: Displays all of the names in the list.
Parameters: DynStrQueue
Returns: none
**********************************************************************/

void display(DynStrQueue &list)
{
	cout << "Here are the contents of the list:\n";
	list.display();
	cout << endl;
}