#include<stdio.h>
void read(int a[100],int n);
void odd_even(int a[100],int n);
void ofo(int a[100],int n);
void main()
{
    int n;
    int a[100];
    printf("Enter the total no of students: \n");
    scanf("%d",&n);
    read(a,n);
    odd_even(a,n);
    ofo(a,n);
}
void read(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the marks: \n");
        scanf("%d",&a[i]);
    }
}
void odd_even(int a[100],int n)
{
    int i,x=0,y=0;
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
          x=x+1;
        }
        else{
            y=y+1;
        }
    }
    printf("No of students who scored even marks are: %d\n",x);
    printf("No of students who scored odd marks are: %d\n",y);
}
void ofo(int a[100],int n)
{
    int i,x=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==10)
        {
            printf("%d Student has scored 100%!!\n",i+1);
            x=x+1;
        }
    }
    printf("No of students who scored 100 marks are: %d\n",x);
}
