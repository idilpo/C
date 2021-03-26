#include <stdio.h>

int main()
{
   char data[MAX][MAX];
   int i;

   FILE fp = fopen("songs.txt", "r+");

   //This will check in case the input .txt file exists or not
   if ((fp = fopen("songs.txt", "r")) == NULL) {
      printf("Um....are you sure this file exists? Maybe try again after obtaining this file.\n");
      exit(0);
   }

   while(!feof(fp)) {
      /
       * if data line doesn't contain * then store into record.artist
       * if data line does contain * then split the string using strtrok to store the first half into record.song
       * and the second half into record.length
      /
   }

   / Implementation of selection sort to sort data to print out in the following format:
    *  Artist:
    *  - Song*Duration
    *  - Song*Duration
    *  ...
    *  <new line>
    *  Artist:
    *  - Song*Duration
    *  - Song*Duration
    *  ...
    *  <new line>
    /

   / Implemetation of Fisher-Yates Algrorithm
    * to shuffle the list
    */

   printf("%s", data);
   return 0;
}
