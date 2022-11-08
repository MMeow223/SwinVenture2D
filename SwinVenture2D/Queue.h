#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

template <class DataType>

class Queue{
private:
	LinkedList<DataType>* queue;
	DataType front_value;
	DataType back_value;
	int size = 0;
	
public:
	Queue() {
		
		queue = new LinkedList<DataType>();
		front_value = queue->getValue();
		back_value = queue->getValue();
		size++;
	};
	Queue(DataType value) {

		queue = new LinkedList<DataType>(value);
		front_value = queue->getValue();
		back_value = queue->getValue();
		size++;
	};
	
	~Queue() {
	};
	void push(DataType value) {
		// add at the back
		if (queue == &LinkedList<DataType>::NIL) {
			queue = new LinkedList<DataType>(value);
			front_value = queue->getValue();
			back_value = queue->getValue();
		}
		else {
			
			for (LinkedList<DataType>* i = queue; i != &LinkedList<DataType>::NIL; i = i->getNext()) {
				if (i->getNext() == &LinkedList<DataType>::NIL) {
					i->append(value);
					back_value = value;
					size++;
					break;
				}
			}
		}
	};
	void pop()
	{
		if (size == 1) {
			//delete queue;
			queue = &LinkedList<DataType>::NIL;
			front_value = NULL;
			back_value = NULL;
		}
		else {
			LinkedList<DataType>* temp = queue->getNext();
			front_value = temp->getValue();
			//temp = queue->getNext();
			queue->remove();
			queue = temp;
			//queue = queue->getNext();
		}
			size--;
	};
	bool empty() {
		return size == 0;
	};
	int getSize() {
		return size;
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
