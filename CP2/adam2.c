#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void reverseArray(int arraySize, int a[]);
void randomiseArray(int arraySize, int a[]);
void sumOfArray(int arraySize, int a[]);
void printArray(int arraySize, int a[]);

int main()
{
    //
    int myArray[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    printArray(10, myArray);

    return 0;
}
//Method that Reverses the Array
void reverseArray(int arraySize, int a[])
{
    int i, j = 0;
    int myArray[arraySize];

    for(i = arraySize-1; i >= 0; i--)
    {
        myArray[j] = a[i];
        j++;
    }

    for(i=0; i<arraySize; i++)
    {
        a[i] = myArray[i];
    }

    for(i = 0; i < 10; i++)
    {
        printf("%d\n", a[i]);
    }
}
//Method that Randomises the Array
void randomiseArray(int arraySize, int a[])
{
    srand(time(NULL));

    int i, j, temp;
    for(i = arraySize-1; i > 0; i--)
    {
        j = rand() % (i+1);
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        j--;
    }

    for(i = 0; i < 10; i++)
    {
        printf("%d", a[i]);
    }

}
//Method that Calculates the Sum of the Array
void sumOfArray(int arraySize, int a[])
{
    int total = 0;
    int i;

    for(i = 0; i < arraySize; i++)
    {
        total = total + a[i];
    }
    printf("Total: %d\n", total);
}
//Method that Prints the Array
void printArray(int arraySize, int a[])
{
    void (*f[3]) (int arraySize, int a[]) = {reverseArray, randomiseArray, sumOfArray};

    int userChoice;

    printf("----()----()----()----\n");
    printf("This program is designed to Reverse, Randomise and Calculate the Sum of the array '2, 4, 6, 8, 10, 12, 14, 16, 18, 20'.\n");
    printf("Please press '0' to Reverse the Array.\nPlease press '1' to Randomise the Array.\nPlease press '2' to Calculate the Sum of the Array.\n");
    scanf("%d", &userChoice);

    if(userChoice >= 0 && userChoice <= 2)
    {
        (f[userChoice])(arraySize, a);
    }
    else
    {
        printf("Invalid input.\n");
    }
}
