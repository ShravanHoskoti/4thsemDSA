#include<stdio.h>

struct student
{
    int rollNo;
    char name[5];
    float marks;
};
// struct student s;  // global Declaration

void main()

{
    struct student s;
    struct student *ptr=&s;

    printf("Roll number of student is %d",ptr->rollNo);
    printf("\n");

    printf("Name of Student is %s",ptr->name);
    printf("\n");

    printf("Marks of Student is %f",ptr->marks);

}