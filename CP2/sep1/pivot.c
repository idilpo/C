#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
  int n, i, j, val;
  int arr[10000];
  clock_t start, end;
  double cpu_time_used;

  printf("Enter number of elements: ");
  scanf("%d\n", n);

  input_array(arr, n);
  start clock();
  quicksort(arr, 0, n-1);
  end clock();

  printf("Sorted array: \n");
  for(i=0; i<n; i++){printf("%d", array[i]);}
  printf("\n");

  cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
  printf("Time taken: %f.\n", cpu_time_used);
  return 0;
}

void quicksort(int arr[], int start, int end) //partitions the array around the pivotIndex
{
  //elements smaller than pivot will appear at the start of the array
  //elements greater than pivot will appear at the end of the array
  int pivotIndex;
  if(start<end)
  {
    pivotIndex = partitionarry(arr, start, end);
    quicksort(arr, start, pivotIndex-1); //focuses on the 1st part of the array
    quicksort(arr, pivotIndex+1, end); //focuses on the 2nd part of the array
  }
  return;
}

int partitionarry(int arr[], int start, int end)
{
  int pivot, i, j;
  pivot = arr[start];
  i = start+1;
  j = end;

  while(i<=j) //until the two of them meet
  {
    if(arr[i]<=pivot)
      i++; //i keeps moving upwards
    else if(arr[i]>pivot)
      j--; //j keeps moving downwards
    else
    {
      swap(arr, i, j); //swapping occurs when i is bigger and j is less than the pivot
      i++;
      j--;
    }
  }

  swap(arr, start, j); //pivot at position start is swapped with j
  return j;
}

void swap(int arr[], int i, int j)
{
  int temp;
  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
  return;
}
