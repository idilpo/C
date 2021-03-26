#include <stdio.h>
#include <string.h>
#include "library.h"

//functions used:
/*
void sorting(char array[MAX_LINES][MAX_ELEMENTS], int lineNum)
{
    char swap[MAX_ELEMENTS];
    int j;
    for (int i=1; i<lineNum; i++)
    {
        j = i;
        while ((array[j] > 0) && (strcmp(array[j], array[j - 1]) < 0))
        {
            strcpy(swap, array[j]);
            strcpy(array[j], array[j - 1]);
            strcpy(array[j - 1], swap);
        }
    }
}*/



void sorting(char array[MAX_LINES][MAX_ELEMENTS], int start, int end)
{
    char swap[MAX_ELEMENTS];
    int i, j;
    for  (i=1-start; i<end; i++)
    {
        j=i;
        strcpy(swap, array[j]);
        while (j > 0 && strcmp(array[j], array[j - 1]) < 0)
        {
            strcpy(swap, array[j]);
            strcpy(array[j], array[j - 1]);
            strcpy(array[j - 1], swap);
            j--;
        }
    }
}




/*
void seperating(void)
{
    char *name[MAX_LINES], *street[MAX_ELEMENTS], *city;
    static const char file[] = "/Users/idilbilgic/Desktop/assignment1/indie-1990s-2000s.txt";
    FILE *fp = fopen(file, "r+");
    char line[MAX_ELEMENTS];
    char *val;
    int i=0;
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        name[i] = strtok(line, "*");
        street[i] = strtok(NULL, "*");
        if (name[i] == NULL) {name[i] = "";}
        else if (street[i] == NULL) {street[i] = "";}
        printf("%s: ", name[i]);
        printf("%s\n", street[i]);
        i++;
    }
    fclose(fp);

} */



void seperating(void)
{
    int i=0;
    static const char file[] = "/Users/idilbilgic/Desktop/assignment1/indie-1990s-2000s.txt";
    FILE *fp = fopen(file, "r+");
    char line[MAX_ELEMENTS];
    char * token = strtok(line, "*");
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "*");
        //printf("%s ", songs[MAX_ELEMENTS]);
        //printf("%s ", durations[MAX_ELEMENTS]);
        i++;
    }
    fclose(fp);
}
