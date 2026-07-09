#include <stdio.h>
#include <string.h>
#include "student.h"

// Forward declarations for helper functions
void searchById(struct Student roster[], int count);
void searchByName(struct Student roster[], int count);

void searchStudent(struct Student roster[], int count) {
    if (count == 0) {
        printf(bold_on "\nNo student records available to search.\n" bold_off);
        return;
    }

    int searchChoice;
    do {
        printf(bold_on "\n=== SEARCH STUDENT RECORDS ===\n" bold_off);
        printf("1. Search by Student ID\n");
        printf("2. Search by Name\n");
        printf("3. Display All Students\n");
        printf("4. Return to Main Menu\n");
        printf(bold_on "Enter your choice: " bold_off);

        if (scanf("%d", &searchChoice) != 1) {
            printf(bold_on "\nInvalid input. Please enter a number.\n" bold_off);
            while (getchar() != '\n');
            searchChoice = 0;
            continue;
        }
        while (getchar() != '\n');

        switch(searchChoice) {
            case 1: searchById(roster, count); break;
            case 2: searchByName(roster, count); break;
            case 3: displayStudents(roster, count); break;
            case 4: printf("Returning to main menu...\n"); break;
            default: printf(bold_on "\nInvalid choice. Please try again.\n" bold_off);
        }
    } while (searchChoice != 4);
}

// Search by ID Function
void searchById(struct Student roster[], int count) {
    long id;
    printf(bold_on "\nEnter Student ID to search: " bold_off);

    if (scanf("%ld", &id) != 1) {
        printf(bold_on "\nInvalid input.\n" bold_off);
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (roster[i].id == id) {
            printf(bold_on "\n=== STUDENT RECORD FOUND ===\n" bold_off);
            printf("ID: %ld\n", roster[i].id);
            printf("Name: %s\n", roster[i].name);
            printf("Gender: %s\n", roster[i].gender);
            printf("Scores: ");
            for (int j = 0; j < num_subject; j++) {
                printf("%.2f ", roster[i].scores[j]);
            }
            printf("\nAverage: %.2f\n", roster[i].average);
            printf("Grade: %s\n", roster[i].grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf(bold_on "\nNo student found with ID %ld.\n" bold_off, id);
    }
}

// Search by Name (Partial Match)
void searchByName(struct Student roster[], int count) {
    char name[50];
    printf(bold_on "\nEnter name (or part of name) to search: " bold_off);
    scanf(" %[^\n]%*c", name);

    int found = 0;
    printf(bold_on "\n=== SEARCH RESULTS FOR \"%s\" ===\n" bold_off, name);

    for (int i = 0; i < count; i++) {
        if (strstr(roster[i].name, name) != NULL) {
            printf("ID: %ld | Name: %s | Gender: %s | Avg: %.2f | Grade: %s\n",
                   roster[i].id, roster[i].name, roster[i].gender,
                   roster[i].average, roster[i].grade);
            found = 1;
        }
    }

    if (!found) {
        printf(bold_on "\nNo students found matching \"%s\".\n" bold_off, name);
    }
}
