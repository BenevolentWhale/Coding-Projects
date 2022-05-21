#include <iostream>
#include <algorithm>
#include "BSTNode.h"
using namespace std;

#ifndef BST_H_
#define BST_H_

class BST {

public:

	BSTNode *root;
	int size;

	BST() {
		root = NULL;
		size = 0;
	}

	BSTNode *search(int key) {
		BSTNode* tmp = root;
		while (tmp != NULL)
		{
			if (tmp->value == key)
			{
				return tmp;
			}
			else if (tmp->value < key){
				tmp = tmp->right;
			}
			else
			{
				tmp = tmp->left;
			}
		}
		return NULL;
	}

private:
    
	BSTNode *insert(int val) {
		//allocate memory for root and return when none exist
		if (size == 0)
		{
			//BSTNode* root = new BSTNode(val);
			root = new BSTNode(val);
			//root = new BSTNode(val);
			size++;
			return root;
		}
		else
		{

			BSTNode* tmp = root;
			BSTNode* parent = NULL;
			

			while (tmp != NULL)
			{


		
				if (tmp->value == val)
				{
				
					return NULL;
				} else if (tmp->value < val)
				{
					
					parent = tmp;
					tmp = tmp->right;
				} else
				{
					
					parent = tmp;
					tmp = tmp->left;
				}
			}//end of while loop



		BSTNode* newNode = new BSTNode(val);
		
		newNode->parent = parent;
		if (parent->value > val)
		{
			parent->left = newNode;
		}
		else
		{
			parent->right = newNode;
		}
			size++;
			// Display tree for testing
			print();
			return newNode;
		
		}
	}
    
public:
    
    bool remove(int val) {
        BSTNode *delNode = search(val);
        if (delNode == NULL) {
            return false;
        } else if (delNode->hasLeftChild() && delNode->hasRightChild()) {
            // CASE 3: delNode has both left and right child
            BSTNode *maxNodeInLeftSubTree = findMax(delNode->left);
            delNode->value = maxNodeInLeftSubTree->value;
            // reduced to case 1 or 2
            return deleteAtMostOneChild(maxNodeInLeftSubTree);
        } else {
            return deleteAtMostOneChild(delNode);
        }
    }

	bool insertAndSet(int val) {
		BSTNode *newNode = insert(val);
		if (NULL == newNode)
			return false;
		while (newNode->parent != NULL) {
			setHeightAndSubtreeSize(newNode);
			newNode = newNode->parent;
		}
		return true;
	}

	static int getHeight(BSTNode *node) {
		if (node == NULL)
			return 0;
		else
			return node->height;
	}

	static int getSubtreeSize(BSTNode *node) {
		if (node == NULL)
			return 0;
		else
			return node->subtreeSize;
	}

	static void setHeightAndSubtreeSize(BSTNode *node) {
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		node->subtreeSize = 1 + getSubtreeSize(node->left)
				+ getSubtreeSize(node->right);
	}

	static BSTNode *findMin(BSTNode *node) {
		if (NULL == node)
			return NULL;
		while (node->hasLeftChild()) {
			node = node->left;
		}
		return node;
	}

	static BSTNode *findMax(BSTNode *node) {
		if (NULL == node)
			return NULL;
		while (node->hasRightChild()) {
			node = node->right;
		}
		return node;
	}

	void print(BSTNode *node) {
		if (NULL != node) {
			node->toString();
			cout << " ";
			print(node->left);
			print(node->right);
		}
	}

	int getTreeHeight() {
		return getHeight(root);
	}

	void print() {
		print(root);
	}

	int getSize() {
		return size;
	}

	BSTNode *findMin() {
		return findMin(root);
	}

	BSTNode *findMax() {
		return findMax(root);
	}

private:

	bool deleteAtMostOneChild(BSTNode *delNode) { // delNode must have at most 1 child
		BSTNode *parentOfDelNode = delNode->parent;
		if (delNode->isRoot()) {
			if (delNode->hasLeftChild()) {
				delNode->left->parent = NULL;
				root = delNode->left;
			} else if (delNode->hasRightChild()) {
				delNode->right->parent = NULL;
				root = delNode->right;
			} else {
				root = NULL;
			}
		} else if (delNode->isLeaf()) {
			// CASE 1: delNode is a leaf node
			if (delNode->isLeftChildOfParent())
				parentOfDelNode->left = NULL;
			else
				parentOfDelNode->right = NULL;
		} else {
			// CASE 2: delNode only has a left or a right child
			BSTNode *correctChild;
			if (delNode->hasLeftChild())
				correctChild = delNode->left;
			else
				correctChild = delNode->right;
			if (delNode->isLeftChildOfParent())
				parentOfDelNode->left = correctChild;
			else
				parentOfDelNode->right = correctChild;
			correctChild->parent = parentOfDelNode;
		}
		while (parentOfDelNode != NULL) {
			setHeightAndSubtreeSize(parentOfDelNode);
			parentOfDelNode = parentOfDelNode->parent;
		}
		delNode = NULL;
		size--;
		return true;
	}
};

#endif
