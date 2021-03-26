#include <stdio.h>

int main()
{
  int n, i, j, swap; int array[100];

  printf("Enter number of elements: ");
  scanf("%d\n", n);
  printf("Enter %d integers: ", n);
  for(i=0; i<n; i++){scanf("%d\n", &array[i]);}

  for(i=1; i<n; i++) //starts from 1 assuming the 1st element is already sorted
  {
    j=i;
    while(j>0 &&  array[j]<array[j-1]) //compare if the element in posiiton j is less than j-1
    {
      swap = array[j];
      array[j] = array[j-1];
      array[j-1] = swap;
      j--; //j moves down the array starting from i to 0
    }
  }

  printf("Sorted array: \n");
  for(i=0; i<n; i++){printf("%d", array[i]);}
  return 0;
}
