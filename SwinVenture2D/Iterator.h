#pragma once
#include <iostream>
#include <string>
#include "Achievement.h"
using namespace std;
template <class DataType>
class Iterator
{

protected:
	DataType* fArrayElements;
	int fLength;
	int fIndex;

public:
	// default constructor
	Iterator()
	{
		fIndex = 0;
		fLength = 0;
		fArrayElements = nullptr;
	}
	
	// copy constructor
	Iterator(DataType* aArray, int aLength, int aStart = 0)
	{
		fArrayElements = aArray;
		fIndex = aStart;
		fLength = aLength;
	}

	// dereference
	DataType* operator*()
	{
		return &fArrayElements[fIndex];
	}
	
	// increment
	Iterator<DataType> operator++(int)
	{
		Iterator temp = *this;
		if (fIndex < fLength) fIndex++;
		return temp;
	}
	
	// decrement
	Iterator<DataType> operator--(int)
	{
		Iterator temp = *this;
		if (fIndex > 0) fIndex--;
		return temp;
	}

	// compare equal
	bool operator==(Iterator<DataType> aOther)
	{
		return (fIndex == aOther.fIndex) && (fArrayElements == aOther.fArrayElements);
	}
	
	// compare inequal
	bool operator!=(Iterator<DataType> aOther)
	{
		return (fArrayElements != aOther.fArrayElements) || (fIndex != aOther.fIndex+1);
	}

	// return begin
	Iterator<DataType> begin()
	{
		return Iterator<DataType>(fArrayElements, fLength);
	}
	
	// return end
	Iterator<DataType> end()
	{
		return Iterator<DataType>(fArrayElements, fLength, fLength - 1);
	}
	
	// return array
	DataType* getArray()
	{
		return fArrayElements;
	}
	
	// return index
	int getIndex()
	{
		return fIndex;
	}
	
	// return length
	int getLength()
	{
		return fLength;
	}
	
	// return current item
	DataType* getItem(int index)
	{
		return &fArrayElements[index];
	}
};

