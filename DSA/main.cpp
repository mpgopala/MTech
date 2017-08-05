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
#include "include/Queue.hpp"
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

void testQueue()
{
	string queueStr = "qwerty";

	Queue<char> queue;
	for(size_t i = 0; i < queueStr.length(); i++)
		queue.enque(queueStr[i]);

	cout<<"Queue is ";
	queue.display();
}

void testPostFix()
{
	string postFix = "234*^";
	PostFix p(postFix);
	cout<<"Postfix expression "<<postFix<<". Value = "<<p.evaluate()<<endl;
}

int main()
{
//	testAckermanFunction(3, 4);

//	testStack();

//	testPostFix();

	testQueue();

	return 0;
}


