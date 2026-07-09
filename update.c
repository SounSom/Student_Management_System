#include <stdio.h>
#include <string.h>
#include "student.h"

// Forward declarations for helper functions
void updateName(struct Student roster[], int index);
void updateGender(struct Student roster[], int index);
void updateScores(struct Student roster[], int index);

void updateStudent(struct Student roster[], int count) {
    if (count == 0) {
        printf(bold_on "\nNo student records available to update.\n" bold_off);
        return;
    }

    long id;
    printf(bold_on "\nEnter Student ID of record to update: " bold_off);

    if (scanf("%ld", &id) != 1) {
        printf(bold_on "\nInvalid input.\n" bold_off);
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    // Find the student
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (roster[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf(bold_on "\nNo student found with ID %ld.\n" bold_off, id);
        return;
    }

    // Student found, now show what we have and what we can update
    printf(bold_on "\n=== CURRENT STUDENT INFORMATION ===\n" bold_off);
    printf("ID: %ld\n", roster[index].id);
    printf("Name: %s\n", roster[index].name);
    printf("Gender: %s\n", roster[index].gender);
    printf("Scores: ");
    for (int j = 0; j < num_subject; j++) {
        printf("%.2f ", roster[index].scores[j]);
    }
    printf("\nAverage: %.2f\n", roster[index].average);
    printf("Grade: %s\n", roster[index].grade);

    // Update menu
    int updateChoice;
    do {
        printf(bold_on "\n=== SELECT FIELD TO UPDATE ===\n" bold_off);
        printf("1. Name\n");
        printf("2. Gender\n");
        printf("3. Scores (all subjects)\n");
        printf("4. Return to Main Menu\n");
        printf(bold_on "Enter your choice: " bold_off);

        if (scanf("%d", &updateChoice) != 1) {
            printf(bold_on "\nInvalid input.\n" bold_off);
            while (getchar() != '\n');
            updateChoice = 0;
            continue;
        }
        while (getchar() != '\n');

        switch(updateChoice) {
            case 1: updateName(roster, index); break;
            case 2: updateGender(roster, index); break;
            case 3: updateScores(roster, index); break;
            case 4: printf("Returning to main menu...\n"); break;
            default: printf(bold_on "\nInvalid choice. Please try again.\n" bold_off);
        }
    } while (updateChoice != 4);
}

// Helper Functions for Each Field

// Update Name
void updateName(struct Student roster[], int index) {
    printf(bold_on "Enter new name (current: %s): " bold_off, roster[index].name);
    scanf(" %49[^\n]%*c", roster[index].name);
    printf(bold_on "\nName updated successfully.\n" bold_off);
}

// Update Gender
void updateGender(struct Student roster[], int index) {
    printf(bold_on "Enter new gender (current: %s): " bold_off, roster[index].gender);
    scanf(" %9[^\n]%*c", roster[index].gender);
    printf(bold_on "\nGender updated successfully.\n" bold_off);
}

// Update Scores
void updateScores(struct Student roster[], int index) {
    printf(bold_on "Enter new scores for %d subjects:\n" bold_off, num_subject);
    float total = 0;
    int validInput = 1;

    for (int j = 0; j < num_subject; j++) {
        printf("  Subject %d (current: %.2f): ", j+1, roster[index].scores[j]);
        if (scanf("%f", &roster[index].scores[j]) != 1) {
            printf(bold_on "\nInvalid score input.\n" bold_off);
            validInput = 0;
            while (getchar() != '\n');
            break;
        }

        // Validate score range
        if (roster[index].scores[j] < 0 || roster[index].scores[j] > 100) {
            printf(bold_on "\nScore must be between 0 and 100.\n" bold_off);
            validInput = 0;
            break;
        }

        total += roster[index].scores[j];
    }

    if (validInput) {
        // Update average and grade
        roster[index].average = total / num_subject;

        if (roster[index].average >= 90) {
            strcpy(roster[index].grade, "A");
        } else if (roster[index].average >= 80) {
            strcpy(roster[index].grade, "B");
        } else if (roster[index].average >= 70) {
            strcpy(roster[index].grade, "C");
        } else if (roster[index].average >= 60) {
            strcpy(roster[index].grade, "D");
        } else {
            strcpy(roster[index].grade, "F");
        }

        printf(bold_on "\nScores, average, and grade updated successfully.\n" bold_off);
    }
}
