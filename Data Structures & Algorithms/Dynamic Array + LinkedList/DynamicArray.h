#include <iostream>
using namespace std;

#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

class DynamicArray {

    /**
     * Helper function that creates an array tmp[] of size newArrayLen
     * if arrayLen <= newArrayLen, then copies array[] to tmp[]
     * else copies the first newArrayLen elements of array[] into tmp[]
     */
	int *copyArray(int *array, int arrayLen, int newArrayLen) {
		int *tmp = new int[newArrayLen];
		if (arrayLen <= newArrayLen) {
			for (int i = 0; i < arrayLen; i++)
				tmp[i] = array[i];
		} else {
			for (int i = 0; i < newArrayLen; i++)
				tmp[i] = array[i];
		}
		return tmp;
	}

public:
	int *A;
	int numElements;
	int length;

	DynamicArray(int initialSize) {
		numElements = 0;
		length = initialSize;
		A = new int[length];
	}

	int access(int index) {
		if (index >= numElements)
			throw "ArrayIndexOutOfBoundsException";
		return A[index];
	}

	void update(int index, int val) {
		if (index >= numElements)
			throw "ArrayIndexOutOfBoundsException";
		A[index] = val;
	}

	void insertAtEnd(int val) {
		if (numElements == length)
		{
			length = length * 2;
			int *B;
			B = new int[length];
			for (int i = 0; i < numElements; i++)
			{
				B[i] = A[i];
			}
			A = B;
		}
		
		A[numElements] = val;
		numElements++;

	}

	void deleteLast() {
		if (numElements == 0)
		{
			std::cout << "Cannot delete from an empty array";
		}
		else if (numElements == 1)
		{
			numElements = 0;
			length = 1;
			
		}
		else
		{
			numElements--;
			if (4 * numElements == length)
			{
				length = numElements * 2;
				int *B;
				B = new int[length];
				for (int i = 0; i < numElements; i++)
				{
					B[i] = A[i];
				}
				A = B;
			}
		}
	}

	int getSize() {
		return numElements;
	}

	void printArray() {
		if (0 == numElements) {
			cout << "[]";
			return;
		}
		cout << "[";
		for (int i = 0; i < numElements - 1; i++)
			cout << A[i] << ", ";
		cout << A[numElements - 1] << "]";
	}
};



#endif /* DYNAMICARRAY_H_ */
