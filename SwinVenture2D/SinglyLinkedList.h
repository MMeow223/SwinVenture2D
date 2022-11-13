#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

template <class DataType>
class SinglyLinkedList
{
	typedef LinkedList<DataType>* Node;

private:
	LinkedList<DataType>* list;
	int size = 0;

public:
	// default constructor
	SinglyLinkedList()
	{
		list = new LinkedList<DataType>();
		size++;
	}
	// copy constructor
	SinglyLinkedList(DataType value)
	{
		list = new LinkedList<DataType>(value);
		size++;
	}

	// prepend by pass value and create in linked list
	void prepend(DataType value)
	{
		list->prepend(value);
		size++;
	}
	
	// append by pass value and create in linked list
	void append(DataType value)
	{
		if (list == &LinkedList<DataType>::NIL) {
			list = new LinkedList<DataType>(value);
		}
		else {

			for (LinkedList<DataType>* i = list; i != &LinkedList<DataType>::NIL; i = i->getNext()) {
				if (i->getNext() == &LinkedList<DataType>::NIL) {
					i->append(value);
					break;
				}
			}
		}
		size++;
	}
	
	// get the next item
	SinglyLinkedList<DataType>* next()
	{
		SinglyLinkedList<DataType> temp = *this;
		temp.setList(temp.getList()->getNext());
		return &temp;
	}

	// remove item
	void remove()
	{
		if (size == 1) {
			list = &LinkedList<DataType>::NIL;
		}
		else {
			LinkedList<DataType>* temp = list->getNext();
			list->remove();
			list = temp;
		}
		size--;
	}

	// getters
	LinkedList<DataType>* getList() {
		return list;
	};
	int getSize() {
		return size;
	};
	
	//setter
	void setList(LinkedList<DataType>* list) {
		this->list = list;
	};
};

