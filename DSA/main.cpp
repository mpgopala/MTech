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
#include "include/BinarySearchTree.hpp"
#include "include/AVLTree.hpp"

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

void testBST()
{
	vector<int> v = {3,5,4,2,6,8,7,9};
	BinarySearchTree<int> bst;
	for(int i : v)
	{
		bst.insert(i);
		print(bst.height());
	}

	print("\nHeight = ");
	print(bst.height());

	print("\nInOrder: ");
	bst.inOrder();

	print("\nPreOrder: ");
	bst.preOrder();

	print("\nPostOrder: ");
	bst.postOrder();
}

void testAVLTree()
{
	vector<int> v = {3,5,4,2,6,8,7,9};
	AVLTree<int> tree;
	for(int i : v)
	{
		tree.insert(i);
		print(tree.height());
	}

	print("\nHeight = ");
	print(tree.height());

	print("\nInOrder: ");
	tree.inOrder();

	print("\nPreOrder: ");
	tree.preOrder();

	print("\nPostOrder: ");
	tree.postOrder();
}

int main()
{
//	testAckermanFunction(3, 4);

//	testStack();

//	testPostFix();

//	testQueue();

	testBST();

	cout<<endl;
	testAVLTree();
	return 0;
}


