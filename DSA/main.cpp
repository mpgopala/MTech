/*
 * main.cpp
 *
 *  Created on: 29-Jul-2017
 *      Author: gsharma
 */

#include "include/AckermanFunction.hpp"

#include <iostream>

#include "include/CircularLinkedList.hpp"
#include "include/LinkedList.hpp"
#include "include/Stack.hpp"
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

	stack.display();
}

int main()
{
	testAckermanFunction(3, 4);

	testStack();

	return 0;
}


