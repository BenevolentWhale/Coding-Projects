using System;
using System.Collections.Generic;

namespace _PA5
{
	public class KMP
	{

		public static List<int> runKMP(String text, String pattern)
		{ // complete this method
			List<int> occ = new List<int>();
			int[] F = computeFailure(pattern);
			int txtLen = text.Length;
			int patLen = pattern.Length;
			int t = 0, p = 0;
			while (t < txtLen)
			{
				if (pattern[p] == text[t])
				{
					if (p == patLen - 1)
					{
						occ.Add(t - p);
						p = F[p];
					}
					else
					{
						p++;
					}
					t++;
				}
				else
				{
					if (p != 0)
					{
						p = F[p - 1];
					}
					else
					{
						t++;
					}
				}
			}


			return occ;
		}

		private static int[] computeFailure(String pattern)
		{
			int patLen = pattern.Length;
			int[] F = new int[patLen];
			int pref = 0, suff = 1;
			F[0] = 0;
			while (suff != patLen)
			{
				if (pattern[suff] == pattern[pref])
				{
					pref++;
					F[suff] = pref;
					suff++;
				}
				else if (pref == 0)
				{
					F[suff] = 0;
					suff++;
				}
				else
				{
					pref = F[pref - 1];
				}
			}

			return F;
		}
	}
}
