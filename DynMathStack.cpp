#include "DynMathStack.h"

/**********************************************************************
Function: add
Purpose: Replaces the first 2 ints on the stack with their sum.
Parameters: none
Returns: int
**********************************************************************/

int DynMathStack::add()
{
	int num, sum;

	// -1 error if empty, else pop sum.
	if (isEmpty())
		return -1;
	else
		pop(sum);
	
	// If empty push sum back and return -1 error, else pop num.
	if (isEmpty())
	{
		push(sum);
		return -1;
	}
	else
		pop(num);

	// Sum both values and push result.
	sum += num;
	push(sum);
	return 0;
}

/**********************************************************************
Function: sub
Purpose: Replaces the first 2 ints on the stack with their difference.
Parameters: none
Returns: int
**********************************************************************/

int DynMathStack::sub()
{
	int num, diff;

	// -1 error if empty, else pop diff.
	if (isEmpty())
		return -1;
	else
		pop(diff);

	// If empty push diff back and return -1 error, else pop num.
	if (isEmpty())
	{
		push(diff);
		return -1;
	}
	else
		pop(num);

	// Subtract num from diff and push result.
	diff -= num;
	push(diff);
	return 0;
}

/**********************************************************************
Function: mult
Purpose: Replaces the first 2 ints on the stack with their product.
Parameters: none
Returns: int
**********************************************************************/

int DynMathStack::mult()
{
	int num, prd;

	// -1 error if empty, else pop prd.
	if (isEmpty())
		return -1;
	else
		pop(prd);

	// If empty push prd back and return -1 error, else pop num.
	if (isEmpty())
	{
		push(prd);
		return -1;
	}
	else
		pop(num);

	// Multiply prd and num, push result.
	prd *= num;
	push(prd);
	return 0;
}

/**********************************************************************
Function: add
Purpose: Replaces the first 2 ints on the stack with their quotient.
Parameters: none
Returns: int
**********************************************************************/

int DynMathStack::div()
{
	int num, qnt;

	// -1 error if empty, else pop qnt.
	if (isEmpty())
		return -1;
	else
		pop(qnt);

	// If empty push prd back and return -1 error, else pop qnt.
	if (isEmpty())
	{
		push(qnt);
		return -1;
	}
	else
		pop(num);

	// If divide by 0, push num and qnt back and return -1 error.
	if (num == 0)
	{
		push(num);
		push(qnt);
		return -1;
	}

	// Divide qnt by num, push result.
	qnt /= num;
	push(qnt);
	return 0;
}