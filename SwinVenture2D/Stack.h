#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

template <class DataType>

class Stack {
private:
	LinkedList<DataType>* stack;
	DataType top_value;
	DataType bottom_value;
	int size = 0;

public:
	Stack() {

		stack = new LinkedList<DataType>();
		top_value = stack->getValue();
		bottom_value = stack->getValue();
		size++;
	};
	Stack(DataType value) {

		stack = new LinkedList<DataType>(value);
		top_value = stack->getValue();
		bottom_value = stack->getValue();
		size++;
	};

	~Stack() {
	};
	void push(DataType value) {
		if (stack == &LinkedList<DataType>::NIL) {
			stack = new LinkedList<DataType>(value);
			top_value = stack->getValue();
			bottom_value = stack->getValue();
		}
		else {
			stack->prepend(value);
			stack = stack->getPrevious();
			top_value = value;
		}
		size++;
		//for (LinkedList<DataType>* i = stack; i != &LinkedList<DataType>::NIL; i = i->getNext()) {
		//	cout << i->getValue() << endl;
		//}
	};
	void pop()
	{
		if (size == 1) {
			stack = &LinkedList<DataType>::NIL;
			top_value = NULL;
			bottom_value = NULL;
		}
		else {
			stack = stack->getNext();
			stack->getPrevious()->remove();
			top_value = stack->getValue();
		}
		size--;
	};
	bool empty() {
		return size == 0;
	};
	int getSize() {
		return size;
	}
	DataType top() {
		if (top_value == NULL) {
			cout << "Error: front is null, returning default" << endl;
			return DataType();
		}
		else
			return top_value;
		//return top_value;
	};
	DataType bottom() {
		if (bottom_value == NULL) {
			cout << "Error: back is null, returning default" << endl;
			return DataType();
		}
		else
			return bottom_value;
		//return bottom_value;
	};
};
