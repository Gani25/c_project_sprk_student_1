#include <stdio.h>
#include "student_info.h"

int main()
{
    int choice;

    do
    {

        printf("Enter Choice\n");
        printf("1. Insert Student\n");
        printf("2. Get All Student\n");
        printf("3. Get Student By Roll No\n");
        printf("4. Get Student By Department\n");
        printf("5. Update Student By Roll No\n");
        printf("6. Delete Student By Roll No\n");
        printf("7. Exit:\n");
        scanf("%d", &choice);

        fflush(stdin);

        int numOfStudent;

        switch (choice)
        {
        case 1:
            printf("Enter number of students to be inserted: ");
            scanf("%d", &numOfStudent);
            fflush(stdin);
            for (int i = 1; i <= numOfStudent; i++)
            {

                insertStudent();
            }

            break;
        case 2:
            getAllStudent();
            break;
        case 3:
            getStudentByRollNo();

            break;
        case 4:
            getStudentsByDept();
            break;
        case 5:
            updateByRollNo();
            break;
        case 6:
            deleteByRollNo();
            break;
        case 7:
            printf("Thanks for using student management system.\nVisit again!\n");

            break;

        default:
            printf("Please select correct choice\n");
            break;
        }
    } while (choice != 7);
}
