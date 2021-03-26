//program to illustrate prompting for a file and reading from it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[80];

    int  c;

/*  Prompt the user for a filename.  */
    printf("Enter a file name: ");
    fgets(filename, 80, stdin);

/*  Get rid of the trailing newline, if there is one...  */
    if (filename[strlen(filename) - 1] == '\n')
        filename[strlen(filename) - 1] = '\0';

    fp = fopen(filename, "r");

/*  Check that we can open the file, Exit if we can't.  */
    if (fp == NULL)
    {
        printf("Cannot open file %s.\n", filename);
        exit(1);
    }

/*  Now read from the file, one character at a time.  */
    c = getc(fp);
    while (c != EOF)
    {
        putchar(c);
        c = getc(fp);
    }

    fclose(fp);

    return 0;
}
