#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;
struct Content {
	string title;
	int number;
};
template <class DataType>
class DoublyLinkedList
{
	typedef LinkedList<DataType>* Node;

private:
	LinkedList<DataType>* list;
	int size = 0;

public:
	// default constructor
	DoublyLinkedList()
	{
		list = new LinkedList<DataType>();
		size++;
	}
	
	// copy constructor
	DoublyLinkedList(DataType value)
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
		list->append(value);
		size++;
	}

	// get the next item
	DoublyLinkedList<DataType>* next()
	{
		DoublyLinkedList<DataType> temp = *this;
		temp.setList(temp.getList()->getNext());
		return &temp;
	}

	// get the previous item
	DoublyLinkedList<DataType>* prev()
	{
		DoublyLinkedList<DataType> temp = *this;
		temp.setList(temp.getList()->getPrevious());
		return &temp;
	}
	
	// remove item
	void remove()
	{
		list->remove();
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
