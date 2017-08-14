/*
 * Node.hpp
 *
 *  Created on: 29-Jul-2017
 *      Author: gsharma
 */

#ifndef NODE_HPP_
#define NODE_HPP_

template <typename T>
class Node
{
public:
	Node(const T &t, Node<T> *nxt = nullptr)
	{
		value = t;
		this->next = nxt;
	}
	T value;
	Node<T> *next;
};

template <typename T>
class BSTNode
{
public:
	BSTNode(const T& t, BSTNode<T> *l = nullptr, BSTNode<T> *r=nullptr):left(l), right(r)
	{
		value = t;
	}
	T value;
	BSTNode<T> *left, *right;
};

#endif /* NODE_HPP_ */
