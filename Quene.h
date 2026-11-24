#pragma once

#include "Headers.h"

template <class ValueType>
class Queue
{
public:
	Queue();
	~Queue();
	void Clear();
	int Size();
	void Print();
	void Push(const ValueType & val);
	ValueType Pop();

protected:
	LinkedList<ValueType> _list;
};


template <class ValueType>
Queue<ValueType>::Queue()
{
}

template <class ValueType>
Queue<ValueType>::~Queue()
{
	this->Clear();
}

template <class ValueType>
void Queue<ValueType>::Clear()
{
	_list.Clear();
}

template <class ValueType>
int Queue<ValueType>::Size()
{
	return _list.Size();
}

template <class ValueType>
void Queue<ValueType>::Print()

{
	_list.Print();
}

template <class ValueType>
void Queue<ValueType>::Push(const ValueType& val)
{
	_list.PushBack(val);
}

template <class ValueType>
ValueType Queue<ValueType>::Pop()
{
	return _list.PopFront();
}
