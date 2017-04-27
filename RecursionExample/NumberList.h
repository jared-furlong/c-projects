#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
	struct ListNode
	{
		int value;
		struct ListNode *next;
	};

	ListNode *head;
	int maxValue;
	
	// Private recursive member functions
	int countNodes(ListNode *) const;
	int findMaxNode(ListNode *);

public:
	// Constructor
	NumberList()
	{
		head = nullptr;
	}
	
	// Destructor
	~NumberList();

	// Linked List Operations
	void appendNode(int);
	int insertNode(int, int);
	int deleteNode(int);
	int searchList(int) const;
	int reverseList();
	void displayList() const;
	
	// Calls to Recursive Operations
	int numNodes() const
	{
		return countNodes(head);
	}
	int maxNode()
	{
		// Resets the maxValue counter before calling the recursive function.
		maxValue = -1;
		return findMaxNode(head);
	}
};

#endif