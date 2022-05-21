#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef HEAP_H
#define HEAP_H

class Heap {

public:

	vector<string> heapArray;

public:

	string getMinimum() {
		return heapArray.at(0);
	}

	void deleteMinimum() {
		heapArray[0] = heapArray[heapArray.size()-1];
		heapArray.pop_back();
		unsigned int currentIndex = 0;
		unsigned int leftIndex = 1;
		unsigned int rightIndex = 2;
		while (leftIndex<heapArray.size())
		{
			string currentKey = heapArray.at(currentIndex);
			string leftKey = heapArray.at(leftIndex);
			if (rightIndex < heapArray.size())
			{
				string rightKey = heapArray.at(rightIndex);
				if (leftKey.compare(currentKey) < 0  && leftKey.compare(rightKey) < 0)
				{
					//string tmp = heapArray.at(currentIndex);
					//heapArray.at(currentIndex) = heapArray.at(leftIndex);
					//heapArray.at(leftIndex) = heapArray.at(currentIndex);
					swap(leftIndex, currentIndex);
					currentIndex = leftIndex;
				}
				else if (rightKey.compare(currentKey) < 0)
				{
					//string tmp = heapArray.at(currentIndex);
					//heapArray.at(currentIndex) = heapArray.at(rightIndex);
					//heapArray.at(rightIndex) = heapArray.at(currentIndex);
					swap(rightIndex, currentIndex);
					currentIndex = rightIndex;

				}
				else
				{
					break;
				}
			}
			else if(leftKey.compare(currentKey) < 0)
			{
				int tmp = currentIndex;
				currentIndex = leftIndex;
				leftIndex = tmp;
				break;
			}
			else
			{
				break;
			}

			leftIndex = (2 * (currentIndex + 1));
			rightIndex = (leftIndex + 1);
		}
	}

	void insert(string &value) {
		int currentIndex = heapArray.size();
		int parentIndex = (currentIndex - 1) / 2;
		heapArray.push_back(value);
		while(currentIndex > 0 && parentIndex > currentIndex)
		{
			string tmp = heapArray.at(parentIndex);
			heapArray.at(parentIndex) = heapArray.at(currentIndex);
			heapArray.at(currentIndex) = tmp;
			currentIndex = parentIndex;
			parentIndex = (currentIndex - 1) / 2;
		}
	}

	int size() {
		return heapArray.size();
	}

private:

	void swap(int index1, int index2) {
		string temp = heapArray.at(index1);
		heapArray.at(index1) = heapArray.at(index2);
		heapArray.at(index2) = temp;
	}
};

#endif
