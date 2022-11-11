//#include "Iterator.h"
//
//// constructor
//Iterator::Iterator() :fArrayElements(NULL), fLength(10)
//{
//	fIndex = 0;
//}
//
//// constructor
//Iterator::Iterator(const Achievement* aArray, const int aLength, int aStart) : fArrayElements(aArray), fLength(aLength)
//{
//	fIndex = aStart;
//}
//
//// dereference
//const Achievement& Iterator::operator*()
//{
//	return fArrayElements[fIndex];
//}
//
//
//// increment
//Iterator Iterator::operator++(int)
//{
//	Iterator temp = *this;
//	if (fIndex < fLength - 1) fIndex++;
//	return temp;
//}
//
//// decrement
//Iterator Iterator::operator--(int)
//{
//	Iterator temp = *this;
//	if (fIndex > 0) fIndex--;
//	return temp;
//}
//
//// equality
//bool Iterator::operator==(const Iterator& aOther) const
//{
//	return (fIndex == aOther.fIndex) && (fArrayElements == aOther.fArrayElements);
//}
//
//// inequality
//bool Iterator::operator!=(const Iterator& aOther) const
//{
//	return (fArrayElements != aOther.fArrayElements) || (fIndex != aOther.fIndex);
//}
//
//// Iterator object that have been initialized to the beginning of the array
//const Iterator Iterator::begin()
//{
//	return Iterator(fArrayElements, fLength - 1);
//}
//
//// Iterator object that have been initialized to the end of the array
//const Iterator Iterator::end()
//{
//	return Iterator(fArrayElements, fLength, fLength - 1);
//}
//
//// return the array
//const Achievement* Iterator::getArray()
//{
//	return fArrayElements;
//}
//
//// return the index
//int Iterator::getIndex()
//{
//	return fIndex;
//}
//
//// return the length
//const int Iterator::getLength()
//{
//	return fLength;
//}
//
//// show the array
//const Achievement& Iterator::getValue()
//{
//	return fArrayElements[fIndex];
//	//return fArrayElements[fIndex];
//	//std::cout << "iter[" << fIndex << "]" << **this << endl;
//}
