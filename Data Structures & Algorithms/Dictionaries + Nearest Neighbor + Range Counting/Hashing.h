#include "LinkedList.h"

#ifndef HASHING_H_
#define HASHING_H_

class Hashing {

public:

	int TABLE_SIZE;
	LinkedList* hashTable;

	Hashing(int tableSize) {
		TABLE_SIZE = tableSize;
		
		hashTable = new LinkedList[TABLE_SIZE];
			
	}

	~Hashing() {
		delete hashTable;
	}

	int getHashValue(int val) {
		return (37 * val + 61) % TABLE_SIZE;
	}

	bool search(int key) {

		int hashValue = getHashValue(key);


		ListNode* tmp = hashTable[hashValue].head;
		cout << "[";
		for (int i = 0; i < hashTable[hashValue].size; i++) {
				if (tmp->value == key)
				{
					return true;
				}
				else
				{
					tmp = tmp->next;
				}
			}
			return false;
	}
	

	bool insert(int val) {
		//search to make sure number doesnt already exist
		if (search(val)) {
			//return false if number already exist
			return false;
		} else {
			//insert at end and return true
			hashTable[getHashValue(val)].insertAtEnd(val);
			return true;
		}

	}

	bool remove(int val) {
		
		//return false if list is empty
		if (hashTable[getHashValue(val)].size == 0)
		{
			return false;
		}
		//delete head if val is equal to it
		if (hashTable[getHashValue(val)].head->value == val)
		{
			hashTable[getHashValue(val)].deleteHead();
			return true;
		}

		ListNode* tmp = hashTable[getHashValue(val)].head;
		while (tmp->next != nullptr)
		{
			if (tmp->next->value == val)
			{
				hashTable[getHashValue(val)].deleteAfter(tmp);
				return true;
			}
			tmp = tmp->next;
		}
		return false;
	}

	void printStatistics() {
		int maxSize = hashTable[0].size;
		int minSize = maxSize, total = maxSize;
		for (int i = 1; i < TABLE_SIZE; i++) {
			int size = hashTable[i].size;
			if (size > maxSize)
				maxSize = size;
			else if (size < minSize)
				minSize = size;
			total += size;
		}
		printf(
				"Max length of a chain = %d\nMin length of a chain = %d\nAvg length of chains = %d\n",
				maxSize, minSize, total / TABLE_SIZE);
	}
};

#endif
