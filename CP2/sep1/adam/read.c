//
// Created by Adam on 15/03/2021.
//
#include <stdio.h>
#include "read.h"
#define Lines 300
#define Component 300

int file = 0;

const char *path = "C:\\Users\\Adam\\CLionProjects\\Software_Project2\\artistes+songs.txt";

void readFile (char string[Lines][Component], int *size)
{
    FILE *fp = fopen(path, "r+");

    if(fp == NULL)
    {
        perror("Error");
    }
    else
    {
        while(fgets(string[file], sizeof(string[file]), fp) != NULL)
        {
            file++;
        }
        fclose(fp);
    }
    *size = file;
}