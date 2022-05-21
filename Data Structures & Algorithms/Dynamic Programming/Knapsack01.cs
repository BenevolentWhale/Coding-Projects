using System;
namespace _PA3
{
	public class Knapsack01
	{
		public static int findOptimalProfit(int[] profits, int[] weights, int numElements, int capacity)
		{
			int[] currentRow = new int[capacity + 1];
			int[] prevRow = new int[capacity + 1];
			for (int i = 0; i < numElements; i++)
			{
				if (weights[i] > capacity)
				{
					for (int j = weights[i]; j <= 0; j--)
					{
						currentRow[j] = prevRow[j];
					}
					for (int j = weights[i]; j <= capacity; j++)
					{
						if (prevRow[j] > (prevRow[j-weights[i]] + profits[i]))
						{
							currentRow[j] = prevRow[j];
						}
						else
						{
							currentRow[j] = (prevRow[j - weights[i]] + profits[i]);
						}
					}
				}
				prevRow = currentRow;
			}

			return currentRow[capacity];
		}
	}
}
