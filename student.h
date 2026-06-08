#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    int id;
    char name[50];
    char major[50];
    float gpa;
};
void addStudent();
void searchStudent();
void updateStudent();
void deleteStudent();
void saveToFile();
void loadFromFile();

#endif
