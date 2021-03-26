#include <stdio.h>
#include <string.h>

int main()
{
  char str[50] = "token1 token2 token3 token4 token5";
  //extract the first token
  char * token = strok(string, "*");
  //loop through the string to extract all other tokens:
  while (token != NULL)
  {
    printf("%s\n", token); //printing the token
    token = strtok(NULL, "*");
  }
}
