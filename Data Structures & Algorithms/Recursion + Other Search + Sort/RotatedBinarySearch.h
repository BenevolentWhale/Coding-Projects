#ifndef ROTATEDBINARYSEARCH_H_
#define ROTATEDBINARYSEARCH_H_

class RotatedBinarySearch {

public:

	static int search(int *array, int length, int key) {

		int maxInd = maxIndex(array, array[length-1], 0, length);
		if (key==array[maxInd])
		{
			return maxInd;
		}
		if (key >= array[0])
		{
			return binarySearch(array, 0, maxInd - 1, key);
		}
		else
		{
			//return index found by binary search
			return	binarySearch(array, maxInd + 1, length - 1, key);
		}
	}

	static int maxIndex(int *array, int lastValue, int left, int right) {
		if (left == right)
		{
			return left;
		}
		int mid = (left + right) / 2;
		if (array[mid] > array[mid+1])
		{
			//maximum is at mid
			return mid;
		}
		else if (array[mid] < array[lastValue])
		{
			//value lies to the left of mid
			return maxIndex(array, lastValue, left, mid - 1);
		}
		else
		{
			//max value lies to right of mid
			return maxIndex(array, lastValue, mid + 1, right);
		}

	}

	static int binarySearch(int *array, int left, int right, int key) {
		if (left <= right) {
			int mid = (left + right) / 2;
			if (array[mid] == key) {
				return mid;
			} else if (array[mid] < key)
				return binarySearch(array, mid + 1, right, key);
			else
				return binarySearch(array, left, mid - 1, key);
		}
		return -1;
	}
};

#endif /* ROTATEDBINARYSEARCH_H_ */
