/*
 * LinkedList.hpp
 *
 *  Created on: 29-Jul-2017
 *      Author: gsharma
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_


#include "Node.hpp"

template <typename T>
class LinkedList
{
	Node<T> *m_head;
public:
	LinkedList() : m_head(nullptr) {}
	virtual ~LinkedList() {}


	bool isEmpty() { return m_head == nullptr; }

	void insert(const T& t)
	{
		if(m_head == nullptr)
		{
			m_head = new Node<T>(t);
		}
		else
		{
			Node<T> *temp = m_head;
			while(temp && temp->next != nullptr)
			{
				temp = temp->next;
			}

			insert(t, temp->t);
		}
	}

	void insert(const T &t, const T &after)
	{
		Node<T> *temp = new Node<T>(t);

		if(isEmpty())
		{
			m_head = temp;
		}
		else
		{
			Node<T> *iter = m_head;
			while(iter != nullptr && iter->next != nullptr && iter->next->t < t);
			temp->next = iter->next;
			iter->next = temp;
		}
	}

	void remove(const T &t)
	{
		Node<T> *prev = m_head;
		Node<T> *temp = m_head;
		while(temp && temp->next != nullptr)
		{
			if(temp->t == t)
				break;
			temp = temp->next;
		}

		if(temp && temp->t == t)
		{
			if(prev)
				prev->next = temp->next;
			if(m_head == temp)
			{
				m_head = nullptr;
			}

			delete temp;
			temp = nullptr;
		}
	}

};


#endif /* LINKEDLIST_HPP_ */
