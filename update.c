#include <stdio.h>
#include <string.h>
#include "student.h"

void updateStudent(struct Student roster[], int count)
{

    if (count == 0)
    {
        printf("  [!] No students to update.\n");
        return;
    }

    int searchID, i, found = -1;
    printf("\nEnter Student ID to update: ");
    scanf("%d", &searchID);
    while (getchar() != '\n')
        ;

    for (i = 0; i < count; i++)
    {
        if (roster[i].id == searchID)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("  [!] Student ID %d not found.\n", searchID);
        return;
    }

    struct Student *s = &roster[found];

    printf("New Name   (current: %s): ", s->name);
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0';

    printf("New Gender (current: %s): ", s->gender);
    fgets(s->gender, sizeof(s->gender), stdin);
    s->gender[strcspn(s->gender, "\n")] = '\0';

    float total = 0.0f;
    for (i = 0; i < num_subject; i++)
    {
        printf("New Score %d (current: %.2f): ", i + 1, s->scores[i]);
        scanf("%f", &s->scores[i]);
        total += s->scores[i];
    }
    while (getchar() != '\n')
        ;

    s->average = total / num_subject;

    if (s->average >= 90.0f)
        strcpy(s->grade, "A");
    else if (s->average >= 80.0f)
        strcpy(s->grade, "B");
    else if (s->average >= 70.0f)
        strcpy(s->grade, "C");
    else if (s->average >= 60.0f)
        strcpy(s->grade, "D");
    else
        strcpy(s->grade, "F");

    printf("\n  [+] Student updated! Avg: %.2f | Grade: %s\n\n",
           s->average, s->grade);
}

