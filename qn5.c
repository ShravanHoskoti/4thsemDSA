#include<stdio.h>
#include<stdlib.h>
struct library{
  int rn;
  int late_days;
};
typedef struct library li;
void max_min(li L[100],int);
void avg(li L[100],int n);
void read(li L[100],int n);
int main()
{
    li L[100];
    int n;
    printf("Enter the total no of students: \n");
    scanf("%d",&n);
    read(L,n);
    avg(L,n);
    max_min(L,n);
}
void read(li L[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the student's roll no & no of late days: \n");
        scanf("%d %d",&L[i].rn,&L[i].late_days);
    }
}
void avg(li L[100],int n)
{
    int i,sum=0,avg,penulty;
    for(i=0;i<n;i++)
    {
        sum=sum+L[i].late_days;
    }
    penulty=sum*2;
    avg=penulty/n;
    printf("Total penulty: %d\n",penulty);
    printf("Average penulty: %d\n",avg);
}
void max_min(li L[100],int n)
{
    int i,max,min,tomx,tomn;
    max=L[0].late_days;
    for(i=1;i<n;i++)
    {
        if(L[i].late_days>max)
        {
            max=L[i].late_days;
        }
    }
    tomx=max*2;
    printf("Max fine: %d\n",tomx);

    min=L[0].late_days;
    for(i=0;i<n;i++)
    {
        if(min>L[i].late_days)
        {
            min=L[i].late_days;
        }
    }
    tomn=min*2;
    printf("Min fine: %d\n",tomn);
}

