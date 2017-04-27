#ifndef DYNSTRQUEUE_H
#define DYNSTRQUEUE_H
#include <string>
using namespace std;

class DynStrQueue
{
private:

	struct QueueNode
	{
		string value;
		QueueNode *next;
	};

	QueueNode *front;
	QueueNode *rear;
	int numItems;

public:

	DynStrQueue();
	~DynStrQueue();

	int enqueue(string);
	int dequeue(string &);
	int makeFront(string);
	void display();
	bool isEmpty() const;
};

#endif