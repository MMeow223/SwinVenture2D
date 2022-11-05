#pragma once
#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
using namespace std;

template <class DataType>
class CircularDoublyLinkedList
{
public:
	typedef CircularDoublyLinkedList<DataType> Node;

private:
	DataType fValue;
	Node* fNext;
	Node* fPrevious;
	Node* fStart;
	Node* fEnd;

public:
	static Node NIL;
	// Constructor
	CircularDoublyLinkedList()
	{
		fValue = DataType();
		fNext = &NIL;
		fPrevious = &NIL;
		fStart = &NIL;
		fEnd = &NIL;
	}
	CircularDoublyLinkedList(string contentTitle, int contentNumber)
	{
		Content newValue;
		newValue.title = contentTitle;
		newValue.number = contentNumber;

		fValue = newValue;
		fNext = &NIL;
		fPrevious = &NIL;
		fStart = &NIL;
		fEnd = &NIL;
	}
	void prepend(string contentTitle, int contentNumber)
	{
		CircularDoublyLinkedList* newNode = new CircularDoublyLinkedList(contentTitle, contentNumber);
		newNode->fNext = this;
		newNode->fPrevious = this->fPrevious;
		this->fPrevious->fNext = newNode;
		this->fPrevious = newNode;
	}
	void append(string contentTitle, int contentNumber)
	{
		CircularDoublyLinkedList* newNode = new CircularDoublyLinkedList(contentTitle, contentNumber);

		/*if (this->fPrevious == NIL && this->next == NIL) {
			this->fStart
		}*/

		if (this->fStart == &NIL && this->fPrevious == &NIL) {
			this->fStart = this;
		}

		if (this->fEnd == &NIL && this->fNext == &NIL) {
			this->fEnd = newNode;
		}

		if (this->fEnd == this) {
			this->fNext = this->fStart;
		}
		
		if (this->fStart == this) {
			this->fPrevious = this->fEnd;
		}
		
		this->fStart->fPrevious = this->fEnd;
		this->fEnd->fNext = this->fStart;
		
		newNode->fStart = this->fStart;
		newNode->fEnd = this->fEnd;
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
	Node* getStart() {
		return fStart;
	};
	Node* getEnd() {
		return fEnd;
	};
	
};

template <class DataType>
CircularDoublyLinkedList<DataType> CircularDoublyLinkedList<DataType>::NIL;
