using System;
namespace _PA3
{
	public class LCS
	{
		public static String compute(String x, String y)
		{
			int lenx = x.Length, leny = y.Length;
			int[,] length = new int[lenx + 1, leny + 1];
			int[,] direction = new int[lenx + 1, leny + 1];

			for (int i = lenx; i >= 0; i--)
			{
				length[i,0] = 0;
				direction[i, 0] = '\0';
			}
			for (int j = leny; j >= 0; j--)
			{
				direction[0,j] = 0;
				direction[0,j] = '\0';
			}

			for (int i = 1; i <= lenx; i++)
			{
				for (int j = 1; j <= leny; j++)
				{
					if (x[i-1] == y[j-1])
					{
						length[i, j] = length[i - 1, j - 1] + 1;
						direction[i, j] = 'D';
					} else if(length[i-1,j] > length[i,j-1]) {
						length[i, j] = length[i - 1, j];
						direction[i, j] = 'L';
					}
					else
					{
						length[i, j] = length[i, j - 1]; ;
						direction[i, j] = 'L';
					}
				}
			}

			string answer = "";
			while (direction[lenx, leny] != '\0')
			{
				if (direction[lenx, leny] == 'D')
				{
					answer += x[lenx - 1];
					lenx--;
					leny--;
				}
				else if (direction[lenx, leny] == 'U')
				{
					lenx--;
				}
				else
				{
					leny--;
				}

			}

			char[] charArray = answer.ToCharArray();
			Array.Reverse(charArray);
			return new string(charArray);

		}
	}
}
