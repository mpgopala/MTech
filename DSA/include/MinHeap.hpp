/*
 * MinHeap.hpp
 *
 *  Created on: 04-Oct-2017
 *      Author: gsharma
 */

#ifndef INCLUDE_MINHEAP_HPP_
#define INCLUDE_MINHEAP_HPP_

#include "vector"
using namespace std;

template <typename T>
class MinHeap
{
private:
    vector<T> _vector;


	void heapify()
	{
		int length = _vector.size();
		for(int i=length-1; i>=0; --i)
		{
			bubbleDown(i);
		}
	}

	void bubbleDown(int index)
	{
		int length = _vector.size();
		int leftChildIndex = 2*index + 1;
		int rightChildIndex = 2*index + 2;

		if(leftChildIndex >= length)
			return; //index is a leaf

		int minIndex = index;

		if(_vector[index] > _vector[leftChildIndex])
		{
			minIndex = leftChildIndex;
		}

		if((rightChildIndex < length) && (_vector[minIndex] > _vector[rightChildIndex]))
		{
			minIndex = rightChildIndex;
		}

		if(minIndex != index)
		{
			//need to swap
			int temp = _vector[index];
			_vector[index] = _vector[minIndex];
			_vector[minIndex] = temp;
			bubbleDown(minIndex);
		}
	}

	void bubbleUp(int index)
	{
		if(index == 0)
			return;

		int parentIndex = (index-1)/2;

		if(_vector[parentIndex] > _vector[index])
		{
			int temp = _vector[parentIndex];
			_vector[parentIndex] = _vector[index];
			_vector[index] = temp;
			bubbleUp(parentIndex);
		}
	}

public:
    MinHeap(T* array, int length) : _vector(length)
	{
		for(int i = 0; i < length; ++i)
		{
			_vector[i] = array[i];
		}

		heapify();
	}

	MinHeap(const vector<T>& vector) : _vector(vector)
	{
		heapify();
	}

	MinHeap()
	{
	}

	void insert(const T &newValue)
	{
		int length = _vector.size();
		_vector[length] = newValue;

		bubbleUp(length);
	}

	const T & getMin()
	{
		return _vector[0];
	}

	void deleteMin()
	{
		int length = _vector.size();

		if(length == 0)
		{
			return;
		}

		_vector[0] = _vector[length-1];
		_vector.pop_back();

		bubbleDown(0);
	}
};

#endif /* INCLUDE_MINHEAP_HPP_ */
