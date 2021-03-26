#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int array[100];
    int i, j;
    int swap;

    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && array[j] < array[j - 1])
        {
            swap = array[j];
            array[j] = array[j - 1];
            array[j - 1] = swap;
            j--;
        }
    }

    return 0;
}
