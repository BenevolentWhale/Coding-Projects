#include <iostream>
#include <vector>
using namespace std;

#ifndef MERGESORTANDFRIENDS_H_
#define MERGESORTANDFRIENDS_H_

class MergeSortAndFriends {

private:

	static int *binaryMerge(int *A, int *B, int lenA, int lenB) {
	//length of merged array
		 int lenC = lenA + lenB;
		int *C = new int[lenC];
		int a = 0; int b = 0; int c = 0;
		do {
			if (A[a]<B[b])	{
				C[c] = A[a];
				a++;
			}
			else {
				C[c] = B[b];
				b++;
			}
			c++;
		 } while (a < lenA && b < lenB);

		 do {
			 C[c] = A[a];
			 a++;
			 c++;
		 } while (a < lenA);

		 do {
			 C[c] = B[b];

			 b++;
			 c++;
		 } while (b < lenB);
		 return C;
	}

public:

	static vector<int> commonElements(int *A, int *B, int lenA, int lenB) {
		vector<int> CE;
		int a = 0;
		int b = 0;
		while (a<lenA && b<lenB)
		{
			if (A[a] < B[b]){
				a++;
			}
			else if (A[a] > B[b]){
				b++;
			} else {
				//add A[a] to vector
				CE.push_back(A[a]);
				a++;
				while (a<lenA && A[a] == B[b])
				{
					a++;
				}
			}
		}
		return CE;
	}

	static int *kWayMerge(int **lists, int *listLengths, int k) {
		//base case
		if (k==1)
		{
			//return first row of jagged array
			return lists[0];
		}
		if (k==2)
		{
			//there are two arrays, merge them using merge sort
			binaryMerge(lists[0], lists[1], listLengths[0], listLengths[1]);
		} 
		//recursive rule
		int newK = (k + 1) / 2;
		int **mergedLists = new int*[newK];
		int *mergedListsLengths = new int[newK];
		for (int i = 0; i <= ((k / 2) - 1); i++)
		{
			mergedListsLengths[i] = (listLengths[2 * i] + listLengths[(2 * i) + 1]);
			mergedLists[i] = binaryMerge(lists[2 * i], lists[(2 * i) + 1], listLengths[2 * i], listLengths[(2 * i) + 1]);
		}

		//if k is odd, the last row doesnt have a pair to be merged with
		if (k%2!=0)
		{
			mergedLists[newK - 1] = lists[k - 1];
			mergedListsLengths[newK - 1] = listLengths[k - 1];
		}
		
		//return *kWayMerge(mergedLists, mergedListsLengths, newK);
		return kWayMerge(mergedLists, mergedListsLengths, newK);
	}

	static void mergesort(int *array, int left, int right) {
		if (left < right) {
			int mid = (left + right) / 2;
			mergesort(array, left, mid);
			mergesort(array, mid + 1, right);
			int *mergedArray = binaryMerge(&array[left], &array[mid + 1],
					mid - left + 1, right - mid);
			int i = left;
			int j = 0;
			while (j <= right - left)
				array[i++] = mergedArray[j++];
			//delete[] mergedArray;
		}
	}
};

#endif /* MERGESORTANDFRIENDS_H_ */
