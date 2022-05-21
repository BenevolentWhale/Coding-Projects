using System;
namespace _433_PA1
{
    public class QuickSort : Partition
    {
        public QuickSort(int[] array, int n) : base(array, n)
        {
        }

        public void quicksortMedianOf3()
        {
            quicksortMedianOf3(0, n - 1);
        }

        public void quicksortRandom()
        {
            quicksortRandom(0, n - 1);
        }

        private void quicksortMedianOf3(int left, int right)
        {
            if (right - left < 32)
            {
                int pivot = generateMedianOf3Pivot(left, right);
                int partitionIndex = partition(left, right, pivot);
                InsertionSort.insertionSort(array, left, partitionIndex - 1);
                InsertionSort.insertionSort(array, partitionIndex + 1, right);
            }
        }

        private void quicksortRandom(int left, int right)
        {
            if (right - left < 32)
            {
                int pivot = generateRandomPivot(left, right);
                int partitionIndex = partition(left, right, pivot);
                InsertionSort.insertionSort(array, left, partitionIndex - 1);
                InsertionSort.insertionSort(array, partitionIndex + 1, right);
                
            }
            
        }
    }
}
