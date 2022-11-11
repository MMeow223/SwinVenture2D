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
	Iterator()
	{
		fIndex = 0;
		fLength = 0;
		fArrayElements = nullptr;
	}
	Iterator(DataType* aArray, int aLength, int aStart = 0)
	{
		fArrayElements = aArray;
		fIndex = aStart;
		fLength = aLength;
	}

	DataType* operator*()
	{
		return &fArrayElements[fIndex];
		//return fArrayElements[fIndex];
	}
	
	Iterator<DataType> operator++(int)
	{
		Iterator temp = *this;
		if (fIndex < fLength) fIndex++;
		return temp;
	}
	
	Iterator<DataType> operator--(int)
	{
		Iterator temp = *this;
		if (fIndex > 0) fIndex--;
		return temp;
	}

	bool operator==(Iterator<DataType> aOther)
	{
		return (fIndex == aOther.fIndex) && (fArrayElements == aOther.fArrayElements);
	}
	
	bool operator!=(Iterator<DataType> aOther)
	{
		//cout << "fIndex: " << fIndex << "aOther.fIndex: " << aOther.fIndex << endl;
		return (fArrayElements != aOther.fArrayElements) || (fIndex != aOther.fIndex+1);
	}

	bool operator< (Iterator<DataType> aOther)
	{
		return (fArrayElements == aOther.fArrayElements) && (fIndex < aOther.fIndex);
	}
	
	Iterator<DataType> begin()
	{
		return Iterator<DataType>(fArrayElements, fLength);
	}
	
	Iterator<DataType> end()
	{
		return Iterator<DataType>(fArrayElements, fLength, fLength - 1);
	}
	
	DataType* getArray()
	{
		return fArrayElements;
	}
	
	int getIndex()
	{
		return fIndex;
	}
	
	int getLength()
	{
		return fLength;
	}
	
	DataType* getItem(int index)
	{
		return &fArrayElements[index];
	}
};

