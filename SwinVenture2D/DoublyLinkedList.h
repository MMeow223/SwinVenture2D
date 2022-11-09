#pragma once
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
public:
	typedef LinkedList<DataType>* Node;

private:
	LinkedList<DataType>* list;
	int size = 0;

public:
	//static Node NIL;
	// Constructor
	DoublyLinkedList()
	{
		list = new LinkedList<DataType>();
		size++;
	}
	DoublyLinkedList(DataType value)
	{
		list = new LinkedList<DataType>(value);
		size++;
	}
	//void prepend(DataType value)
	//{
	//	list->prepend(value);
	//}
	void append(DataType value)
	{
		list->append(value);
		size++;
	}
	DoublyLinkedList<DataType>* next()
	{
		DoublyLinkedList<DataType>* temp = this;
		temp->setList(temp->getList()->getNext());
		return temp;
	}
	
	DoublyLinkedList<DataType>* prev()
	{
		DoublyLinkedList<DataType>* temp = this;
		temp->setList(temp->getList()->getPrevious());
		return temp;
	}
	
	void remove()
	{
		list->remove();
		size--;
	}
	
	// getters
	LinkedList<DataType>* getList() {
		return list;
	};
	//setter
	void setList(LinkedList<DataType>* list) {
		this->list = list;
	};
	int getSize() {
		return size;
	};
};

//template <class DataType>
//LinkedList<DataType> LinkedList<DataType>::NIL;
