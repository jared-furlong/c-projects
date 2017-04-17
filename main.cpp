// Jared Furlong
// CISC 187 - Spring 2017
// Program Assignment - Chapter 18 Stacks
// 4/18/17

// This program uses custom classes to create a dynamic stack of integers with basic math functions.
// A menu is used to access all of the member functions.

#include <iostream>
#include <sstream>
#include "DynMathStack.h"
using namespace std;

// Function Prototypes
int getInt();
int menu();
void push(DynMathStack &);
void pop(DynMathStack &);
void add(DynMathStack &);
void subtract(DynMathStack &);
void multiply(DynMathStack &);
void divide(DynMathStack &);
void display(DynMathStack &);

int main()
{
	int choice;
	DynMathStack stack;
	
	do
	{
		// Call the menu function and return the menu choice.
		choice = menu();

		// Switch to choosen menu option.
		switch (choice)
		{
		case 1:		// Push # onto stack

			push(stack);
			break;

		case 2:		// Pop # off of stack

			pop(stack);
			break;

		case 3:		// Sum  of top 2 values

			add(stack);
			break;

		case 4:		// Difference of top 2 values

			subtract(stack);
			break;
		
		case 5:		// Product of top 2 values

			multiply(stack);
			break;

		case 6:		// Quotient of top 2 values

			divide(stack);
			break;
		
		case 7:		// Display the list

			display(stack);
			break;
		
		case 8:		// Exit the menu.

			cout << "Thank you for using my program!";
			break;
		}
	} while (choice != 8);

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
		<< "1. Push\n"
		<< "2. Pop\n"
		<< "3. Add\n"
		<< "4. Subtract\n"
		<< "5. Multiply\n"
		<< "6. Divide\n"
		<< "7. Display\n"
		<< "8. Exit\n\n"
		<< "Enter your choice (1-8): ";
	choice = getInt();

	// Validate the menu choice.
	while (choice < 1 || choice > 8)
	{
		cout << "Please enter a valid choice (1-8): ";
		choice = getInt();
	}

	cout << endl;
	return choice;
}

/**********************************************************************
Function: push
Purpose: Gets an integer to push onto the stack.
Parameters: DynMathStack
Returns: none
**********************************************************************/

void push(DynMathStack &stack)
{
	int number;

	cout << "Integer to push onto the stack: ";
	number = getInt();

	stack.push(number);
	cout << number << " has been pushed to the stack.\n\n";
}

/**********************************************************************
Function: pop
Purpose: Pops the top number off the stack.
Parameters: DynMathStack
Returns: none
**********************************************************************/

void pop(DynMathStack &stack)
{
	int number, error;

	error = stack.pop(number);

	if (error == -1)
		cout << "Stack is empty, can not pop.\n\n";
	else
	{
		cout << number << " has been popped off of the stack.\n\n";
	}
}

/**********************************************************************
Function: add
Purpose: Sums the top two values of the stack.
Parameters: DynMathStack
Returns: none
**********************************************************************/

void add(DynMathStack &stack)
{
	int error;

	error = stack.add();

	if (error == -1)
		cout << "Can not sum, less than 2 integers on the stack.\n\n";
	else
	{
		cout <<"The first 2 integers on the stack have been replaced by their sum.\n\n";
	}
}

/**********************************************************************
Function: subtract
Purpose: Subtacts the top two values of the stack.
Parameters: DynMathStack
Returns: none
**********************************************************************/

void subtract(DynMathStack &stack)
{
	int error;

	error = stack.sub();

	if (error == -1)
		cout << "Can not subtract, less than 2 integers on the stack.\n\n";
	else
	{
		cout << "The first 2 integers on the stack have been replaced by their difference.\n\n";
	}
}

/**********************************************************************
Function: multiply
Purpose: Sums the top two values of the stack.
Parameters: DynMathStack
Returns: none
**********************************************************************/

void multiply(DynMathStack &stack)
{
	int error;

	error = stack.mult();

	if (error == -1)
		cout << "Can not multiply, less than 2 integers on the stack.\n\n";
	else
	{
		cout << "The first 2 integers on the stack have been replaced by their product.\n\n";
	}
}

/**********************************************************************
Function: divide
Purpose: Sums the top two values of the stack.
Parameters: DynMathStack
Returns: none
**********************************************************************/

void divide(DynMathStack &stack)
{
	int error;

	error = stack.div();

	if (error == -1)
		cout << "Can not divide, less than 2 integers on the stack or divide by 0.\n\n";
	else
	{
		cout << "The first 2 integers on the stack have been replaced by their quotient.\n\n";
	}
}

/**********************************************************************
Function: display
Purpose: Displays all of the numbers on the stack.
Parameters: DynMathStack
Returns: none
**********************************************************************/

void display(DynMathStack &stack)
{
	cout << "Here are the contents of the stack:\n";
	stack.display();
	cout << endl;
}