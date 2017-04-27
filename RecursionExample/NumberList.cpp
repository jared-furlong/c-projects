#include "NumberList.h"
#include <iostream>
using namespace std;

// Destructor, deletes each node.
NumberList::~NumberList()
{
	ListNode *nodePtr = head;
	ListNode *nextNode = nullptr;

	while (!nodePtr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

/**********************************************************************
Function: appendNode
Purpose: Creates a node with value of num at end of list.
Parameters: int
Returns: none
**********************************************************************/

void NumberList::appendNode(int num)
{
	ListNode *newNode;
	ListNode *nodePtr;

	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}

/**********************************************************************
Function: insertNode
Purpose: Creates a node with value of num at position of pos, returns
		 -1 if position does not exist.
Parameters: int, int
Returns: int
**********************************************************************/

int NumberList::insertNode(int pos, int num)
{
	ListNode *newNode;
	ListNode *nodePtr = head;
	ListNode *previousNode = nullptr;

	newNode = new ListNode;
	newNode->value = num;

	// If position is 0, insert new node at start of list.
	if (pos == 0)
	{
		head = newNode;
		newNode->next = nodePtr;
		return 0;
	}

	// Traverse list until at position.
	for (int i = 0; i < pos; i++)
	{
		if (!nodePtr)	// Return error if at the end of the list.
			return -1;

		previousNode = nodePtr;
		nodePtr = nodePtr->next;
	}

	// Insert new node in list.
	previousNode->next = newNode;
	newNode->next = nodePtr;
	return 0;
}

/**********************************************************************
Function: deleteNode
Purpose: Deletes a node at position of pos, returns -1 if position does
		 not exist.
Parameters: int
Returns: int
**********************************************************************/

int NumberList::deleteNode(int pos)
{
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	// If list is empty, return -2 error.
	if (!head)
		return -2;

	// If position is 0, delete head.
	if (pos == 0)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		return 0;
	}

	nodePtr = head;

	// Traverse list until at position.
	for (int i = 0; i < pos; i++)
	{
		previousNode = nodePtr;
		nodePtr = nodePtr->next;
		
		if (!nodePtr)	// Return -1 error if at the end of the list.
			return -1;
	}

	// If not last node, link previous node to next and delete node.
	if (nodePtr)
	{
		previousNode->next = nodePtr->next;
		delete nodePtr;
		return 0;
	}

	// If last node, point previous to null and delete node.
	previousNode->next = nullptr;
	delete nodePtr;
	return 0;
}

/**********************************************************************
Function: searchList
Purpose: Returns postion of first node with value of num, returns -1 if
		 num is not on list and -2 if list is empty.
Parameters: int
Returns: int
**********************************************************************/

int NumberList::searchList(int num) const
{
	ListNode *nodePtr = head;
	int counter = 0;

	// If list is empty, return -2 error.
	if (!head)
		return -2;

	// Starting at head, traverse list until value == num.
	while (nodePtr->value != num)
	{
		nodePtr = nodePtr->next;
		counter++;

		if (!nodePtr)	// Return -1 error if at the end of the list.
			return -1;
	}

	// Return position, with first node being 0.
	return counter;
}

/**********************************************************************
Function: reverseList
Purpose: Reverses the order of nodes in the list, returns -1 if list
		 contains 0 or 1 nodes.
Parameters: none
Returns: int
**********************************************************************/

int NumberList::reverseList()
{
	ListNode *placeHolder1 = nullptr;
	ListNode *placeHolder2 = nullptr;
	ListNode *previousNode = nullptr;
	ListNode *lastNode = head;
	int counter = 0;

	// If list is empty or has 1 node, return error.
	if ((!head) || (!head->next))
		return -1;

	// Traverse to end of list and count size.
	while (lastNode->next)
	{
		previousNode = lastNode;
		lastNode = lastNode->next;
		counter++;
	}

	// Move last node to head.
	lastNode->next = head;
	head = lastNode;
	previousNode->next = nullptr;
	counter--;

	while (counter > 0)
	{
		// placeHolder1 is now the node that was just moved and placeHolder2 is the next node.
		placeHolder1 = lastNode;
		placeHolder2 = lastNode->next;

		// Traverse to end of list.
		while (lastNode->next)
		{
			previousNode = lastNode;
			lastNode = lastNode->next;
		}

		// Move last node to between placeHolder1 and placeHolder2.
		lastNode->next = placeHolder2;
		placeHolder1->next = lastNode;
		previousNode->next = nullptr;
		
		counter--;
	}
	
	return 0;
}

/**********************************************************************
Function: displayList
Purpose: Outputs the values of all nodes in the list.
Parameters: none
Returns: none
**********************************************************************/

void NumberList::displayList() const
{
	ListNode *nodePtr = head;

	while (nodePtr)
	{
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
}

/**********************************************************************
Function: countNodes
Purpose: Uses recursion to return the number of nodes in the list.
Parameters: ListNode
Returns: int
**********************************************************************/

int NumberList::countNodes(ListNode *nodePtr) const
{
	// If current node exists return 1 + number of remaining nodes.
	if (nodePtr != nullptr)
		return 1 + countNodes(nodePtr->next);
	
	// At end of list return 0, base case.
	else
		return 0;
}

/**********************************************************************
Function: findMaxNode
Purpose: Uses recursion to return the value of the largest node on the
		 list.
Parameters: ListNode
Returns: int
**********************************************************************/

int NumberList::findMaxNode(ListNode *nodePtr)
{	
	// Traverse the list using recursion.
	if (nodePtr != nullptr)
	{
		// If current value > maxValue ,then replace maxValue with current value.
		if (nodePtr->value > maxValue)
			maxValue = nodePtr->value;
		
		// Call the next node.
		return findMaxNode(nodePtr->next);
	}
	
	// At end of list return maxValue, base case.
	else
		return maxValue;
}