#pragma once

#include "Headers.h"

template <class ValueType>
class Stack
{
public:
	Stack();
	~Stack();
	void Clear();
	int Size();
	void Print();
	void Push(const ValueType& val);
	ValueType Pop();

protected:
	LinkedList<ValueType> _list;
};



template <class ValueType>
Stack<ValueType>::Stack()
{
}

template <class ValueType>
Stack<ValueType>::~Stack()
{
	this->Clear();
}

template <class ValueType>
void Stack<ValueType>::Clear()
{
	_list.Clear();
}

template <class ValueType>
int Stack<ValueType>::Size()
{
	return _list.Size();
}

template <class ValueType>
void Stack<ValueType>::Print()
{
	_list.Print();
}

template <class ValueType>
void Stack<ValueType>::Push(const ValueType& val)
{
	_list.PushBack(val);
}

template <class ValueType>
ValueType Stack<ValueType>::Pop()
{
	return _list.PopBack();
}
