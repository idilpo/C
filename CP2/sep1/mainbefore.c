/*
const char *SONG_FILE_PATH = "/Users/idilbilgic/Desktop/assignment1/artiste+songs.txt";
FILE* fp;
fp = fopen(songArray, "r");
if (fp == NULL)
{
    printf("Error.\n");
    exit;
}
 */


int k=0, l=1, m=0, n=0;
//file_scan(DJ, &lineNum);
strcpy(artists[0], DJ[0]);
for (int i=0; i<lineNum; i++)
{
    if ((DJ[i][(strlen(DJ[i])) - 2] >= '0') && (DJ[i][(strlen(DJ[i])) - 2] <= '9'))
    {
        strcpy(songs[k], DJ[i]);
        song_count++;
        k++;
    }
    else if (DJ[i][0] == '\n')
    {
        l++;
        artist_count++;
    }
}
for (int i=1; i<artist_count; i++)
{
    k=i;
    while (strcmp(artists[k], artists[k-1]) < 0)
    {
        strcpy(swap, artists[k]);
        strcpy(artists[k], artists[k-1]);
        strcpy(artists[k-1], swap);
        k--;
    }
}

int unique[10];
for (int i=0; i<artist_count+1; i++) {unique[i] = 0;}
for (int i=0; i<lineNum; i++) {strcpy(joshethancassified[i], DJ[i]);}
char test[max_lines][max_elements];
//int g=0, f=0;
for (int i=0; i<lineNum; i++)
{
    if (*artists[m] == *DJ[i])
    {
        while (DJ[i][0] != '\n')
        {
            strcpy(test[n], DJ[i]);
            printf("  %s  ", test[n]);
            i++;
            n++;
        }
        printf("\n");
        m++;
        i=0;
    }
}









/* mine before:
FILE *fp;
if((fp = fopen("/Users/idilbilgic/Desktop/assignment1/artiste+songs.txt", "r+")) == NULL)
{
    puts("File cannot be opened");
}
else
{
    while(fgets(array[lineNum], sizeof(array[lineNum]), fp) != NULL) {lineNum++;}
    fclose(fp);
}


int d; //duration of each song
int choice; //user input

printf("Welcome to 'DJ For An Hour', a random playlist generator!");
printf("Do you wish to continue? Please enter 1 to run the program or enter 0 to terminate: ");
scanf("%d", choice);

if (choice==0)
{
    printf("You've chosen 0, program will terminate.");
    exit;
}
else if (choice==1)
{
    printf("You've chosen 1, here is your randomised playlist:");
    qsort(songArray);
}
else //in case of the entry of an invalid character
{
    do{
        printf("Please enter a valid character.\n");
        scanf("%d", choice);
    } while(choice!=0 && choice!=1);
}

//time(int d, ...);
//printf("Playlist duration: %d:%d",);
 */
