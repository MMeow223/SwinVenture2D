#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class DataType>
class LinkedList
{
public:
	typedef LinkedList<DataType> Node;

protected:
	DataType fValue;
	Node* fNext;
	Node* fPrevious;

public:
	static Node NIL;
	// default constructor
	LinkedList()
	{
		fValue = DataType();
		fNext = &NIL;
		fPrevious = &NIL;
	}
	
	// copy constructor
	LinkedList(DataType value)
	{
		fValue = value;
		fNext = &NIL;
		fPrevious = &NIL;
	}
	
	// prepend node
	void prepend(DataType value)
	{
		LinkedList* newNode = new LinkedList(value);
		newNode->fNext = this;
		newNode->fPrevious = this->fPrevious;
		this->fPrevious->fNext = newNode;
		this->fPrevious = newNode;
	}

	// append node
	void append(DataType value)
	{
		LinkedList* newNode = new LinkedList(value);
		newNode->fNext = this->fNext;
		newNode->fPrevious = this;
		this->fNext->fPrevious = newNode;
		this->fNext = newNode;
	}

	// remove node
	void remove()
	{
		if (fNext == &NIL)
		{
			fPrevious->fNext = &NIL;
		}
		else if (fPrevious == &NIL)
		{
			fNext->fPrevious = &NIL;
		}
		else
		{
			fPrevious->fNext = fNext;
			fNext->fPrevious = fPrevious;
		}
	}

	// get next node
	void setValue(DataType value)
	{
		fValue = value;
	}
	
	// getters
	DataType getValue() {
		return fValue;
	};
	Node* getNext() {
		return fNext;
	};
	Node* getPrevious() {
		return fPrevious;
	};

};

template <class DataType>
LinkedList<DataType> LinkedList<DataType>::NIL;
