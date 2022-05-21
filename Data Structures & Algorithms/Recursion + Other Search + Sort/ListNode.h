#include <iostream>
using namespace std;

#ifndef LISTNODE_H_
#define LISTNODE_H_

class ListNode {

public:

	int value;
	ListNode *next;

	ListNode(int val) {
		value = val;
		next = nullptr;
	}
};

#endif /* LISTNODE_H_ */
