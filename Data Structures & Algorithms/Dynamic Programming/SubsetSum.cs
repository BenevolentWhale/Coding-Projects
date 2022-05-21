using System;
using System.Collections.Generic;
namespace _PA3
{
    public class SubsetSum
    {
		public static bool isSumPossible(int[] elements, int numElements, int target)
		{
			SortedSet<int> sums = new SortedSet<int>();
			sums.Add(0);
			for (int i = 0; i < numElements; i++)
			{
				int[] values = new int[numElements];
				IEnumerator<int> it = sums.GetEnumerator();
				while (it.MoveNext())
				{
					int currentVal = it.Current;
				}
				for (int j = 0; j < values.Length; j++)
				{
					int val = elements[i] + values[j];
					if (val == target) { return true; }
					else if (val < target)
					{
						sums.Add(val);
					}
				}
			}
			return false;
		}
	}
}
