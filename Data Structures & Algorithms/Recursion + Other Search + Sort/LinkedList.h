#include "ListNode.h"

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

class LinkedList {

private:

	ListNode *head, *tail;
	int size;
	int *mergedArray;

public:

	LinkedList() {
		head = tail = NULL;
		size = 0;
		mergedArray = NULL;
	}

	void mergesort() {
		mergedArray = new int[size];
		mergesort(0, size - 1, head, tail);
		delete[] mergedArray;
	}

private:

	void mergesort(int left, int right, ListNode *leftNode,
			ListNode *rightNode) {
		if (left>=right)
		{
			return;
		}
		else
		{

		int mid = (left + right) / 2;
		ListNode* midNode = leftNode;
		//loop through list to set midNode to node at mid index
		for (int i = left; i < mid; i++)
		{
			midNode = midNode->next;
		}
		 mergesort(left, mid, leftNode, midNode);
		 mergesort(mid + 1, right, midNode->next, rightNode);
		 int k = left;
		 ListNode* tmp1 = leftNode;
		 ListNode* tmp2 = midNode->next;
		 while (tmp1!=midNode->next && tmp2!=rightNode->next)
		 {
			 if (tmp1->value < tmp2->value)
			 {
				 mergedArray[k++] = tmp1->value;
				 tmp1 = tmp1->next;
			 }
			 else
			 {
				 mergedArray[k++] = tmp2->value;
				 tmp2 = tmp2->next;
			 }
		 }

		 while (tmp1!=midNode->next)
		 {
			 mergedArray[k++] = tmp1->value;
			 tmp1 = tmp1->next;
		 }


		 while (tmp2!=rightNode->next)
		 {
			 mergedArray[k++] = tmp2->value;
			 tmp2 = tmp2->next;
		 }
		 k = left;
		 ListNode* tmp = leftNode;
		 while (tmp != rightNode->next)
		 {
			 tmp->value = mergedArray[k++];
			 tmp = tmp->next;
		 }
	}
		return;
	}

public:

	ListNode *insertAtFront(int value) {
		ListNode *newNode = new ListNode(value);
		if (size == 0) {
			head = tail = newNode;
		} else {
			newNode->next = head;
			head = newNode;
		}
		size++;
		return newNode;
	}

	ListNode *insertAtEnd(int value) {
		ListNode *newNode = new ListNode(value);
		if (size == 0) {
			head = tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		size++;
		return newNode;
	}

	void printList() {
		if (size == 0)
			cout << "[]" << endl;
		else {
			ListNode *tmp = head;
			cout << "[";
			for (int i = 0; i < size - 1; i++) {
				cout << tmp->value << " -> ";
				tmp = tmp->next;
			}
			cout << tail->value << "]" << endl;
		}
	}

	int getSize() {
		return size;
	}
};

#endif /* LINKEDLIST_H_ */
