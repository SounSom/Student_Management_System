#include <stdio.h>
#include "student.h"

#define bold_on "\x1b[1m"
#define bold_off "\x1b[0m"

    // TO DO: Uncomment this after file_handler.c is finished
    // loadFromFile(student_list, &student_count)

int main() {
    struct Student student_list[max_student];   // Max number of students storage list (defined in student.h library)
    int student_count = 0;
    int choice;

    do {
        printf("\n" bold_on "==========================================\n");
        printf("        STUDENT MANAGEMENT SYSTEM         \n");
        printf("==========================================\n" bold_off);
        printf(" 1. Add New Student Record\n");
        printf(" 2. Search Student Record\n");
        printf(" 3. Update Student Record\n");
        printf(" 4. Delete Student Record\n");
        printf(" 5. Display All Active Records\n");
        printf(" 6. Commit Changes & Exit\n");
        printf(bold_on "==========================================\n" bold_off);
        printf("Enter operation choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {    // Checks for number inputs only
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        switch(choice) {
            case 1: addStudent(student_list, &student_count); // Calls function from add.c
                break;
            case 2: searchStudent(student_list, student_count); // Calls function from search.c
                break;
            case 3: updateStudent(student_list, student_count); // Calls function from update.c
                break;
            case 4: deleteStudent(student_list, &student_count); // Calls function from delete.c
                break;
            case 5: displayStudents(student_list, student_count); // Calls function from display.c
                break;
            case 6: saveToFile(student_list, student_count); // Calls function from file_handler.c
                break;
            default: printf("Invalid choice.\n");
                break;
        }
    } while(choice != 6);

    return 0;
}