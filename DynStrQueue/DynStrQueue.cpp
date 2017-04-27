#include "DynStrQueue.h"
#include <string>
#include <iostream>
using namespace std;

// Constructor
DynStrQueue::DynStrQueue()
{
	front = nullptr;
	rear = nullptr;
	numItems = 0;
}

// Destructor
DynStrQueue::~DynStrQueue()
{
	string x;
	while (!isEmpty())
		dequeue(x);
}

/**********************************************************************
Function: enqueue
Purpose: Creates a new node and adds it to the end of the queue.
		 Returns -1 for empty strings.
Parameters: string
Returns: int
**********************************************************************/

int DynStrQueue::enqueue(string name)
{
	if (name.length() == 0)
		return -1;
	
	QueueNode *newNode = new QueueNode;
	newNode->value = name;
	newNode->next = nullptr;

	if (isEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}

	numItems++;
	return 0;
}

/**********************************************************************
Function: dequeue
Purpose: Stores value of first node in name and removes it.
		 Returns -1 if queue is empty.
Parameters: string
Returns: int
**********************************************************************/

int DynStrQueue::dequeue(string &name)
{
	QueueNode *temp = nullptr;

	if (isEmpty())
		return -1;
	
	name = front->value;
	temp = front;
	front = front->next;
	delete temp;
	numItems--;
	return 0;
}

/**********************************************************************
Function: makeFront
Purpose: Creates a new node and adds it to the front of the queue.
		 Returns -1 for empty strings.
Parameters: string
Returns: int
**********************************************************************/

int DynStrQueue::makeFront(string name)
{
	if (name.length() == 0)
		return -1;

	QueueNode *newNode = new QueueNode;
	newNode->value = name;
	newNode->next = nullptr;

	if (isEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		newNode->next = front;
		front = newNode;
	}

	numItems++;
	return 0;
}

/**********************************************************************
Function: display
Purpose: Displays values of queue in order, or message if empty.
Parameters: none
Returns: none
**********************************************************************/

void DynStrQueue::display()
{
	QueueNode *temp = front;

	if (isEmpty())
		cout << "The queue is empty.\n";
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
Purpose: Returns true if queue is empty.
Parameters: none
Returns: bool
**********************************************************************/

bool DynStrQueue::isEmpty() const
{
	bool status;

	if (numItems > 0)
		status = false;
	else
		status = true;
	
	return status;
}