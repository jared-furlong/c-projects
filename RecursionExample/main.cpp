// Jared Furlong
// CISC 187 - Spring 2017
// Program Assignment - Chapter 17
// 4/10/17

// This program uses a linked list class to create a list of integers. It allows the user to append,
// insert, delete, search, reverse, and display the list. It uses a menu to drive user input.

#include <iostream>
#include <sstream>
#include "NumberList.h"
using namespace std;

// Function Prototypes
int getInt();
int menu();
void appendNode(NumberList &);
void insertNode(NumberList &);
void deleteNode(NumberList &);
void search(const NumberList &);
void reverse(NumberList &);
void display(const NumberList &);
void numNodes(const NumberList &);
void maxNode(NumberList &);

int main()
{
	int choice;
	NumberList list;
	
	do
	{
		// Call the menu function and return the menu choice.
		choice = menu();

		// Switch to choosen menu option.
		switch (choice)
		{
		case 1:		// Append a node

			appendNode(list);
			break;

		case 2:		// Insert a node

			insertNode(list);
			break;

		case 3:		// Delete a node

			deleteNode(list);
			break;

		case 4:		// Search the list

			search(list);
			break;
		
		case 5:		// Reverse the list

			reverse(list);
			break;

		case 6:		// Display the list

			display(list);
			break;
		
		case 7:		// Display number of nodes.

			numNodes(list);
			break;

		case 8:		// Display the max value node.

			maxNode(list);
			break;
		
		case 9:		// Exit the menu.

			cout << "Thank you for using my program!";
			break;
		}
	} while (choice != 9);

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
			if (number >= 0)	// Reject negative numbers	
				return number;
		}

		cout << "Invalid number, please try again: ";
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
		<< "1. Append a node to the list.\n"
		<< "2. Insert a node in the list.\n"
		<< "3. Delete a node in the list.\n"
		<< "4. Search the list for a value.\n"
		<< "5. Reverse the list.\n"
		<< "6. Display the list.\n"
		<< "7. Display number of nodes in the list.\n"
		<< "8. Display max value of nodes in the list.\n"
		<< "9. Exit the program.\n\n"
		<< "Enter your choice (1-9): ";
	choice = getInt();

	// Validate the menu choice.
	while (choice < 1 || choice > 9)
	{
		cout << "Please enter a valid choice (1-9): ";
		choice = getInt();
	}

	cout << endl;
	return choice;
}

/**********************************************************************
Function: appendNode
Purpose: Prompts the user to add a number to the end of list.
Parameters: NumberList
Returns: none
**********************************************************************/

void appendNode(NumberList &list)
{
	int number;
	
	cout << "Number to append to the end of the list: ";
	number = getInt();

	list.appendNode(number);

	cout << number << " has been added to the end of the list.\n\n";
}

/**********************************************************************
Function: insertNode
Purpose: Prompts the user to add a number to the list at a specific
		 position.
Parameters: NumberList
Returns: none
**********************************************************************/

void insertNode(NumberList &list)
{
	int position, number, error;

	cout << "Position to insert number on: ";
	position = getInt();

	cout << "Number to insert: ";
	number = getInt();

	error = list.insertNode(position, number);

	// Returns -1 for an invalid position, prompts user again.
	while (error == -1)
	{
		cout << "Invalid position. Try a different position: ";
		position = getInt();

		cout << "Number to insert: ";
		number = getInt();

		error = list.insertNode(position, number);
	}

	cout << number << " has been inserted at position " << position << endl << endl;
}

/**********************************************************************
Function: deleteNode
Purpose: Prompts the user for a position on the list to delete.
Parameters: NumberList
Returns: none
**********************************************************************/

void deleteNode(NumberList &list)
{
	int position, error;

	cout << "Position of number to delete: ";
	position = getInt();

	error = list.deleteNode(position);

	// Returns -2 if list is empty, then returns to menu.
	if (error == -2)
	{
		cout << "Cannot delete, the list is empty.\n\n";
		return;
	}

	// Returns -1 for an invalid position, prompts user again.
	while (error == -1)
	{
		cout << "Invalid position. Try a different position: ";
		position = getInt();

		error = list.deleteNode(position);
	}

	cout << "Position " << position << " has been deleted\n\n";
}

/**********************************************************************
Function: search
Purpose: Prompts the user for a position on the list and returns the
		 value at that position.
Parameters: NumberList
Returns: none
**********************************************************************/

void search(const NumberList &list)
{
	int number, position;

	cout << "Value of number to search for: ";
	number = getInt();

	position = list.searchList(number);

	// Returns -2 if list is empty, then returns to menu.
	if (position == -2)
	{
		cout << "Cannot search, the list is empty.\n\n";
		return;
	}

	// Returns -1 for number not found, prompts user again.
	while (position == -1)
	{
		cout << "Number not found. Try a different number: ";
		number = getInt();

		position = list.searchList(number);
	}

	cout << "The number " << number << " is first found at position: " << position << endl << endl;
}

/**********************************************************************
Function: reverse
Purpose: Reverses the order of the numbers on the list.
Parameters: NumberList
Returns: none
**********************************************************************/

void reverse(NumberList &list)
{
	int error;

	error = list.reverseList();

	// Returns -1 if the list contains 0 or 1 numbers.
	if (error == -1)
		cout << "List cannot be reverse, it contains 0 or 1 numbers.\n\n";
	else
		cout << "List has been reversed.\n\n";
}

/**********************************************************************
Function: display
Purpose: Displays all of the numbers on the list.
Parameters: NumberList
Returns: none
**********************************************************************/

void display(const NumberList &list)
{
	cout << "Here are the contents of the list:\n";
	list.displayList();
	cout << endl;
}

/**********************************************************************
Function: numNodes
Purpose: Displays the number of nodes in the list.
Parameters: NumberList
Returns: none
**********************************************************************/

void numNodes(const NumberList &list)
{
	cout << "There are " << list.numNodes() << " nodes in the list.\n\n";
}

/**********************************************************************
Function: maxNode
Purpose: Displays the max value of all nodes in the list.
Parameters: NumberList
Returns: none
**********************************************************************/

void maxNode(NumberList &list)
{
	// Returns -1 if list is empty.
	if (list.maxNode() == -1)
		cout << "No max value, the list is empty.\n\n";
	else
		cout << "The max value of any node in the list is " << list.maxNode() << ".\n\n";
}