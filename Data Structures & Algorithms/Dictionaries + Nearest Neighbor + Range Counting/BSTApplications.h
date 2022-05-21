#include "BST.h"

#ifndef BSTAPPLICATIONS_H_
#define BSTAPPLICATIONS_H_

class BSTApplications: public BST {

public:

	BSTApplications(int A[], int length) {
		root = NULL;
		size = 0;
		for (int i = 0; i < length; i++)
			insertAndSet(A[i]);
	}

	BSTNode *getPredecessor(int key) {
		BSTNode* tmp = root;
		BSTNode* predecessor = NULL;
		while (tmp!=NULL)
		{
			if (tmp->value == key) {
				return tmp;
			} else if (tmp->value < key) {
				predecessor = tmp;
				tmp = tmp->right;
			}
			else {
				tmp = tmp->left;
			}
		}
		return predecessor;
	}

	BSTNode *getSuccessor(int key) {
		//return right node if it exist
		//search(key);
		BSTNode* tmp = search(key);
		//if (tmp->hasRightChild())
		//{
		//	return	search(key)->right;
		//}
		//return null if it doesnt
		//return search(key);
		if (tmp != NULL)
		{
			if (tmp->right)
			{
				return tmp->right;
			}
			else
			{
				return tmp;
			}
		}
		else {
			return NULL;
		}
			
	}

	int nearestNeighbour(int key) {
		BSTNode* predecessor = getPredecessor(key);
		BSTNode* successor = getSuccessor(key);
		//return NULL if there is no nearest neighbor somehow
		if (predecessor == NULL && successor == NULL)
		{
			return NULL;
		}
		if (predecessor == NULL)
		{
			return successor->value;
		}
		if (successor == NULL)
		{
			return predecessor->value;
		}
		//return value closest to key
		if (key - successor->value < key - predecessor->value)
		{
			return successor->value;
		} else {
			return predecessor->value;
		}
	}
    
    BSTNode *getLCA(int x, int y) {
		if (x > y)
		{
			int z = y;
			y = x;
			x = z; 
		}
		BSTNode* tmp = root;
		while (tmp != NULL)
		{
			if (tmp->value < x) {
				tmp = tmp->right;
			}
			else if (tmp->value > y) {
				tmp = tmp->left;
			}
			else
			{
				break;
			}
		}
		
		return tmp;
    }

	int rangeCount(int L, int R) {
		if (L > R)
		{
			return 0;
		}
		//find lca
		BSTNode* LCA = getLCA(L, R);
		if (LCA == NULL)
		{
			return 0;
		}
		if (LCA->value == L && LCA->value == R)
		{
			return 1;
		}
		int counter = 0;
		if (LCA->value > L && LCA->value < R)
		{
			counter = 1;
		} else if (LCA->value == L || LCA->value == R) {
			counter = 1;
		}
		
		if (LCA->value > L){
			BSTNode* tmp = LCA->left;
			while (tmp != NULL){
				if (L == tmp->value)
				{
					counter += getSubtreeSize(tmp->right);
					break;
				}
				if (L < tmp->value)
				{
					counter += getSubtreeSize(tmp->right);
					tmp = tmp->left;
				} else {
					tmp = tmp->right;
				}
			}
		}
		//end of if (LCA->value > L)
		if (LCA->value < R) {
			BSTNode* tmp = LCA->right;
			while (tmp != NULL) {
				if (R == tmp->value)
				{
					counter += getSubtreeSize(tmp->left);
					break;
				}
				if (R < tmp->value)
				{
					counter += getSubtreeSize(tmp->left);
					tmp = tmp->right;
				}
				else {
					tmp = tmp->left;
				}
			}
		}
		return counter;
	}
};

#endif /* BSTAPPLICATIONS_H_ */
