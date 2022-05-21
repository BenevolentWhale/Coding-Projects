#include "ListNode.h"

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

class LinkedList {

public:

	ListNode *head, *tail;
	int size;

	LinkedList() {
		head = tail = NULL;
		size = 0;
	}

	void insertAfter(ListNode *argNode, int value) {
		ListNode *newNode = new ListNode(value);
		newNode->next = argNode->next;
		argNode->next = newNode;
		if (argNode == tail)
		{
			tail = newNode;
		}
		size++;
	
	}

	void deleteAfter(ListNode *argNode) {
		if (argNode == tail)
		{
			std::cout << "Nothing to delete";
		}
		else if(argNode->next == tail)
		{
			//delete argNode->next;
			tail = argNode;
			size--;
		}
		else {
			ListNode* tmp = argNode->next;
			argNode->next = tmp->next;
			//delete tmp;
			size--;
		}
	
	}

	void selectionSort() {
	 
		ListNode* iNode = head;

		//
		for (iNode; iNode!=NULL  && iNode->next != NULL; iNode=iNode->next)
		{
			ListNode* minNode = iNode;
			ListNode* jNode = iNode->next;

			for (jNode; jNode!=NULL; jNode = jNode->next)
			{
				if (minNode->value > jNode->value) {
					minNode = jNode;
					//jNode = jNode->next;
				}
			}
			//Swap node values
			if (minNode != iNode)
			{
				int val = iNode->value;
				iNode->value = minNode->value;
				minNode->value = val;
				//iNode = iNode->next;
			}
			

		}

	}

	bool removeDuplicatesSorted() {
		//Check to make sure list is in ascending order
		

			ListNode* a = head;
			while (a->next != nullptr)
			{
				if (a->value <= a->next->value) {		
					a = a->next;
					
				}
				else
				{
					//return false if not in ascending order
					return 0;
				}
			}
			
		//Check for duplicates
		 a = head;
		while (a->next != nullptr)
		{
	
			if (a->next != nullptr && a->value != a->next->value) {
			}
			else 
			{	 	
					 deleteAfter(a);	
			}
			a = a->next;

		}
		return 1;
	}

	void pushOddIndexesToTheBack() {
		ListNode* tmp;
		for (int i = 0; i < (size/2)-1; i++)
		{
			//insert value after tail
				tmp = getNodeAt(i);
				insertAtEnd(tmp->next->value);
				deleteAfter(tmp);
			}
	

		}

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

	void deleteHead() {
		if (0 == size) {
			cout << "Cannot delete from an empty list" << endl;
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

	ListNode *getNodeAt(int pos) {
		if (pos < 0 || pos >= size) {
			cout << "No such position exists" << endl;
			return NULL;
		} else {
			ListNode *tmp = head;
			for (int i = 0; i < pos; i++)
				tmp = tmp->next;
			return tmp;
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

#endif /* LINKEDLIST_H_ */
