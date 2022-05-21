#include <iostream>
using namespace std;

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

class ListNode {

public:

	int value;
	ListNode *next;

	ListNode(int val) {
		value = val;
		next = NULL;
	}
};

class LinkedList {

public:

	ListNode *head, *tail;
	int size;

	LinkedList() {
		head = tail = NULL;
		size = 0;
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

	void deleteHead() {
		if (0 == size) {
			cout << "Cannot delete from an empty list." << endl;
		} else if (1 == size) {
			size--;
			delete head;
		} else {
			size--;
			ListNode *tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	void deleteAfter(ListNode *argNode) {
		if (0 == size) {
			cout << "Cannot delete from an empty list." << endl;
		}
		else if (1 == size) {
			size--;
			delete head;
		}
		else {
			size--;
			ListNode* tmp = head;
			head = head->next;
			delete tmp;
		}

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

#endif
