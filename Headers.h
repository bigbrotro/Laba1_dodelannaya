#include <iostream>


template <class ValueType>
class LinkedListNode
{
public:
	LinkedListNode(const ValueType& val)
		: _prev(nullptr), _next(nullptr), _value(val) {}
	LinkedListNode<ValueType>* _prev;
	LinkedListNode<ValueType>* _next;
	ValueType _value;
};

template <class ValueType>
class LinkedList
{



public:
	LinkedList();
	~LinkedList();

	void Clear();
	int Size();
	void Print();
	void PushBack(const ValueType& val);
	ValueType PopBack();
	void PushFront(const ValueType& val);
	ValueType PopFront();
	ValueType At(int index);
	ValueType operator[](int index);
	ValueType RemoveAt(int index);
protected:
	LinkedListNode<ValueType>* _first;
	LinkedListNode<ValueType>* _last;

	int _count;
};


template <class ValueType>
LinkedList<ValueType>::LinkedList()
	: _first(nullptr), _last(nullptr), _count(0) {}


template <class ValueType>
LinkedList<ValueType>::~LinkedList()
{
	this->Clear();
}

template <class ValueType>
void LinkedList<ValueType>::Clear()
{
	LinkedListNode<ValueType>* current = _first;
	while (current != nullptr)
	{
		LinkedListNode<ValueType>* next = current->_next;
		delete current;
		current = next;
	}

	_first = nullptr;
	_last = nullptr;
	_count = 0;
}
template <class ValueType>
int LinkedList<ValueType>::Size()
{
	return _count;
}

template <class ValueType>
void LinkedList<ValueType>::Print()
{
	std::cout << "[" << _count << "]{";

	LinkedListNode<ValueType>* current = _first;
	while (current != nullptr)
	{
		std::cout << current->_value;
		if (current->_next != nullptr)
			std::cout << ", ";
		current = current->_next;
	}

	std::cout << "}" << std::endl;
}
template <class ValueType>
void LinkedList<ValueType>::PushBack(const ValueType& val)
{
	LinkedListNode<ValueType>* newNode = new LinkedListNode<ValueType>(val);
	if (_count == 0)
	{
		_first = newNode;
		_last = newNode;


	}
	else
	{
		newNode->_prev = _last;
		_last->_next = newNode;
		_last = newNode;
	}

	_count++;
}
template <class ValueType>
ValueType LinkedList<ValueType>::PopBack()
{
	if (_count == 0)
		throw std::out_of_range("List is empty");

	ValueType retVal = _last->_value;
	if (_count == 1)
	{
		delete _last;
		_last = nullptr;
		_first = nullptr;
	}
	else
	{
		_last = _last->_prev;
		delete _last->_next;
		_last->_next = nullptr;
	}

	_count--;
	return retVal;
}

template <class ValueType>
void LinkedList<ValueType>::PushFront(const ValueType& val)
{
	LinkedListNode<ValueType>* newNode = new LinkedListNode<ValueType>(val);
	if (_count == 0)
	{
		_first = newNode;
		_last = newNode;


	}
	else
	{
		newNode->_next = _first;
		_first->_prev = newNode;
		_first = newNode;
	}

	_count++;
}
template <class ValueType>
ValueType LinkedList<ValueType>::PopFront()
{
	if (_count == 0)
		throw std::out_of_range("List is empty");

	ValueType retVal = _first->_value;
	if (_count == 1)
	{
		delete _first;
		_first = nullptr;
		_last = nullptr;
	}
	else
	{
		_first = _first->_next;
		delete _first->_prev;
		_first->_prev = nullptr;
	}

	_count--;
	return retVal;
}

template <class ValueType>
ValueType LinkedList<ValueType>::At(int index)
{
	if (index >= _count)
		throw std::out_of_range("List is empty");
	LinkedListNode<ValueType>* current = _first;
	for (int i = 0; i < index; i++)
		current = current->_next;
	return current->_value;
}

template <class ValueType>
ValueType LinkedList<ValueType>::operator[](int index)
{
	if (index >= _count)
		throw std::out_of_range("List is empty");
	LinkedListNode<ValueType>* current = _first;
	for (int i = 0; i < index; i++)
		current = current->_next;
	return current->_value;
}

template <class ValueType>
ValueType LinkedList<ValueType>::RemoveAt(int index)
{
	LinkedListNode<ValueType>* current = _first;
	for (int i = 0; i < index; i++)
		current = current->_next;
	
	ValueType retVal = current->_value;
	if (current == NULL)
	{
		return 0;
	}
	if (current->_prev == NULL) {
		PopFront();

	}

	if (current->_next == NULL) {
		PopBack();

	}
	LinkedListNode<ValueType>* left = current->_prev;
	LinkedListNode<ValueType>* right = current->_next;
	left->_next = right;
	right->_prev = left;
		
	delete current;
	_count--;
	return retVal;
	
}



