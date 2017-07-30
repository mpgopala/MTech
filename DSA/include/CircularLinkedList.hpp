#ifndef _CIRCULAR_LINKED_LIST_HPP_
#define _CIRCULAR_LINKED_LIST_HPP_

#include "Node.hpp"

template <class T>
class CircularLinkedList
{
	Node<T> * m_head;
public:
	CircularLinkedList() : m_head(nullptr) {}
	virtual ~CircularLinkedList() {}

	bool isEmpty() const { return m_head == nullptr; }

	void insert(const T& t)
	{
		Node<T> *temp = m_head;
		while(temp && temp->next != m_head)
		{
			temp = temp->next;
		}

		insert(t, temp->t);
	}

	void insert(const T &t, const T &after)
	{
		Node<T> *temp = new Node<T>(t);

		if(isEmpty())
		{
			temp->next = temp;
			m_head = temp;
		}
		else
		{
			Node<T> *iter = m_head;
			while(iter->next->t < t && iter->next != m_head);
			temp->next = iter->next;
			iter->next = temp;
		}
	}

	void remove(const T &t)
	{
		Node<T> *prev = m_head;
		Node<T> *temp = m_head;
		while(temp && temp->next != m_head)
		{
			if(temp->t == t)
				break;

			temp = temp->next;
		}

		if(temp->t == t)
		{
			prev->next = temp->next;
			if(m_head == temp)
			{
				m_head = nullptr;
			}

			delete temp;
			temp = nullptr;
		}
	}

	void display() const
	{
		if(isEmpty())
			return;

		Node<T> *temp = m_head;
		do
		{
			print(temp->t);
			temp = temp->next;
		}while(temp != m_head);
	}
};

#endif //_CIRCULAR_LINKED_LIST_HPP_
