// A C program to manage the DVDs of a DVD rental company. It is implemented as a menu based system with four options.
// Users can create DVDs (add them to the file), borrow DVDs, return DVDs and print the DVDs currently borrowed.
// One function handles borrowing and returning DVDs.

#include <stdio.h>

// DVD RECORD structure definition
struct DVD {
    unsigned int uniqueID;
    char title[100];
    char genre[40];
    unsigned int year;
    unsigned int borrowed;
    unsigned int borrowed_by;
};

// function defintions
void createDB();
void createDVD();
void updateBorrower(char a);
void viewborrowedDVD(int ID);

FILE *cfPtr; //pointer to file

int main() {
    // initialise integer to store user input
    int userInput;
    // initialise integer for use as marker in while loop
    int keepGoing = 1;

    // create the random access file
    createDB();

    // menu driven system, will continually ask for input until user enters exit value
    while(keepGoing == 1) {
        // array of pointers to functions
        void (*choice[])() = {createDVD, viewborrowedDVD, updateBorrower};

        printf("\nEnter 0 to create DVD, 1 to view borrowed DVD, 2 to borrow DVD, 3 to return DVD\n");
        printf("Any other integer to exit\n");
        printf("Enter your choice now: ");

        scanf("%d", &userInput);
        // check user input is within the options given, if not print message and exit
        if (userInput > 3|| userInput < 0) {
            printf("Goodbye!");
            keepGoing = 0;
        }
        else {
            // creating or viewing DVDs
            if (userInput == 0 || userInput == 1) {
                (*choice[userInput])(); // call the function at the index in choice that the user specified
            }
            // borrowing a DVD
            else if (userInput == 2){
                (*choice[userInput])('b');
            }
            // returning a DVD
            else if (userInput == 3){
                (*choice[2])('r');
            }
        }
    }
    return 0;
}

void createDB(){
    if ((cfPtr = fopen("dvd_catalog.dat", "ab")) == NULL){
        puts("File could not be opened");
    }
    else {
        struct DVD blankDVD = {0, "", "", 0, 0, 0};

        for (unsigned int i = 1; i<=10; ++i){
            fwrite(&blankDVD, sizeof(struct DVD), 1, cfPtr);
        }
    }
    fclose(cfPtr);
}

void createDVD(){
    // check file
    if ((cfPtr = fopen("dvd_catalog.dat", "ab")) == NULL){
        puts("File could not be opened");
    }
    else {
        // request user input for DVD details
        struct DVD new_DVD = {0, "", "", 0, 0, 0};
        printf("%s", "Enter DVD ID (an integer Eg, 100, 300, 500, 700): ");
        scanf("%ul", &new_DVD.uniqueID);
        printf("%s", "Enter DVD Title (as a string with no spaces): ");
        scanf("%s", new_DVD.title);
        printf("%s", "Enter DVD Genre (as a string with no spaces): ");
        scanf("%s", new_DVD.genre);
        printf("%s", "Enter DVD Year(as an integer): ");
        scanf("%ul", &new_DVD.year);

        // set borrowed and borrowed by to 0
        new_DVD.borrowed = 0;
        new_DVD.borrowed_by = 0;

        // write to file
        fseek(cfPtr, (new_DVD.uniqueID - 1) * sizeof(struct DVD), SEEK_SET);
        fwrite(&new_DVD, sizeof(struct DVD), 1, cfPtr);
    }
    fclose(cfPtr);
    printf("DVD successfully created\n\n");
}

void updateBorrower(char a){
    struct DVD new_DVD = {0, "", "", 0, 0, 0};
    // integer variables for DVD ID and Cust ID
    int ID;
    int CustID;

    // check file
    if ((cfPtr = fopen("dvd_catalog.dat", "rb+")) == NULL) {
        puts("File could not be opened");
    }

    else {
        // get DVD ID from user
        printf("Please enter the uniqueID of the DVD you wish to update: ");
        scanf("%d", &ID);
        // get the customer ID from user if the function is in borrow mode
        if (a == 'b'){
            printf("Please enter the customerID of the person borrowing the DVD: ");
            scanf("%d", &CustID);
        }


        while (!feof(cfPtr)) {
            //struct DVD new_DVD = {0, "", "", 0, 0, 0};
            // check how many results in file
            int result = fread(&new_DVD, sizeof(struct DVD), 1, cfPtr);
            // if the file has the correct ID
            if (result != 0 && (new_DVD.uniqueID == ID)) {
                    if  (a == 'b'){  // in borrow mode...
                        printf("%s", "Borrowing mode");
                        new_DVD.borrowed = 1; // set borrowed to 1
                        new_DVD.borrowed_by = CustID; // set borrowed_by to customer ID
                    }
                    if (a == 'r') { // in return mode
                        new_DVD.borrowed = 0; // set borrowed to 0
                        new_DVD.borrowed_by = 0; // set borrowed_by to 0
                    }
                    // print the new update
                    printf("%-6u%-20s%-11s%10u%16u%15d\n", new_DVD.uniqueID, new_DVD.title, new_DVD.genre, new_DVD.year, new_DVD.borrowed, new_DVD.borrowed_by);
                    fseek (cfPtr, (ID - 1) * sizeof(struct DVD), SEEK_SET); //seek to start of record
                    fwrite(&new_DVD, sizeof(struct DVD), 1, cfPtr); // write update to file
                }
            }
        }
    printf("DVD successfully updated\n\n");
    fclose(cfPtr);
}


void viewborrowedDVD() {
    //check file
    if ((cfPtr = fopen("dvd_catalog.dat", "rb+")) == NULL) {
        puts("File could not be opened");
    }
    else {
        while (!feof(cfPtr)) {
            struct DVD new_DVD = {0, "", "", 0, 0, 0};
            int result = fread(&new_DVD, sizeof(struct DVD), 1, cfPtr); // read from file

            if(result != 0 && (new_DVD.uniqueID != 0) && (new_DVD.borrowed == 1)) { // if it is borrowed
                printf("%-6u%-20s%-11s%10u%16u%15d\n", new_DVD.uniqueID, new_DVD.title, new_DVD.genre, new_DVD.year, new_DVD.borrowed, new_DVD.borrowed_by);
            }
        }
    }
    fclose(cfPtr);
}

