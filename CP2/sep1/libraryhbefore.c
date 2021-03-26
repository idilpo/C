#ifndef ASSIGNMENT1_LIBRARY_H
#define ASSIGNMENT1_LIBRARY_H
#endif //ASSIGNMENT1_LIBRARY_H

#define max_lines 1000
#define max_elements 500

//declarations:
char DJ[max_lines][max_elements];
char songs[max_lines][max_elements];
char artists[max_lines][max_elements];
char names[max_lines][max_elements];
char joshethancassified[max_lines][max_elements];
char swap[max_lines];
int lineNum=0;
int song_count=0;
int artist_count=0;

/*
int duration[lines];
int songsFirstIndex[lines];
int songsLastIndex[lines];
*/

//function prototypes:
void sorting(char array[max_lines][max_elements], int lineNum);
//void removeExcess(void);
//void file_scan(char array[max_lines][max_elements], int *size);
//void knuth();
//int time(int n, ...);
