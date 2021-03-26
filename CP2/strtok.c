#include <string.h>
#include <stdio.h>

#define MAXSIZE 100
#define MAX 500

int main ()
{
   char *name[210], *street[210], *city;
   FILE *fp;
   static const char file[] = "path";
   char line[MAX]; char *val;
   char *token;
   int i;

   while(fgts(line, sizof(line), fp) != NULL)
   {
     name[i] = strtok(line, "*");
     street[i] = strtok(NULL, "*");
     printf("%s: ", name[i]);
     printf("%s: \n", street[i]);
     i++;
   }
   return(0);
}
