using System;
using System.Collections.Generic;
namespace _PA4
{
	public class DynamicProgramming
	{
		public DynamicProgramming()
		{
		}

		public static int numberOfBinaryStringsWithNoConsecutiveOnes(int n)
		{
			int[] zero = new int[n];
			int[] one = new int[n];
			zero[0] = 1;
			one[0] = 1;

			for (int i = 1; i < n; i++)
			{
				zero[i] = zero[i - 1] + one[i - 1];
				one[i] = zero[i - 1];

			}

			return zero[n - 1] + one[n - 1];
		}

		public static List<int> longestIncreasingSubsequence(int[] arr, int len)
		{
			int[] LIS = new int[len];
			int[] PRED = new int[len];
			for (int i = 0; i < len-1; i++)
			{
				LIS[i] = 1;
				PRED[i] = -1;
				int maxIndex = 0;
				if (arr[maxIndex] < arr[i] && arr[i] > arr[i-1])
				{
					maxIndex = i;
				}
				else
				{
					maxIndex = -1;
				}

				if (maxIndex != -1)
				{
					LIS[i] = LIS[maxIndex] + 1;
					PRED[i] = maxIndex;
				}
		
			}
			int lisIndex = 0;
			for (int i = 0; i <LIS.Length; i++)
			{
				if(LIS[i] > lisIndex)
				{
					lisIndex = LIS[i];
				}
			}

			List<int> dynamicArray = new List<int>();
			for (int i = lisIndex; i < PRED.Length; i++)
			{
				dynamicArray.AddRange(longestIncreasingSubsequence(PRED, i));
			}

			reverse(dynamicArray);
			return dynamicArray;

		}

		private static void reverse(List<int> list)
		{
			for (int i = 0, j = list.Count - 1; i < j; i++, j--)
			{
				int temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
	}
}
