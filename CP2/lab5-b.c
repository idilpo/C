#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
//function prototypes:
void reverseArray(int arraySize, int a[]);
void randomiseArray(int arraySize, int a[]);
void printArray(int arraySize, int a[]);
void arraySum(int arraySize, int a[]);

int main()
{
  int arraySize=10;
  int myArray[] = {2,4,6,8,10,12,14,16,18,20};
  printArray(10, myArray);
}

void reverseArray(int arraySize, int a[]) //reverses the order of all elements in an array
{
  int i, j=0;
  int myArray[arraySize];

  for(i=arraySize-1; i>=0; i--) //goes thorugh the array and reverses
  {
    myArray[j] = a[i];
    j++;
  }
  for(i=0; i<arraySize; i++) {a[i] = myArray[i];}
  for(i=0; i<arraySize; i++) {printf("%d ", a[i]);}
}

void randomiseArray(int arraySize, int a[]) //randomly puts elements in the array using a temporray value
{
  srand(time(NULL));
  int k = arraySize - 1;
  int l, temp;

  while (k>0) //uses a Fisher-Yates shuffle algorithm
  {
    l = rand() % (k + 1);
    temp = a[k];
    a[k] = a[l];
    a[l] = temp;
    k = k-1;
  }

  for(k=0; k<10; k++) {printf("%d ", a[k]);}
}

void arraySum(int arraySize, int a[])
{
  int sum=0; //the sum is initialised to 0 at the beginning
  for(int m=0; m<arraySize; m++) {sum+=a[m];} //adds all elements together
  printf("%d ", sum);
}

void printArray(int arraySize, int a[])
{
  //menu-driven program:
  void (*f[3]) (int arraySize, int a[]) = {reverseArray, randomiseArray, arraySum};
  printf("Please enter 0 for REVERSE, 1 for RANDOMISE, 2 for SUM or enter 3 to TERMINATE the program: ");
  size_t input; //variable to hold user's input
  scanf("%zd", &input);

  while((input!=0) && (input!=1) && (input!=2) && (input!=3))
  {
    printf("An invalid number is entered. ");
    break;
  }

  if(input==3){printf("You've chosen 0, program will TERMINATE.\n");}
  if(input>=0 && input<=2) {(f[input])(arraySize, a);} //executes the entered computation
}
