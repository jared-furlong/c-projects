#ifndef DYNMATHSTACK_H
#define DYNMATHSTACK_H
#include "DynIntStack.h"

class DynMathStack : public DynIntStack
{
	public:
		DynMathStack() {}
		~DynMathStack() {}

		int add();
		int sub();
		int mult();
		int div();
};

#endif