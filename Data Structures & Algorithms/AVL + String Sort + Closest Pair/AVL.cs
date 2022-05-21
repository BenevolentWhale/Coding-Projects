using System;
using System.Collections.Generic;

namespace _PA2
{
	public class AVL
	{   // This is an AVL implementation, but does not support deletion :-(

		protected AVLNode root;
		public int size;

		public AVL()
		{
			root = null;
			size = 0;
		}

		public AVLNode search(int key)
		{
			AVLNode tmp = root;
			while (tmp != null)
			{
				if (tmp.value == key)
					return tmp;
				else if (tmp.value > key)
					tmp = tmp.left;
				else
					tmp = tmp.right;
			}
			return null;
		}

		public bool insert(int val)
		{
			if (root == null)
			{
				root = new AVLNode(val);
			}
			else
			{
				AVLNode tmp = root, parent = null;
				AVLNode pred = null, succ = null;
				while (tmp != null)
				{
					if (tmp.value == val)
					{
						return false;
					}
					else if (tmp.value > val)
					{
						succ = parent = tmp;
						tmp = tmp.left;
					}
					else
					{
						pred = parent = tmp;
						tmp = tmp.right;
					}
				}
				AVLNode newNode = new AVLNode(val);
				newNode.parent = parent;
				if (pred != null)
					pred.next = newNode;
				newNode.next = succ;
				if (parent.value > val)
					parent.left = newNode;
				else
					parent.right = newNode;

				while (parent != null)
				{
					rebalance(parent);
					parent = parent.parent;
				}
			}
			size++;
			return true;
		}

		public int getTreeHeight()
		{
			return getHeight(root);
		}

		public AVLNode findMin()
		{
			return findMin(root);
		}

		public AVLNode findMax()
		{
			return findMax(root);
		}

		protected static AVLNode findMin(AVLNode node)
		{
			if (null == node)
				return null;
			while (node.hasLeftChild())
			{
				node = node.left;
			}
			return node;
		}

		protected static AVLNode findMax(AVLNode node)
		{
			if (null == node)
				return null;
			while (node.hasRightChild())
			{
				node = node.right;
			}
			return node;
		}

		protected static int getHeight(AVLNode node)
		{
			if (node == null)
				return 0;
			else
				return node.height;
		}

		protected static int getSubtreeSize(AVLNode node)
		{
			if (node == null)
				return 0;
			else
				return node.subtreeSize;
		}

		private static void setHeightAndSubtreeSize(AVLNode node)
		{
			node.height = 1 + Math.Max(getHeight(node.left), getHeight(node.right));
			node.subtreeSize = 1 + getSubtreeSize(node.left) + getSubtreeSize(node.right);
		}

		private void rotateLeftHelper(AVLNode node)
		{
			AVLNode nodeR = node.right;
			if (!node.isRoot())
			{
				AVLNode nodeParent = node.parent;
				nodeR.parent = nodeParent;
				if (node.isLeftChildOfParent())
					nodeParent.left = nodeR;
				else
					nodeParent.right = nodeR;
			}
			else
			{
				root = nodeR;
				nodeR.parent = null;
			}
			node.right = nodeR.left;
			if (nodeR.left != null)
				nodeR.left.parent = node;
			nodeR.left = node;
			node.parent = nodeR;
			setHeightAndSubtreeSize(node);
			setHeightAndSubtreeSize(nodeR);
		}

		private void rotateRightHelper(AVLNode node)
		{
			AVLNode nodeL = node.left;
			if (!node.isRoot())
			{
				AVLNode nodeParent = node.parent;
				nodeL.parent = nodeParent;
				if (node.isLeftChildOfParent())
					nodeParent.left = nodeL;
				else
					nodeParent.right = nodeL;
			}
			else
			{
				root = nodeL;
				nodeL.parent = null;
			}
			node.left = nodeL.right;
			if (nodeL.right != null)
				nodeL.right.parent = node;
			nodeL.right = node;
			node.parent = nodeL;
			setHeightAndSubtreeSize(node);
			setHeightAndSubtreeSize(nodeL);
		}

		private void rotateLeft(AVLNode node)
		{
			AVLNode nodeR = node.right;
			int heightRL = getHeight(nodeR.left);
			int heightRR = getHeight(nodeR.right);

			if (heightRR <= heightRL)
				rotateRightHelper(node.right); // need to perform double rotation to left
			rotateLeftHelper(node);
		}

		private void rotateRight(AVLNode node)
		{
			AVLNode nodeL = node.left;
			int heightLL = getHeight(nodeL.left);
			int heightLR = getHeight(nodeL.right);

			if (heightLL <= heightLR)
				rotateLeftHelper(node.left); // need to perform double rotation to right
			rotateRightHelper(node);
		}

		private void rebalance(AVLNode node)
		{
			int heightL = getHeight(node.left);
			int heightR = getHeight(node.right);

			if (heightR > heightL + 1)
			{
				rotateLeft(node);
			}
			else if (heightL > heightR + 1)
			{
				rotateRight(node);
			}
			else
			{
				setHeightAndSubtreeSize(node);
			}
		}
	}
}
