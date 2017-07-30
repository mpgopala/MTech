/*
 * main.cpp
 *
 *  Created on: 29-Jul-2017
 *      Author: gsharma
 */

#include "AckermanFunction.hpp"

#include "utils/CircularLinkedList.hpp"
#include "utils/LinkedList.hpp"
#include "utils/Stack.hpp"

#include <iostream>
using namespace std;

void testAckermanFunction(int x, int y)
{
	cout<< "ackerman("<<x<<", "<<y<<") is "<<ackerman(x, y)<<endl;
}

void testStack()
{
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.pop();

	cout<<"Top of stack should be 2. It is "<<stack.top()<<endl;
}

int main()
{
	testAckermanFunction(3, 4);

	testStack();

	return 0;
}


