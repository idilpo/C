#include <stdio.h>
#include <string.h>


#define lines 200
#define columns 400

char ArrCountainer[lines][columns];
int authorsIndex[lines];
int SongsLength[lines];
int songsFirstIndex[lines];
int songsLastIndex[lines];


int lineNum = 0;

void sort(char arr[lines][columns], int beg,int end)
{
    int j;
    char tmp[lines];
    for(int i = beg+1; i < end+1;i++)
    {

        j = i;
        while(j > 0 && strcmp(arr[j], arr[j-1]) < 0 && (j != beg))
        {
            strcpy(tmp, arr[j]);
            strcpy(arr[j], arr[j-1]);
            strcpy(arr[j-1], tmp);
            j--;
        }

    }
}

int main(void)
{
    FILE *fp;

    if((fp = fopen("/Users/firat/Downloads/p3q6/briansedit.txt", "r+")) == NULL)
    {
        puts("File cannot be opened");
    }
    else{
        while(fgets(ArrCountainer[lineNum], sizeof(ArrCountainer[lineNum]), fp) != NULL)
        {
            lineNum++;
        }

        fclose(fp);
    }


    int beg = 0;
    int autor = 0;
    int start = 0;
    int end;

    for(int i=0;i<lineNum;i++)
    {
        if(ArrCountainer[i][0]  == '\n' && ArrCountainer[i-1][0] != '\n')
        {
            end = i-1;
            authorsIndex[autor] = start;
            songsFirstIndex[beg] = start+1;
            songsLastIndex[beg] = end;
            autor++;
            beg++;
            start = i+1;

        }
    }

    for(int i=0;i<autor;i++)
    {
        sort(ArrCountainer, songsFirstIndex[i], songsLastIndex[i]);
    }

    char ordered[autor][400];

    for(int i=0; i<autor;i++)
    {
        strcpy(ordered[i], ArrCountainer[authorsIndex[i]]);
    }

    sort(ordered, 0, autor-1);

    char newArr[lines][columns];
    int new=0;

    for(int i=0; i<autor;i++)
    {
        for(int j =0; j<lineNum;j++)
        {
            if(strcmp(ordered[i], ArrCountainer[j]) == 0)
            {
                while(ArrCountainer[j][0] != '\n')
                {
                    strcpy(newArr[new], ArrCountainer[j]);
                    j++;
                    printf("%d\n", new);
                    ++new;
                }
                strcpy(newArr[new], "\n");
                ++new;
                printf("%d\n", new);

            }
        }
    }

    printf("%d\n", new);
    for(int i=0; i < new; i++)
    {
        printf("%s ", newArr[i]);
    }
    return 0;
}
