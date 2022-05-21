using System;
using System.Collections.Generic;

namespace _PA2
{
	public class StringSorter
	{
		public StringSorter()
		{
		}

		class StringComparator : IComparer<String>
		{
			public int Compare(String arg1, String arg2)
			{
				return arg1.CompareTo(arg2);
			}
		}

		public static void mergeSort(String[] strings, int n)
		{
			MergeSort<String> mgSort = new MergeSort<String>(strings, n);
			mgSort.mergesort(new StringComparator());
		}

		public static void radixSort(String[] strings, int n)
		{

			int M = strings[0].Length;
			//find longest string
			for (int i = 0; i < n; i++)
			{
				if (strings[i].Length > M)
				{
					M = strings[i].Length;
				}
			}
			int[] digits = new int[n];

			//int e = M - 1;
			for (int e = M-1; e > 0; e--)
			{
				for (int i = 0; i <= n-1; i++)
				{
					if (e>= strings[i].Length)
					{
						digits[i] = 0;
					}
					else
					{
						string s = strings[i];
						digits[i] = (int)s[e]-96;

					}
				}
				countSortOnLowerCaseCharacters(strings, n, digits);
				
			}
		}

		private static void countSortOnLowerCaseCharacters(String[] strings, int n, int[] digits)
		{
			int[] C = new int[27];
			string[] T = new string[n];
			for (int i = 0; i <= n-1 ; i++)
			{
				C[digits[i]]++;
			}
			for (int i = 1; i <= 26; i++)
			{
				C[i] = C[i - 1] + C[i];
			}
			for (int i = n-1; i >= 0 ; i--)
			{
				T[C[digits[i]] - 1] = strings[i];
				C[digits[i]]--;
			}

			//copy array
			for (int i = 0; i < n; i++)
			{
				strings[i] = T[i];
			}
			
		}
	}
}
