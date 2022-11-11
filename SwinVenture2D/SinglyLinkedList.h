#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

template <class DataType>

class SinglyLinkedList {
private:
	LinkedList<DataType>* list;
	DataType front_value;
	DataType back_value;
	int size = 0;

public:
	SinglyLinkedList() {

		list = new LinkedList<DataType>();
		front_value = list->getValue();
		back_value = list->getValue();
		size++;
	};
	SinglyLinkedList(DataType value) {

		list = new LinkedList<DataType>(value);
		front_value = list->getValue();
		back_value = list->getValue();
		size++;
	};

	~SinglyLinkedList() {
	};
	
	void pushFront(DataType value) {
		// add at the back
		if (list == &LinkedList<DataType>::NIL) {
			list = new LinkedList<DataType>(value);
			front_value = list->getValue();
			back_value = list->getValue();
		}
		else {

			for (LinkedList<DataType>* i = list; i != &LinkedList<DataType>::NIL; i = i->getNext()) {
				if (i->getNext() == &LinkedList<DataType>::NIL) {
					i->append(value);
					back_value = value;
					size++;
					break;
				}
			}
		}
	};
	void popFront()
	{
		if (size == 1) {
			//delete queue;
			list = &LinkedList<DataType>::NIL;
			front_value = NULL;
			back_value = NULL;
		}
		else {
			LinkedList<DataType>* temp = list->getNext();
			front_value = temp->getValue();
			//temp = queue->getNext();
			list->remove();
			list = temp;
			//queue = queue->getNext();
		}
		size--;
	};

	void pushBack(DataType value) {
		
		if (list == &LinkedList<DataType>::NIL) {
			list = new LinkedList<DataType>(value);
			front_value = list->getValue();
			back_value = list->getValue();
		}
		else {
			list->prepend(value);
			list = list->getPrevious();
			front_value = value;
		}
		size++;
	};
	void popBack()
	{
		if (size == 1) {
			//delete queue;
			list = &LinkedList<DataType>::NIL;
			front_value = NULL;
			back_value = NULL;
		}
		else {
			LinkedList<DataType>* temp = list->getNext();
			front_value = temp->getValue();
			//temp = queue->getNext();
			list->remove();
			list = temp;
			//queue = queue->getNext();
		}
		size--;
	};

	void prepend(DataType value) 
	{
		list->prepend(value);
	}
	
	void append(DataType value) 
	{
		list->append(value);
	}

	void remove() {
		list->remove();
	}
	
	bool empty() {
		return size == 0;
	};
	int getSize() {
		return size;
	}
	
	SinglyLinkedList<DataType>* next() {
		SinglyLinkedList<DataType> temp = *this;
		temp.list = list->getNext();
		return &temp;
	}
	
	DataType getValue() {
		return list->getValue();
	}
	DataType front() {
		if (front_value == NULL) {
			cout << "Error: front is null, returning default" << endl;
			return DataType();
		}
		else
			return front_value;
		//return front_value;
	};
	DataType back() {
		if (back_value == NULL) {
			cout << "Error: back is null, returning default" << endl;
			return DataType();
		}
		else
			return back_value;
		//return back_value;
	};
};



//#pragma once
//#include <iostream>
//#include <string>
//#include "LinkedList.h"
//using namespace std;
//
//template <class DataType>
//class SinglyLinkedList
//{
//	typedef LinkedList<DataType>* Node;
//
//private:
//	LinkedList<DataType>* list;
//	int size = 0;
//
//public:
//	//static Node NIL;
//	// Constructor
//	SinglyLinkedList()
//	{
//		list = new LinkedList<DataType>();
//		size++;
//	}
//	SinglyLinkedList(DataType value)
//	{
//		list = new LinkedList<DataType>(value);
//		size++;
//	}
//	void prepend(DataType value)
//	{
//		list->prepend(value);
//		size++;
//	}
//	void append(DataType value)
//	{
//		list->append(value);
//		size++;
//	}
//	SinglyLinkedList<DataType>* next()
//	{
//		SinglyLinkedList<DataType>* temp = this;
//		temp->setList(temp->getList()->getNext());
//		return temp;
//	}
//
//
//	void remove()
//	{
//		list->remove();
//		size--;
//	}
//
//	// getters
//	LinkedList<DataType>* getList() {
//		return list;
//	};
//	//setter
//	void setList(LinkedList<DataType>* list) {
//		this->list = list;
//	};
//	int getSize() {
//		return size;
//	};
//};

//template <class DataType>
//LinkedList<DataType> LinkedList<DataType>::NIL;
