// Program: Two-dimensional integer arrays
// Author: Idil Bilgic (19206730)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arrayA[20][20], arrayB[20][20];
int sum[20][20], product[20][20];
int r, c; //will be used in the for loops for going through the array elements, (r stands for rows, c stands for columns)
int total=0, rows=0, columns=0; //initialized to 0
//total=the numbers that occur in both arrays
int i, j; //for the loops

int main(void)
{
  srand(time(0)); //seed for the random number generator

  printf("Enter the size of row: ");
  scanf("%i", &r);
  printf("Enter the size of column: ");
  scanf("%i", &c);

  printf("--------------------------------------------------------\n");
  printf("Elements of arrayA: \n");
  for(i=0; i<r; i++)
  {
      for(j=0; j<c; j++)
      {
          arrayA[i][j]=(rand()%1400)+100; //generates random numbers between 100 and 1500
          printf("The element at arrayA[%i][%i] is %i.\n", i, j, arrayA[i][j]);
      }
   }

   printf("--------------------------------------------------------\n");
   printf("Elements of arrayB: \n");
   for(i=0; i<r; i++)
   {
      for(j=0; j<c; j++)
      {
          arrayB[i][j]=(rand()%1400)+100; //generates random numbers between 100 and 1500
          printf("The element at arrayB[%i][%i] is %i. \n", i, j, arrayB[i][j]);
      }
   }

   printf("--------------------------------------------------------\n");
   printf("Rows' and columns' sum of arrayA: \n");
   for(i=0; i<r; i++)
   {
      for (j=0; j<c; j++) {rows+=arrayA[i][j];}
      printf("The [%i] sum of rows of arrayA is %i.\n", i+1, rows);
      rows=0; //set back to 0
   }
   for (i=0; i<r; i++)
   {
      for (j=0; j<c; j++) {columns+=arrayA[j][i];}
      printf("The [%i] column_sum of arrayA is %i.\n", i+1, columns);
      columns=0; //set back to 0
   }

   printf("--------------------------------------------------------\n");
   printf("Rows' and columns' sum of arrayA: \n");
   for(i=0; i<r; i++)
   {
      for(j=0; j<c; j++) {rows+=arrayB[i][j];}
      printf("The [%i] sum of rows of arrayB is %i.\n", i+1, rows);
      rows=0; //set back to 0
   }
   for(i=0; i<r; i++)
   {
      for(j=0; j<c; j++) {columns+=arrayB[j][i];}
      printf("The [%i] sum of columns of arrayB is %i.\n", i+1, columns);
      columns=0; //set back to 0
   }

   printf("--------------------------------------------------------\n");
   printf("Product of arrayA and arrayB:\n");
   for(i=0; i<r; i++)
   {
      for(j=0; j<c; j++)
      {
          product[i][j]=arrayB[i][j]*arrayA[i][j];
          printf("The product of arrayA and arrayB at [%i][%i] is %i.\n", i, j, product[i][j]);
      }
   }

   printf("--------------------------------------------------------\n");
   printf("Sum of arrayA and arrayB:\n");
   for(i=0; i<r; i++)
   {
      for(j=0; j<c; j++)
      {
          sum[i][j] = arrayB[i][j] + arrayA[i][j];
          printf("The sum of arrayA and arrayB at [%i][%i] is %i.\n", i, j, sum[i][j]);
      }
   }

   for(i=0; i<r; i++) //when arrays match
   {
      for(j=0; j<c; j++)
      {
        if(arrayA[i][j]==arrayB[i][j])
        {
          printf("Wow, arrays match at the [%i][%i] cells!\n", i, j);
          total+=1;
        }
      }
   }

   printf("The total of elements from arrayA and arrayB is %i.\n", total);
}
