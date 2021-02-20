#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main(void) {
  //Declaration and Initiaziation of variables
  int arrayA[20][20];
  int arrayB[20][20];
  int arraysum[20][20];
  int arrayproduct[20][20];
  int r,c,j,i,total=0,row=0,column=0;
  srand(time(0)); //seed for random number generator
  //getting inputs of size from user
  printf("enter the size of row: ");
  scanf("%i",&r);
  printf("enter the size of column: ");
  scanf("%i",&c);
  printf("\n");

  //printing all elements of arrayA
  printf("elements of array A\n");
  for(i=0; i<r; i++) {
      for(j=0;j<c;j++) {

          arrayA[i][j]=(rand()%1401)+100;
          printf("The element at arrayA[%i][%i] : %i\n", i, j,arrayA[i][j]);

      }
   }

  //printing all elements of arrayA
   printf("elements of array B\n");
  for(i=0; i<r; i++) {
      for(j=0;j<c;j++) {
          arrayB[i][j]=(rand()%1401)+100;
          printf("The element at arrayB[%i][%i] : %i\n", i, j,arrayB[i][j]);


      }
   }
   printf("\n");

   //printing all row_sum and column_sum of arrayA
   printf("arrayA row and column sum:\n");
   for(i=0; i<r; i++) {
      for(j=0;j<c;j++) {

          row+=arrayA[i][j];
      }
      printf("The [%i] row_sum of arrayA is: %i.\n",i+1,row);
      row=0;
   }
   for(i=0; i<r; i++) {
      for(j=0;j<c;j++) {

          column+=arrayA[j][i];
      }
      printf("The [%i] column_sum of arrayA is: %i.\n",i+1,column);
      column=0;
   }
   printf("\n");

   //printing all row_sum and column_sum of arrayB
   printf("arrayB row and column sum:\n");
   for(i=0; i<r; i++) {
      for(j=0;j<c;j++) {

          row+=arrayB[i][j];
      }
      printf("The [%i] row_sum of arrayB is: %i.\n",i+1,row);
      row=0;
   }
   for(i=0; i<r; i++) {
      for(j=0;j<c;j++) {

          column+=arrayB[j][i];
      }
      printf("The [%i] column_sum of arrayB is: %i.\n",i+1,column);
      column=0;
   }
   printf("\n");

   //printing product of both arrayA and arrayB
   printf("Product array:\n");
   for(i=0; i<r; i++) {
      for(j=0;j<c;j++) {
          arrayproduct[i][j]=arrayB[i][j]*arrayA[i][j];
          printf("The product of arrayA and arrayB at [%i][%i] is : %i\n", i, j,arrayproduct[i][j]);

      }
   }
   printf("\n");

   //printing sum of both arrayA and arrayB
   printf("Sum array:\n");
   for(i=0; i<r; i++) {
      for(j=0;j<c;j++) {
          arraysum[i][j]=arrayB[i][j]+arrayA[i][j];
          printf("The sum of arrayA and arrayB at [%i][%i] is : %i\n", i, j,arraysum[i][j]);
      }
   }
   printf("\n");

   //printing WoW if both arrayA and arrayB has equal value in the same cell
   for(i=0; i<r; i++) {
      for(j=0;j<c;j++) {
        if(arrayB[i][j]==arrayA[i][j])
          printf("WOW !!! at [%i][%i] the cells of two arrays match  \n", i, j);
      }
   }
   //printing the total of all elements in both arrayA and arrayB
   total=2*(r*c);
   printf("The total elements from arrayA and arrayB is %i\n",total);
   return 0;

}
