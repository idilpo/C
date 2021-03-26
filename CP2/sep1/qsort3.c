#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
  int n, i, j, val;
  int array[100];
  char filename[100];
  FILE* fp;
  clock_t start, end;
  double cpu_time_used;

  printf("Enter number of elements: ");
  scanf("%d\n", n);
  printf("Enter  a file name: ");
  fscanf(stdin, "%s", filename);
  printf("Trying to open %s for reading\n", filename);

  //if((pos = strchr(filename, '\n')) != NULL)
    //*pos = '\0';

  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("Error.\n");
    exit;
  }
  for(i=0; i<n; i++){fscanf(fp, "%d", &array[i]);} //read on char at a time
  fclose(fp);

  start = clock();
  for(i=1; i<n; i++)
  {
    j=i;
    val = array[j];
    while(j>0 &&  val<array[j-1])
    {
      array[j] = array[j-1];
      j--;
    }
    array[j] = val;
  }
  end = clock();

  printf("Sorted array: \n");
  for(i=0; i<n; i++){printf("%d", array[i]);}
  printf("\n");

  //clock() returns num of clock tics so convrting  that to secs w CLOCKS_PER_SEC
  cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
  printf("Time taken: %f.\n", cpu_time_used);
  return 0;
}
