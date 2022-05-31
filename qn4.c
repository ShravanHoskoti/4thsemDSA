#include<stdio.h>
struct student{
   int rn;
   float marks;
};
typedef struct student st;
void read(st s[100],int n);
void avg(st s[100],int n);
void main()
{
    st s[100];
    int n=10;
    read(s,n);
    avg(s,n);
}
void read(st s[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the students roll no & marks scored: \n");
        scanf("%d %f",&s[i].rn,&s[i].marks);
    }
}
void avg(st s[100],int n)
{
    int i,sum=0,avg,x=0,y=0;
    for(i=0;i<n;i++)
    {
        sum=sum+s[i].marks;
    }
    avg=sum/n;
    printf("Average of class is %d\n",avg);
    for(i=0;i<n;i++)
    {
        if(s[i].marks>avg)
        {
            x=x+1;
        }
        else if(s[i].marks<avg)
        {
            y=y+1;
        }
    }
    printf("Total no of students above avg: %d\n",x);
    printf("Total no of students below avg: %d\n",y);
}
