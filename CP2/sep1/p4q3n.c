#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*  We have 5 results...  */
#define NUM_RESULTS 5

/*  LINE_LENGTH must be >= (TEAM_LENGTH * 2) + (RES_LENGTH * 2) + 6 + 1:
6 for "++" * 3 and 1 for the NULL at the end  */
#define LINE_LENGTH 80
#define TEAM_LENGTH 30

/*  RES_LENGTH of 5 can accommodate a score of nn-nn in GAA.  */
#define RES_LENGTH 5


void readResults(char inputResults[][LINE_LENGTH]);
void printResults(char inputResults[][LINE_LENGTH]);


int main()
{
    char inputResults[NUM_RESULTS][LINE_LENGTH];

    readResults(inputResults);

    printf("The list of formatted results is as follows:\n");
    printResults(inputResults);

    return 0;
}


/*
This function requests NUM_RESULTS results from the keyboard
(one per line, according to the given input format)
and stores them in the array inputResults.
*/
void readResults(char inputResults[][LINE_LENGTH])
{
    int i;
    int linelen;

    printf("Enter %d results, please, one per line:\n", NUM_RESULTS);
    for (i = 0;  i < NUM_RESULTS;  i++)
    {
        printf("Enter result %d: ", i + 1);

/*  Use fgets to read a line from the standard input (stdin)  */
        fgets(inputResults[i], LINE_LENGTH, stdin);

/*  Don't forget to strip the newline from the end of the line!  */
        linelen = strlen(inputResults[i]);
        if (inputResults[i][strlen(inputResults[i]) - 1] == '\n')
            inputResults[i][strlen(inputResults[i]) - 1] = '\0';

    }

    return;
}


/*
This function prints out NUM_RESULTS results in the array inputResults
and prints them out according to the given output format.
*/
void printResults(char inputResults[][LINE_LENGTH])
{
    const char delim[] = "+";
    char homeTeamName[TEAM_LENGTH], awayTeamName[TEAM_LENGTH];
    char homeTeamScore[RES_LENGTH], awayTeamScore[RES_LENGTH];

    int i;
    int linelen;
    char *token;

    for (i = 0;  i < NUM_RESULTS;  i++)
    {
/*  Extract the first token (home team name)  */
        token = strtok(inputResults[i], delim);
        strcpy(homeTeamName, token);

/*  Extract the next token (home team score)  */
        token = strtok(NULL, delim);
        strcpy(homeTeamScore, token);

/*  Extract the next token (away team name)  */
        token = strtok(NULL, delim);
        strcpy(awayTeamName, token);

/*  Extract the next token (away team score)  */
        token = strtok(NULL, delim);
        strcpy(awayTeamScore, token);

/*  Now print them out according to the given format  */
        printf("%s-%s %s:%s\n", homeTeamName, awayTeamName, homeTeamScore, awayTeamScore);
    }

    return;
}
