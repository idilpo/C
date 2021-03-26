#include ...


void fydkShuffle1(int arr[], int size);
void printArr(int arr[], int size);
void swapArrElems(int arr[], int i, int j);


int main()
{
    int arr[30];

    int i;
    int size;

    size = 30;

/*  Initialise the array.  */
    for (i = 0;  i < size;  i++)
        arr[i] = i;

    srand(time(NULL));  /*  srand() should only be called once!  */

    printf("Array before shuffling:\n");
    printArr(arr, size);

    fydkShuffle1(arr, size);


    printf("Array after shuffling:\n");
    printArr(arr, size);

    return 0;
}


/*
Shuffle an array of ints using the Fisher-Yates Durstenfeld Knuth Shuffle algorithm.
*/
void fydkShuffle1(int arr[], int size)
{
    int i, j;

    for (i = size - 1;  i >= 0;  i--)
    {
        j = rand() % i;
        swapArrElems(arr, i, j);
    }

    return;
}


/*
Print out an array of ints of size size.
*/
void printArr(int arr[], int size)
{
    ...
}


/*
Swap elements i and j in array arr of ints.
*/
void swapArrElems(int arr[], int i, int j)
{
    ...
}
