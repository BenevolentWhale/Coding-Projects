using System;
namespace _433_PA1
{
    public class MergeSort
    {

        private readonly int[] array;
        private readonly int[] mergedArray;
        private readonly int n;

        public MergeSort(int[] array, int n)
        {
            this.array = array;
            this.n = n;
            this.mergedArray = new int[n];
        }

        public void mergesort()
        {
            mergesort(0, n - 1);
        }

        private void mergesort(int left, int right)
        {
            if (right - left < 31)
            {
                InsertionSort.insertionSort(array, left, right);
                return;
            }
            int mid = (left + right) / 2;
            mergesort(left, mid);
            mergesort(mid + 1, right);
            int i = left, j = mid + 1, k = left;
            while (i <= mid && j <= right)
            {
                if (array[j] < array[i])
                {
                    mergedArray[k++] = array[j++];
                }
                else
                {
                    mergedArray[k++] = array[i++];
                }
            }
            while (i <= mid)
            {
                mergedArray[k++] = array[i++];
            }
            while (j <= right)
            {
                mergedArray[k++] = array[j++];
            }
            i = left;
            j = 0;
            while (j++ <= right - left)
                array[i] = mergedArray[i++];
        }
    }
}
