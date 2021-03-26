//program to illustrate prompting for a file and reading from it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    int c;

/*  Check to see if the user supplied a filename. Exit if they didn't  */
    if (argc < 2)
    {
        printf("No filename supplied.\n");
        exit(2);
    }

    fp = fopen(argv[1], "r");

/*  Check that we can open the file, Exit if we can't.  */
    if (fp == NULL)
    {
        printf("Cannot open file %s.\n", argv[1]);
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
