#ifndef Student_h
#define Student_h

#define max_student 100 // 100 Max structure for student list 
#define num_subject 3 // Number of subjects

struct Student {
    int id;
    char name[50];
    char gender[10];
    float scores[num_subject];
    float average;
    char grade[5];
};

// Function declarations / prototypes
void addStudent(struct Student roster[], int *count); // add.c
void searchStudent(struct Student roster[], int count); // search.c
void updateStudent(struct Student roster[], int count); // update.c
void deleteStudent(struct Student roster[], int *count); // delete.c
void displayStudents(struct Student roster[], int count); // display.c

// file_handler.c
void saveToFile(struct Student roster[], int count);
void loadFromFile(struct Student roster[], int *count);

#endif