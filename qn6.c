#include<stdio.h>
void read(int a[100],int n);
void asce(int a[100],int n);
void max_min(int a[100],int n);
void main()
{
    int a[100];
    int n;
    printf("Enter the no of students: \n");
    scanf("%d",&n);
    read(a,n);
    asce(a,n);
    max_min(a,n);
}
void read(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the student's ranks: \n");
        scanf("%d",&a[i]);
    }
}
void asce(int a[100],int n)
{
    int i,j,x;
     for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    x =  a[i];
                    a[i] = a[j];
                    a[j] = x;
                }
            }
        }
        printf("The ranks arranged in ascending order are given below \n");
        for (i = 0; i < n; ++i)
            printf("%d\n", a[i]);
}
void max_min(int a[100],int n)
{
    int i,max,min;
    max=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    printf("Lowest rank: %d\n",max);

    min=a[0];
    for(i=1;i<n;i++)
    {
        if(min>a[i])
        {
            min=a[i];
        }
    }
    printf("Highest rank: %d\n",min);
}
