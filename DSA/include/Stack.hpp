/*
 * Stack.hpp
 *
 *  Created on: 29-Jul-2017
 *      Author: gsharma
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include "../include/Exception.hpp"
#include "../include/Node.hpp"

template <typename T>
class Stack
{
	Node<T> *m_top = nullptr;

public:
	Stack() : m_top(nullptr) {}
	virtual ~Stack() {}

	bool isEmpty() const { return m_top == nullptr; }
	void push(const T &t)
	{
		Node<T> *temp = new Node<T>(t);
		if(isEmpty())
			m_top = temp;
		else
		{
			temp->next = m_top;
			m_top = temp;
		}
	}

	void pop()
	{
		if(isEmpty())
			return;

		Node<T> *temp = m_top;
		m_top = m_top->next;
		delete temp;
		temp = nullptr;
	}

	const T top()
	{
		if(isEmpty())
			throw new Exception();
		return m_top->t;
	}

	void display() const
	{
		if(isEmpty())
			return;

		for(Node<T> *temp = m_top; temp != nullptr; temp = temp->next)
		{
			print(temp->t);
		}
	}
};

#endif /* STACK_HPP_ */
