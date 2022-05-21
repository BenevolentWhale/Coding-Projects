#include <iostream>
using namespace std;

class Sorting {

public:

	void selectionSort(int array[], int arrayLen) { 
		int minIndex = 0, tmp;
		for (int i = 0; i < arrayLen-2; i++)
		{
			minIndex = i;
			for (int j = 0; j < arrayLen -1; j++)
			{
				if (array[j]< array[minIndex])
				{
					minIndex = j;
				}
			}
			if (minIndex != i)
			{
				tmp = array[i];
				array[i] = array[minIndex];
				array[minIndex] = tmp;
			}
		}
	}

	void insertionSort(int array[], int arrayLen) { 
		int j, tmp;
		for (int i =1; i < arrayLen; i++)
		{
			j = i; 
			tmp = array[j];
			while (j > 0 && tmp < array[j - 1])
			{
				
				array[j] = array[j - 1];
				j--;
				array[j] = tmp;
			}
			
		}
	}

	void printArray(int A[], int length) {
		cout << "[";
		for (int i = 0; i < length - 1; i++)
			cout << A[i] << ", ";
		cout << A[length - 1] << "]";
	}
};

int main() {
	Sorting sortObj;
	int A[] = { 13, 17, 8, 14, 1 };
	int lenA = sizeof(A) / sizeof(int);
	cout << "Original Array: ";
	sortObj.printArray(A, lenA);
	sortObj.selectionSort(A, lenA);
	cout << endl << "Selection Sorted Array: ";
	sortObj.printArray(A, lenA);

	cout << endl << endl;

	int B[] = { -13, -17, -8, -14, -1, -20 };
	int lenB = sizeof(B) / sizeof(int);
	cout << "Original Array: ";
	sortObj.printArray(B, lenB);
	sortObj.insertionSort(B, lenB);
	cout << endl << "Insertion Sorted Array: ";
	sortObj.printArray(B, lenB);

	return 1;
}
