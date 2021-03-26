#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 1000
#define TEST_SIZE 7

void newDatabase(FILE *fp); //function prototype
struct database
{
  int dvd_id; char title[70]; char genre[20];
  int year; int borrowed; char date_borrowed[11];
  unsigned int customer_id;
};

int main(void)
{
  FILE *fp;
  if((fp = fopen("dvd.dat", "rw+"))== NULL)
  {
    puts("No database file found, a new empty database will be created.");
    newDatabase(fp);
    if((fp = fopen("dvd.dat", "rw+")) == NULL)
    {
      puts("Couldn't open file after writing empty database.");
      return 1;
    }
  }
  fclose(fp);
  return 0;
}

void newDatabase(FILE *fp)
{
  fp = fopen("dvd.dat", "wb");
  struct database blank = {0, "John Doe", "The Movie", 0, 0, 0, "01-01-2021"};
  for(int i=0; i<TEST_SIZE; i++)
  {
    blank.dvd_id = i + 1;
    blank.year = 2021;
    blank.customer_id = i * 4;
    fwrite(&blank, sizeof(struct database), 1, fp);
  }
  fclose(fp);
}
