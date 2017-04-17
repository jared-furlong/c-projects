#include "DynIntStack.h"
#include <iostream>
using namespace std;

/**********************************************************************
Function: destructor
Purpose: Traverses the stack deleting each node.
Parameters: none
Returns: none
**********************************************************************/

DynIntStack::~DynIntStack()
{
	StackNode *nodePtr = top, *nextNode = nullptr;

	while (nodePtr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

/**********************************************************************
Function: push
Purpose: Takes an int and add it to top of the stack.
Parameters: int
Returns: none
**********************************************************************/

void DynIntStack::push(int num)
{
	StackNode *newNode = nullptr;

	// Allocate new node and store value of num.
	newNode = new StackNode;
	newNode->value = num;

	// If no other nodes, make first node.
	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else // Else insert before top.
	{
		newNode->next = top;
		top = newNode;
	}
}

/**********************************************************************
Function: pop
Purpose: Removes top node of stack and stores it in reference int.
Parameters: int
Returns: int
**********************************************************************/

int DynIntStack::pop(int &num)
{
	StackNode *temp = nullptr;

	// Return -1 error if stack is empty.
	if (isEmpty())
		return -1;
	
	else // Pop off top value of stack.
	{
		num = top->value;
		temp = top->next;
		delete top;
		top = temp;
		return 0;
	}
}

/**********************************************************************
Function: display
Purpose: Traverses the stack, displaying each value.
Parameters: int
Returns: none
**********************************************************************/

void DynIntStack::display()
{
	StackNode *temp = top;

	if (isEmpty())
		cout << "The stack is empty.\n";
	else
	{
		while (temp)
		{
			cout << temp->value << endl;
			temp = temp->next;
		}
	}
}

/**********************************************************************
Function: isEmpty
Purpose: Returns true if stack is currently empty.
Parameters: none
Returns: bool
**********************************************************************/

bool DynIntStack::isEmpty()
{
	bool status;

	if (!top)
		status = true;
	else
		status = false;

	return status;
}