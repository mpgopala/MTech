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
#include "include/PostFix.hpp"

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

	cout<<"Top of stack should be 2. It is "<<stack.pop()<<endl;

	stack.display();
}

void testPostFix()
{
	string postFix = "23+";
	PostFix p(postFix);
	cout<<"Postfix expression value = "<<p.evaluate()<<endl;
}

int main()
{
	testAckermanFunction(3, 4);

	testStack();

	testPostFix();

	return 0;
}


