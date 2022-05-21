#include <iostream>
using namespace std;

class BinarySearchApplications {

public:

	int minIndexBinarySearch(int array[], int arrayLength, int key) {
		//returns the minimum index where key appears. If key does not appear, then returns ?1.
		int left = 0, right = arrayLength - 1, minIndex = -1;
		while (left <= right){
			int mid = (left + right) / 2;
			if (array[mid] == key) {
				minIndex = mid;
				right = mid - 1;
			}
			else	if (array[mid] > key) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return minIndex;
	}

	int maxIndexBinarySearch(int array[], int arrayLength, int key) {
		//returns the maximum index where key appears. If key does not appear, then returns ?1.
		int left = 0, right = arrayLength - 1, maxIndex = -1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (array[mid] == key) {
				maxIndex = mid;
				left = mid + 1;
			}
			else	if (array[mid] > key) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return maxIndex;
	}
	

	int countNumberOfKeys(int array[], int arrayLength, int key) {
		// Returns 0 if key is not the in the array, else it returns the number of occurrences of key.
		int max = maxIndexBinarySearch(array, arrayLength, key);
		int min = minIndexBinarySearch(array, arrayLength, key);
		//return difference of max and min to find number of occurences. Add one
		return ((max - min) + 1);
	}

	int predecessor(int array[], int arrayLen, int key) {
		int left = 0, right = arrayLen - 1, predIndex = -1;
		while (left <= right){
			int mid = (left + right) / 2;
			if (array[mid] == key) {
				return array[mid];
			}
			else	if (array[mid] > key) {
				right = mid - 1;
			}
			else {
				predIndex = mid;
				left = mid + 1;
			}
		}
		return predIndex;
	}


};

int main() {

	BinarySearchApplications proj1;
	int A[] = { 1, 1, 3, 7, 9, 14, 14, 14, 14, 14, 14, 18, 27, 39, 39, 39 };
	int length = sizeof(A) / sizeof(int);
	cout << "*** Counting the number of occurrences of key ***" << endl << endl;
	cout << "Number of occurrences of 1 is "
			<< proj1.countNumberOfKeys(A, length, 1) << endl;
	cout << "Number of occurrences of 14 is "
			<< proj1.countNumberOfKeys(A, length, 14) << endl;
	cout << "Number of occurrences of 39 is "
			<< proj1.countNumberOfKeys(A, length, 39) << endl;
	cout << "Number of occurrences of 7 is "
			<< proj1.countNumberOfKeys(A, length, 7) << endl;
	cout << "Number of occurrences of 100 is "
			<< proj1.countNumberOfKeys(A, length, 100) << endl;
	cout << "Number of occurrences of -88 is "
			<< proj1.countNumberOfKeys(A, length, -88) << endl;
	cout << "Number of occurrences of 16 is "
			<< proj1.countNumberOfKeys(A, length, 16) << endl;

	cout << endl << "*** Finding Predecessor ***" << endl << endl;

	int B[] = { 1, 0, 39, 47, 36, 12, 6 };
	for (int i = 0; i < sizeof(B) / sizeof(int); i++) {
		int key = B[i];
		int x = proj1.predecessor(A, length, key);
		if (x >= 0)
			cout << "Predecessor of " << B[i] << " is " << A[x] << endl;
		else
			cout << "Predecessor of " << B[i] << " is not defined." << endl;
	}

	return 0;
}
