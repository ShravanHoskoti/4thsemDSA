#include<stdio.h>
struct employee{
int id;
char name[5];
};
typedef struct employee em;
void empl(em e[],int n);
void main()
{

    int n;
    printf("Enter the no of employees: \n");
    scanf("%d",&n);
    em e[n];
    empl(e,n);

}
void empl(em e[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("Enter employee name and id: \n");
        scanf("%s %d",e[i].name,&e[i].id);
    }
    for(i=0;i<n;i++)
    {
        printf("The employee name and id:%s\t%d \n",e[i].name,e[i].id);
    }
}
