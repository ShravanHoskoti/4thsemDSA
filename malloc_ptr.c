#include<stdio.h>
#include<stdlib.h>
struct employee{
int id;
char name[10];
};
int main()
{
    struct employee *ptr;
    int n;
    printf("Enter the no of employees: \n");
    scanf("%d",&n);
    ptr = (struct employee*)malloc(n*sizeof(struct employee));
    read(ptr,n);
    display(ptr,n);
}
void read(struct employee *ptr,int n)
{
  for(int i=0;i<n;i++)
    {
        printf("Enter the id and name: \n");
        scanf("%d %s",&(ptr+i)->id,(ptr+i)->name);
    }
}
void display(struct employee *ptr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Id :%d, Name: %s\n",(ptr+i)->id,(ptr+i)->name);
    }
}
