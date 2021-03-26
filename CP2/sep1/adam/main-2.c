//
// Created by Adam on 15/03/2021.
//
#include <stdio.h>
#include "read.h"
#include "sort.h"

//Declaring my playlist array
char playlist[Lines][Component];

//Declaring my variables
int input;
int x;
int y;

int main()
{
    readFile(playlist, &input);
    sort(playlist, x, y);

    for(int i = 0; i < input; i++)
    {
        printf("%s", playlist[i]);
    }
}