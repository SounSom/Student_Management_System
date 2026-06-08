#include <stdio.h>
#include "student.h"

// Prototypes (links to the other files)
void addStudent();
void searchStudent();
void updateStudent();
void deleteStudent();
void saveToFile();
void loadFromFile();

int main() {
    int choice;
    loadFromFile(); // Load existing data when program starts

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add\n2. Search\n3. Update\n4. Delete\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: searchStudent(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: saveToFile(); break;
            default: printf("Invalid choice.\n"); break;
        }
    } while(choice != 5);

    return 0;
}
