#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STR_COUNT 12

const char* strings[] =
{
  "COMP10120", "is", "my", "favourite", "module", "and",
  "I", "learn", "lots", "of", "interesting", "things"
};

void jumble()
{
    int size = STR_COUNT;
    if (size>1)
    {
        //step through each index of the city name array
        for (int i=0; i<size-1; i++)
        {
        //pick a random index (j) to swap it with
        //okay to pick same value as i
        int j = rand() % STR_COUNT; //random between 0 and 10
        const char* temp = strings[j];
        strings[j] = strings[i];
        strings[i] = temp;
        }
    }
    for (int p=0; p<STR_COUNT; p++) {printf("%s\n", strings[p]);}
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    jumble();
}
