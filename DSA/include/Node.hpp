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
	Node(const T &t, Node *nxt = nullptr)
	{
		this->t = t;
		this->next = nxt;
	}
	T t;
	Node *next;
};


#endif /* NODE_HPP_ */
