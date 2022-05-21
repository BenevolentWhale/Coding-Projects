#include <iostream>
using namespace std;

#ifndef BSTNODE_H_
#define BSTNODE_H_

class BSTNode {

public:

	int value, height, subtreeSize;
	BSTNode *left, *right, *parent;

	BSTNode(int val) {
		// each node is inserted as a leaf
		value = val;
		height = subtreeSize = 1;
		left = NULL;
		right = NULL;
		parent = NULL;
	}

	bool isLeaf() {
		return (left == NULL && right == NULL);
	}

	bool hasRightChild() {
		return (right != NULL);
	}

	bool hasLeftChild() {
		return (left != NULL);
	}

	bool isLeftChildOfParent() {
		if (isRoot())
			return false;
		else
			return parent->left == this;
	}

	bool isRoot() {
		return (parent == NULL);
	}

	void toString() {
		if (isRoot())
			cout << "<" << value << ", null>";
		else
			cout << "<" << value << ", " << parent->value << ">";
	}
};

#endif
