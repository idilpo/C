#include <stdio.h>

int main()
{
  int n, i, j, val; int array[100];

  printf("Enter number of elements: ");
  scanf("%d\n", n);
  printf("Enter %d integers: ", n);
  for(i=0; i<n; i++){scanf("%d\n", &array[i]);}

  for(i=1; i<n; i++) //improved intertion sort:
  {
    j=i;
    val = array[j];
    while(j>0 &&  val<array[j-1])
    {
      array[j] = array[j-1]; //moving the element in j-1 to position j
      j--;
    }
    array[j] = val;
  }

  printf("Sorted array: \n");
  for(i=0; i<n; i++){printf("%d", array[i]);}
  return 0;
}
