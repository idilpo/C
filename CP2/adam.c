#include <stdio.h>
#include <string.h>

int main(void)
{
    char countyList[20], nameList[20];
    int accountNumber, ageList, agreed, ageC = 0, Ages = 0;


    FILE *Point1, *Point2;

    //Opens the file "customers.txt" and reads it, then stores those variables in Point1
    Point1 = fopen("customers.txt", "r");

    //Opens the file "customers2.txt" and reads it, then stores those variables in Point2
    Point2 = fopen("customers2.txt", "w");


    while(!feof(Point1))
    {
        fscanf(Point1,"%s %s %d %d %d" , countyList, nameList, &accountNumber, &ageList, &agreed);
        if(agreed == 1 && strcmp(countyList, "Dublin") == 0 )
        {
            fprintf(Point2, "%s %s %d %d %d\n", countyList, nameList, accountNumber, ageList, agreed);
            Ages += ageList;
            ageC++;
        }
    }
    Ages = Ages/ageC;
    fprintf(Point2,"\nThe average age: %d", Ages);

    fclose(Point1);
    fclose(Point2);

}
