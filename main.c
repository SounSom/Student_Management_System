#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

    /*   Cross platform clear screen   */
#ifdef _WIN32
    #define clear_screen() system("cls")    // Windows clear command
#else
    #define clear_screen() system("clear")  // Linux/Mac clear command
#endif

    /*  Bold characters  */
#define bold_on "\x1b[1m"
#define bold_off "\x1b[0m"

int main() {
    struct Student student_list[max_student];   // Max number of students storage list (defined in student.h)
    int student_count = 0;
    int choice;

    // Preload database
    loadFromFile(student_list, &student_count);

    /*   Temporary data for testing   */
    student_list[0].id = 101;
    strcpy(student_list[0].name, "Test Dummy");
    strcpy(student_list[0].gender, "Male");
    student_list[0].scores[0] = 85.0;
    student_list[0].scores[1] = 90.0;
    student_list[0].scores[2] = 95.0;
    student_list[0].average = 90.0;
    strcpy(student_list[0].grade, "A");
    student_count = 1; 

    do {
        clear_screen();
        printf(bold_on "\n==========================================\n");
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
            printf(bold_on "\nInvalid input! Please enter a number!\n" bold_on);
            choice = 0;
            while (getchar() != '\n');
        }
        else {
            while (getchar() != '\n');    // Clear buffer
            
            switch(choice) {
                case 1: //addStudent(student_list, &student_count); // Calls function from add.c
                    break;
                case 2: //searchStudent(student_list, student_count); // Calls function from search.c
                    break;
                case 3: //updateStudent(student_list, student_count); // Calls function from update.c
                    break;
                case 4: deleteStudent(student_list, &student_count); // Calls function from delete.c
                    break;
                case 5: displayStudents(student_list, student_count); // Calls function from display.c
                    break;
                case 6: saveToFile(student_list, student_count); // Calls functions from file_handler.c
                    break;
                default: printf(bold_on "\nInvalid choice.\n" bold_off);
                    break;
            }
        }
        if (choice != 6) {
            printf("\n" bold_on "Press [ENTER] to return to the main menu..." bold_off);
            while (getchar() != '\n'); // Wait for Enter key
        }
    } while(choice != 6);
    return 0;
}