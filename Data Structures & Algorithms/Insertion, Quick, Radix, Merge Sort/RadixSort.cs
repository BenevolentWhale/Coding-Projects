using System;
namespace _433_PA1
{
    public class RadixSort
    {
        private readonly int[] array;
        private readonly int n;

        public RadixSort(int[] array, int length)
        {
            this.array = array;
            this.n = length;
        }

        private static void countSortOnDigits(int[] A, int n, int[] digits)
        {
            int[] C = new int[10];
            int[] T = new int[n];

            for (int i = 0; i <= n-1; i++)
            {
                C[digits[i]]++;
            }
            for (int i = 1; i <= 9 ; i++)
            {
                C[i] = C[i - 1] + C[i];
            }
            for (int i = (n-1); i >= 0; i--)
            {
                T[C[digits[i]] - 1] = A[i];
                C[digits[i]]--;
                
            }

            Array.Copy(T, A, n);
        }

        private static void radixSortNonNeg(int[] A, int n)
        {
            //find maximum in array A
            int max = A[0];
            foreach (int val in A)
            {
                if(val > max) { max = val; }
            }
            int M = max;

            int[] digits = new int[n];
            int e = 1;
            while ((M / e) > 0)
            {
                for (int i = 0; i < n-1; i++)
                {
                    digits[i] = ((A[i] / e) % 10);
                    countSortOnDigits(A, n, digits);
                    e = (e * 10);

                }
            }
        }   
	

        public void radixSort()
        { 
            //count number of positive and negative
            int nCount = 0, pCount = 0;

            //foreach (int r in array)
            //{
            //    if (array[r] >= 0) { pCount ++; }
            //    else { nCount ++ ; }
            //}

            for (int i = 0; i < n; i++)
            {
                if (array[i] >= 0) { pCount++; }
                else { nCount++; }
            }

            //create arrays for negative and positive numbers
            int[] NONNEG = new int[pCount];
            int[] NEG = new int[nCount];
            int iN = 0, iP = 0;
            //seperate into arrays
            foreach (var r in array)
            {
                if (r >= 0) 
                { 
                    NONNEG[iP] = r;
                    iP++;
                }
                else 
                {
                    //copy AND negate numbers in negative array
                    NEG[iN] = -r;
                    iN++; 
                }
            }

            //Radix Sort on positive numbers
            radixSortNonNeg(NONNEG, pCount);
            radixSortNonNeg(NEG, nCount);

            //make each member negative after the array has been sorted
            for (int i = 0; i < nCount; i++)
            {
                NEG[i] = -NEG[i];
            }

            //copy negative array into main array from back to front
            int j = 0;
            for (int i = iN-1; i >= 0; i--)
            {
                array[j] = NEG[i];
                j ++; 
            }

            //copy positive array into main array
            int k = 0;
            for (int i = j; j < n; j++)
            {
                array[i] = NONNEG[k];
                k++;
            }





        }
    }
}
