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
	// Constructor
	LinkedList()
	{
		fValue = DataType();
		fNext = &NIL;
		fPrevious = &NIL;
	}
	LinkedList(DataType value)
	{
		fValue = value;
		fNext = &NIL;
		fPrevious = &NIL;
	}
	void prepend(DataType value)
	{
		LinkedList* newNode = new LinkedList(value);
		newNode->fNext = this;
		newNode->fPrevious = this->fPrevious;
		this->fPrevious->fNext = newNode;
		this->fPrevious = newNode;
	}
	void append(DataType value)
	{
		LinkedList* newNode = new LinkedList(value);
		newNode->fNext = this->fNext;
		newNode->fPrevious = this;
		this->fNext->fPrevious = newNode;
		this->fNext = newNode;
	}
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
			fPrevious->fNext = fNext;	  // previous->next
			fNext->fPrevious = fPrevious; // previous<-next
		}
	}
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
