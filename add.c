#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent(struct Student roster[], int *count) {
    // 1. Check Capacity
    if (*count >= max_student) {
        printf(bold_on "\nError: Database is full. Cannot add more students.\n" bold_off);
        return;
    }

    struct Student newStudent;

    // 2. Get and Validate Student ID
    printf(bold_on "\nEnter Student ID: " bold_off);
    if (scanf("%ld", &newStudent.id) != 1) {
        printf(bold_on "\nInvalid input for ID.\n" bold_off);
        while (getchar() != '\n');
        return;
    }

    // Check for duplicate ID
    for (int i = 0; i < *count; i++) {
        if (roster[i].id == newStudent.id) {
            printf(bold_on "\nError: Student with ID %ld already exists.\n" bold_off, newStudent.id);
            while (getchar() != '\n');
            return;
        }
    }

    // 3. Get Student Information
    while (getchar() != '\n'); // Clear buffer before fgets

    printf(bold_on "Enter Student Name: " bold_off);
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    printf(bold_on "Enter Gender (Male/Female/Other): " bold_off);
    fgets(newStudent.gender, sizeof(newStudent.gender), stdin);
    newStudent.gender[strcspn(newStudent.gender, "\n")] = '\0';

    // 4. Get and Validate Scores
    printf(bold_on "Enter scores for %d subjects:\n" bold_off, num_subject);
    float total = 0;
    int validInput = 1;

    for (int j = 0; j < num_subject; j++) {
        printf("  Subject %d: ", j+1);
        if (scanf("%f", &newStudent.scores[j]) != 1) {
            printf(bold_on "\nInvalid score input.\n" bold_off);
            validInput = 0;
            while (getchar() != '\n');
            break;
        }

        // Validate score range (0-100)
        if (newStudent.scores[j] < 0 || newStudent.scores[j] > 100) {
            printf(bold_on "\nScore must be between 0 and 100.\n" bold_off);
            validInput = 0;
            break;
        }

        total += newStudent.scores[j];
    }

    if (!validInput) {
        return; // Exit if any input was invalid
    }

    // 5. Calculate Average and Grade
    newStudent.average = total / num_subject;

    if (newStudent.average >= 90) {
        strcpy(newStudent.grade, "A");
    } else if (newStudent.average >= 80) {
        strcpy(newStudent.grade, "B");
    } else if (newStudent.average >= 70) {
        strcpy(newStudent.grade, "C");
    } else if (newStudent.average >= 60) {
        strcpy(newStudent.grade, "D");
    } else {
        strcpy(newStudent.grade, "F");
    }

    // 6. Finalize and Confirm
    roster[*count] = newStudent;
    (*count)++;

    printf(bold_on "\nStudent record added successfully!\n" bold_off);
    printf("Student ID: %ld\n", newStudent.id);
    printf("Name: %s\n", newStudent.name);
}
