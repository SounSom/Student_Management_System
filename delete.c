#include <stdio.h>
#include <string.h>
#include "student.h"

//Function definition
void deleteStudent(struct Student roster[], int *count) {
    if (*count == 0) {
        printf("\nThe database is currently empty. No records to delete.\n");
        return;
    }

    int mode;
    int found = -1;

    // Mini-menu for deletion options
    printf("\nDelete Record By:\n");
    printf("1. Student ID\n");
    printf("2. Student Name\n");
    printf("Enter operation option (1-2): ");
    
    if (scanf("%d", &mode) != 1) {      // Checks for number inputs only
        printf("[ERROR] Invalid input.\n");
        while (getchar() != '\n'); // clear buffer
        return;
    }

        // Delete by ID
    if (mode == 1) {
        int id_del;
        printf("Enter Student ID: ");
        scanf("%d", &id_del);

        for (int i = 0; i < *count; i++) {
            if (roster[i].id == id_del) {   // Compare student IDs in database for valid ID for deletion
                found = i;
                break;
            }
        }
    } 
        // Delete by name
    else if (mode == 2) {
        char name_del[50];
        printf("Enter Student Name: ");
        
        // clear buffer and begin loop for fgets
        while (getchar() != '\n');  
        fgets(name_del, sizeof(name_del), stdin);   // Reads and stores whole line of text
        name_del[strcspn(name_del, "\n")] = '\0';   // Remove the '\n' that fgets grabbed automatically

        for (int i = 0; i < *count; i++) {
            if (strcmp(roster[i].name, name_del) == 0) {    // Compare Student names in database for valid name for deletion
                found = i;
                break;
            }
        }
    }

    // Invalid operation choice
    else {
        printf("[ERROR] Invalid mode selected.\n");
        return;
    }

    // No valid IDs / names found in database
    if (found == -1) {
        printf("[ERROR] Record not found in the system registry.\n");
        return;
    }

    // Shift everything left by 1 (The actual deletion process)
    for (int i = found; i < *count - 1; i++) {
        roster[i] = roster[i + 1];
    }

    // Reduce current registered student counter by 1
    (*count)--;
    printf("Successfully deleted record.\n");
}