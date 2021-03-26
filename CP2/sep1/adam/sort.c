//
// Created by Adam on 18/03/2021.
//

#include <string.h>
#include "sort.h"

void sort(char arr[Lines][Char], int begin, int end)
{
    int i;
    int j;
    char swap[Char];

    for(i = 1 - begin; i < end; i++)
    {
        j = i;
        strcpy(swap, arr[j]);
        while (j > 0 && strcmp(arr[j], arr[j - 1]) < 0)
        {
           strcpy(swap, arr[j]);
           strcpy(arr[j], arr[j - 1]);
           strcpy(arr[j - 1], swap);
           j--;
        }

    }
}
