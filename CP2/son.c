#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX 10
int myArray[] = {2,4,6,8,10,12,14,16,18,20};

//void reverseArray(int arraySize, int a[], int myArray[]);
void reverseArray(int arraySize, int a[], int myArray[]) //reverses the order of all elements in an array
{
  int arr[MAX]; int i;
  for(i=0; i<arraySize; i++) {arr[i] = myArray[i];}
  for(i=0; i<arraySize; i++) {a[i] = arr[i];}
  for(i=MAX-1; i>=0; i--) {printf("%d ", myArray[i]);}
  return;
}

void randomiseArray(int arraySize, int a[], int myArray[]);
void randomiseArray(int arraySize, int a[], int myArray[]) //randomly mixes the order of elements in an array
{
  int k = arraySize - 1;
  int j, temp;
  srand(time(NULL));

  while (k>0) //uses a Fisher-Yates shuffle algorithm
  {
    j = rand() % (k + 1);
    temp = a[k];
    a[k] = a[j];
    a[j] = temp;
    k = k-1;
  }
  return;
}

void printArray(int arraySize, int a[]);
void printArray(int arraySize, int a[]) //prints the contents of the array in reverse order or random order depending on user input
{
  for(int n=0; n<arraySize; n++) {printf("%d", a[MAX]);}
}

void sum(int a[], int myArray[]);
void sum(int a[], int myArray[])
{
  int s=0; //the sum of all numbers are initialised to 0
  for(int m=0; m<a[m]; m++) {s+=a[m];} //adds all elements together
  printf("The sum of all array numbers is %d.\n", s);
}

int main(void)
{
  int arraySize = sizeof(myArray)/sizeof(myArray[0]);
  void(*f[3])(int arraySize,int a[]) = {reverseArray, randomiseArray, printArray};
  printf("Please enter 3 for COMPUTATIONS or enter 0 to TERMINATE the program: ");
  size_t input; //variable to hold user's input
  scanf("%zd", &input);

  while((input!=0) && (input!=3))
  {
    printf("Please enter a valid number: ");
    scanf("%zd", &input);
    break;
  }

  bool t = true;
  while(true) //processing user's input
  {
    //void (*f[3])(int arraySize,int a[]) = {reverseArray, randomiseArray, printArray}; //invoke func at location input in array and pass input as argument
    if(input==0){printf("You've chosen 0, program will TERMINATE.\n");}
    if (input==3)
    {
      int choice;
      printf("Which operation would you like to compute?\n");
      printf("Enter 1 for REVERSE, 2 for RANDOMISE: ");
      scanf("%d", &choice);

      while((choice!=1) || (input!=2))
      {
        printf("Please enter a valid number: ");
        scanf("%d", &choice);
      }
      if(choice==1)
      {
        printf("You've chosen 1, here is the REVERSE of the array:\n");
        reverseArray(arraySize, myArray); //calls the chosen function
      }
      else if (choice==2)
      {
        printf("You've chosen 2, here is the RANDOMISED version of the array:\n");
        randomiseArray(arraySize,  myArray); //calls the chosen function
      }
    }
    t=false;
    break;
  }

  printf("Would you like to see the sum of the array numbers?\n");
  printf("Enter Y for yes and N for no: ");
  int ch = getchar();
  if(ch=='Y'){sum(myArray);}
  if(ch=='N'){puts("Program execution completed.");}
}
