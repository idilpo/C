#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "library.h"

//functions used:
void sorting(char array[max_lines][max_elements], int lineNum)
{
    char swap[100];
    int j;
    for (int i=1; i<lineNum; i++)
    {
        j=i;
        while ((array[j] > 0) && (strcmp(array[j], array[j-1]) < 0))
        {
            strcpy(swap, array[j]);
            strcpy(array[j], array[j-1]);
            strcpy(array[j-1], swap);
        }

    }

    /* my sorting function from before:
    int i, j, val;
    for(i=1; i<lines; i++)
    {
        j=i;
        val = songArray[j];
        while(j>0 &&  val<songArray[j-1])
        {
            songArray[j] = songArray[j-1];
            j--;
        }
        songArray[j] = val;
    */
}

/*
void removeExcess(void) //DEĞİŞKEN ADLARINI DEĞİŞTİR
{
    char *name[max_lines], *street[max_elements], *city;
    static const char file[] = "/Users/idilbilgic/Desktop/assignment1/indie-1990s-2000s.txt";
    FILE *fp = fopen(file, "r+");
    char line[max_elements];
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
}
*/

/*
void file_scan(char array[max_lines][max_elements], int *size)
{
    int lineNum=0;
    const char *SONG_FILE_PATH = "/Users/idilbilgic/Desktop/assignment1/indie-1990s-2000s.txt";
    FILE *fp = fopen(SONG_FILE_PATH, "r+");
    if(fp == NULL)
    {
        perror("No file was found.");
        lineNum = -1;
    }
    else
    {
        while(fgets(array[lineNum], sizeof(array[lineNum]), fp) != NULL) {lineNum++;}
        fclose(fp);
    }
}


*/

/* my shuffle from before:
 void fisher(int songArray[], int n)
{
    int i, j, tmp; // create local variables to hold values for shuffle
    for (i=n-1; i>0; i--)
    { // for loop to shuffle
        j = rand() % (i + 1); //randomise j for shuffle with Fisher Yates
        tmp = songArray[j];
        songArray[j] = songArray[i];
        songArray[i] = tmp;
    }

}
 */


/*
void swap(int *a, int *b) //function needed for fisher-yates shuffle
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void knuth(int songArray[], int n)
{
    n = sizeof(songArray) / sizeof(songArray[0]);

    //randomise:
    srand(time(NULL));
    for(int i=n-1; i>0; i--)
    {
        int j = rand() % (i+1);
        swap(&songArray[i], &songArray[j]);
    }
    //print array:
    for(int i=0; i<n; i++) {printf("%d ", songArray[i]);}
    printf("\n");
}
*/





/*
void time(int d, ...)
{
    int min=0;
    int sec=0;

    for (int i=0; i<maxsize; i++)
    {
        d += ?; //duration will be updated with each song
        min = ;
        sec = ;
    }

}
 */
