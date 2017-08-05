/*
 * Queue.hpp
 *
 *  Created on: 30-Jul-2017
 *      Author: gsharma
 */

#ifndef INCLUDE_QUEUE_HPP_
#define INCLUDE_QUEUE_HPP_

#include <vector>

template <typename T>
class Queue
{
	std::vector<T> v;
public:
	Queue()
	{}

	virtual ~Queue() {}

	void enque(const T &t)
	{
		v.push_back(t);
	}

	const T deque()
	{
		T retVal;
		if(!v.empty())
		{
			retVal = v.back();
			v.pop_back();
		}
		return retVal;
	}

	void display()
	{
		if(v.empty())
			return;

		for(size_t i = 0; i < v.size(); i++)
			print(v[i]);
	}
};


#endif /* INCLUDE_QUEUE_HPP_ */
