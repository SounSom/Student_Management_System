// Display all data of all student 
#include <stdio.h>
#include "student.h"
void displayStudents(struct Student roster[], int count) {
    if (count == 0) {
        printf("\nNo student records to display.\n");
        return;
    }

    printf("\n=================================== ALL STUDENT RECORDS =============================================\n");
    printf("%-12s %-22s %-10s %s\n", "ID", "Name", "Gender", "Grades (5 Subjects)");
    printf("-----------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-12ld %-22s %-10s ",
        roster[i].id,
        roster[i].name,
        roster[i].gender);

        // Print all 3 scores
        for (int j = 0; j < num_subject; j++) {
            printf("%-5.2f ", roster[i].scores[j]);
        }
        printf("| Avg: %-5.2f | Grade: %s\n",
            roster[i].average,
            roster[i].grade);
    }

    printf("=====================================================================================================\n");
    printf("Total Students: %d\n", count);
}