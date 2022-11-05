#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Content {
	int number;
	string title;
};
template <class DataType>
class DoublyLinkedList
{
public:
	typedef DoublyLinkedList<DataType> Node;

protected:
	DataType fValue;
	Node* fNext;
	Node* fPrevious;

public:
	static Node NIL;
	// Constructor
	DoublyLinkedList()
	{
		fValue = DataType();
		fNext = &NIL;
		fPrevious = &NIL;
	}
	DoublyLinkedList(string contentTitle, int contentNumber)
	{
		Content newValue;
		newValue.title = contentTitle;
		newValue.number = contentNumber;

		fValue = newValue;
		fNext = &NIL;
		fPrevious = &NIL;
	}
	void prepend(string contentTitle, int contentNumber)
	{
		DoublyLinkedList* newNode = new DoublyLinkedList(contentTitle, contentNumber);
		newNode->fNext = this;
		newNode->fPrevious = this->fPrevious;
		this->fPrevious->fNext = newNode;
		this->fPrevious = newNode;
	}
	void append(string contentTitle, int contentNumber)
	{
		DoublyLinkedList* newNode = new DoublyLinkedList(contentTitle, contentNumber);
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
	void setValue(string newSkillName, int newLevel)
	{
		fValue.name = newSkillName;
		fValue.contentNumber = newLevel;
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
DoublyLinkedList<DataType> DoublyLinkedList<DataType>::NIL;
