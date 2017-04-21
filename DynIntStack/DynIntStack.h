#ifndef DYNINTSTACK_H
#define DYNINTSTACK_H

class DynIntStack
{
	protected:
		struct StackNode
		{
			int value;
			StackNode *next;
		};

		StackNode *top;

	public:
		DynIntStack()
		{
			top = nullptr;
		}
		~DynIntStack();
	
		void push(int);
		int pop(int &);
		void display();
		bool isEmpty();
};

#endif