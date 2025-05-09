// Structure Store in Binary Format
#include <stdio.h>

#define MAX_SIZE 100
#define MAX_MARKS 5
#define FILE_NAME "student_info.txt"
char SUBJECTS[MAX_MARKS][10] = {"ENGLISH", "MATHS", "SCIENCE", "HINDI", "MARATHI"};

typedef struct student_info
{
    int rollNo;
    char name[MAX_SIZE];
    int marks[MAX_MARKS];
    char department[MAX_SIZE];
} Student;
#define STUDENT_SIZE sizeof(Student)

void insertStudent();
void getStudentByRollNo();
Student getByRollNo(int rollNo);
void getAllStudent();
void display(Student student);
void acceptStudentData(Student *studRef);

void insertStudent()
{
    FILE *fptr = fopen(FILE_NAME, "ab");
    Student s1;
    printf("Enter roll no: ");
    scanf("%d", &s1.rollNo);
    fflush(stdin);
    // first check if rollNo already exists then do not insert

    Student existingStudent = getByRollNo(s1.rollNo);
    if (existingStudent.rollNo != -1)
    {
        printf("Student with roll no = %d already exists\n", s1.rollNo);
        return;
    }
    printf("Enter name: ");
    fgets(s1.name, MAX_SIZE, stdin);

    fflush(stdin);
    printf("Enter department: ");
    fgets(s1.department, MAX_SIZE, stdin);
    fflush(stdin);

    // INPUT OF MARKS
    for (int i = 0; i < MAX_MARKS; i++)
    {
        printf("Enter marks of subject %s: ", SUBJECTS[i]);
        scanf("%d", &s1.marks[i]);
    }
    fwrite(&s1, STUDENT_SIZE, 1, fptr);
    printf("Student with roll no = %d saved successfully\n", s1.rollNo);

    fclose(fptr);
}
void getStudentByRollNo()
{
    int rollNo;
    printf("Enter rollno: ");
    scanf("%d", &rollNo);

    fflush(stdin);

    Student s1 = getByRollNo(rollNo);
    if (s1.rollNo == -1)
    {
        printf("Student with roll no = %d not found in our records\n", s1.rollNo);
    }
    else
    {
        display(s1);
    }
}
Student getByRollNo(int rollNo)
{
    FILE *fptr = fopen(FILE_NAME, "rb");

    int flag = 0;
    Student s1;
    while (fread(&s1, STUDENT_SIZE, 1, fptr) > 0)
    {
        if (rollNo == s1.rollNo)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        s1.rollNo = -1;
    }

    fclose(fptr);
    return s1;
}

void getAllStudent()
{
    FILE *fptr = fopen(FILE_NAME, "rb");

    Student s1;
    while (fread(&s1, STUDENT_SIZE, 1, fptr))
    {
        display(s1);
    }
}

void display(Student student)
{

    printf("\n---------------------------------------------\n");
    printf("Student Info\n");
    printf("Roll No = %d\n", student.rollNo);
    printf("Name = %s", student.name);
    printf("Department = %s", student.department);
    printf("Marks are: \n");
    for (int i = 0; i < MAX_MARKS; i++)
    {
        printf("%s = %d\n", SUBJECTS[i], student.marks[i]);
    }

    printf("---------------------------------------------\n");
}

void acceptStudentData(Student *studRef)
{
}
