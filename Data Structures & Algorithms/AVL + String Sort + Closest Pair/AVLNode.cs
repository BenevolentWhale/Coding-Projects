using System;
namespace _PA2
{
	public class AVLNode
	{
		public int value, height, subtreeSize;
		public AVLNode left, right, parent, next;

		public AVLNode(int val)
		{
			// a node is always inserted as a leaf
			value = val;
			height = subtreeSize = 1;
			left = null;
			right = null;
			parent = null;
			next = null;
		}

		public bool isLeaf()
		{
			return (left == null && right == null);
		}

		public bool hasRightChild()
		{
			return (right != null);
		}

		public bool hasLeftChild()
		{
			return (left != null);
		}

		public bool isLeftChildOfParent()
		{
			if (isRoot())
				return false;
			else
				return parent.left == this;
		}

		public bool isRoot()
		{
			return (parent == null);
		}

		public String toString()
		{
			if (isRoot())
				return "<" + value + ", null>";
			else
			{
				return "<" + value + ", " + parent.value + ">";
			}
		}
	}
}
