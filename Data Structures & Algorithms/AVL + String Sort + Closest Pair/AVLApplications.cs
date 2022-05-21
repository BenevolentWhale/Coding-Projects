using System;
using System.Collections.Generic;

namespace _PA2
{
    public class AVLApplications : AVL
    {
		public AVLApplications(int[] A)
		{
			for (int a = 0; a < A.Length; a++)
				insert(A[a]);
		}

		public int rank(int key)
		{ 
			AVLNode tmp = root;
			int rank = 0;
			while (tmp!=null)
			{
				if (key >= tmp.value)
				{
					
						rank += (1 + getSubtreeSize(tmp.left));
						tmp = tmp.right;			
				}
				else
				{
						tmp = tmp.left;	
				}
			}
			return rank;
		}

		public int select(int k)
		{ 
			AVLNode tmp = root;
			do
			{
				if (k == 1 + getSubtreeSize(tmp.left))
				{
					return tmp.value;
				}
				else if (k <= getSubtreeSize(tmp.left))
				{
					tmp = tmp.left;
				}
				else
				{
					k -= (1 + getSubtreeSize(tmp.left));
					tmp = tmp.right;
				}
			} while (tmp != null);
	
			return -1;
		}

		public List<int> sortedRangeReporting(int L, int R)
		{ 
			AVLNode successor = getSuccessor(L);
			List<int> array = new List<int>();
			while (successor != null && successor.value <= R)
			{
				array.Add(successor.value);
				successor = successor.next;
			}
			return array;
		}

		public AVLNode getPredecessor(int key)
		{
			AVLNode tmp = root;
			AVLNode pred = null;
			while (tmp != null)
			{
				if (tmp.value == key)
					return tmp;
				else if (tmp.value < key)
				{
					pred = tmp;
					tmp = tmp.right;
				}
				else
				{
					tmp = tmp.left;
				}
			}
			return pred;
		}

		public AVLNode getSuccessor(int key)
		{
			AVLNode tmp = root;
			AVLNode succ = null;
			while (tmp != null)
			{
				if (tmp.value == key)
					return tmp;
				else if (tmp.value > key)
				{
					succ = tmp;
					tmp = tmp.left;
				}
				else
				{
					tmp = tmp.right;
				}
			}
			return succ;
		}
	}
}
