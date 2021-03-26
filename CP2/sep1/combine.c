void joshua(char array[MAX_LINES][MAX_ELEMENTS])
{
    char temp[MAX_ELEMENTS]; //temporarily stores the artist
    char line[MAX_ELEMENTS]; //temporarily stores the line that that is being worked on from the file
    static const char file[] = "/Users/idilbilgic/Desktop/assignment1/indie-1990s-2000s.txt";
    FILE *fp = fopen(file, "r+");
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        for (int i=0; i<lineNum; i++)
        {
            if(strchr(line,'\n') == NULL) {i++;}
            else if(strchr(line,'*') == NULL) //if(line == artist)
            {
                strcpy(temp, artists[i]);
                artist_count++;
                i++;
            }
            else
            {
                strcpy(playlist[i], temp); // copy the temporary artist into your_array[row X]
                strcpy(playlist[i], line[i]); //copy the line into your_array[row X]  <-- Add it onto the end of the artist.
                song_count++;
                i++; //move along the array to the next row
            }

        }
}


void sorting(char array[MAX_LINES][MAX_ELEMENTS], int start, int end)
{
    char swap[MAX_ELEMENTS];
    int i, j;
    for (i=start; i<end; i++)
    {
        j=i;
        strcpy(swap, array[j]);
        while (j > 0 && strcmp(array[j], array[j - 1]) < 0)
        {
            strcpy(swap, array[j]);
            strcpy(array[j], array[j - 1]);
            strcpy(array[j - 1], swap);
            j--;
        }
    }
    for (int i=0; i<=end; i++) {printf("%s", playlist[i]);}
}


void sort(char array[MAX_LINES][MAX_ELEMENTS],)        
