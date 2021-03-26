#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

const char *TEXT_PATH = "/Users/idilbilgic/Desktop/STAGE 1.2/COMP10050/assignment1/artistes+songs.txt";
char data[10000][70];
int array[10000];

int main()
{
    int lineNum;
    FILE *fp = fopen(TEXT_PATH, "r+");

    if(fp == NULL)
    {
        perror("Error opening weather file");
        lineNum = -1;    /* use this as a file not found code.  */
    }
    else
    {
/*  Recall that fgets returns NULL when it gets to the end of the file.  */
        while(fgets(data[lineNum], sizeof(data[lineNum]), fp) != NULL)
            lineNum++;

        fclose (fp);
    }

    for(int k=0; k<lineNum; k++) {printf("\n%s\n", data[k]);}

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int n;
    int array[100];
    int i, j;
    int swap;

    for (i=1; i<n; i++)
    {
        j = i;
        while (j>0 && array[j]<array[j-1])
        {
            swap = array[j];
            array[j] = array[j-1];
            array[j-1] = swap;
            j--;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
    return 0;







    FILE *cfPtr; //cfPtr = clients.txt file pointer

    if ((cfPtr = fopen("artistes+songs.txt", "w")) == NULL)
    {
      puts("File could not be opened");
    }
    else
    {
      puts("Enter the artist, song and duration.");
      puts("Enter EEOF to end input.");
      printf("%s\n", "?");

      unsigned int artist; //account number
      char song[50]; //account name
      double duration; //account balance

      scanf("%d%49s%lf", &artist, song, &duration);

      while (!feof(stdin)) //writes into file with fprintf
      {
        fprintf(cfptr, "%d %s %.2f\n", artist, song, duration);
        printf("%s", "? ");
        scanf("%d%49s%ld", &artist, song, &duration);
      }

      fclose(cfPtr); //fclose closes file
    }
}
