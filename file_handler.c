#include <stdio.h>
#include "student.h"

#define database "student.dat"  //file name for storage

//  Save to file function definition
void saveToFile(struct Student roster[], int count) {
    
    // Open file for writing in binary
    FILE *fptr = fopen(database, "wb");

    // Check whether the file is corrupted / read-only
    if (fptr == NULL) {
        printf("ERROR! Could not open file for writing!");
        return;
    }

    // Write count so we know how many students when loading
    fwrite(&count, sizeof(int), 1, fptr);

    // Write all student records at once
    fwrite(roster, sizeof(struct Student), count, fptr);

    // Close file
    fclose(fptr);
    printf("\nSuccessfully saved %d record(s) to '%s'\n", count, database);
}

//  Load from file function definition
void loadFromFile(struct Student roster[], int *count) {

    // Open file for reading in binary
    FILE *fptr = fopen(database, "rb");

    // Check whether the file is corrupted / read-only / doesn't exist (first run)
    if (fptr == NULL) {
        printf("No saved data file found! Starting fresh...\n");
        *count = 0;
        return;
    }
    
    // Read file count
    int file_count;
    fread(&file_count, sizeof(int), 1, fptr);

    // Make sure file count doesn't go over array size (max_student)
    if (file_count > max_student) {
        printf("Warning! File has %d reccords, but max is %d. Loading first %d...\n", file_count, max_student, max_student);
    }

    // Read all student records stored in student.dat
    fread(roster, sizeof(struct Student), file_count, fptr);
    *count = file_count;    // Update pointer count to file_count

    // Close file
    fclose(fptr);
    printf("Successfully loaded %d record(s) from '%s'!\n", file_count, database);
}