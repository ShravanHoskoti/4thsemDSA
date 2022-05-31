#include<stdio.h>
void read(int a[100],int n);
void isequi(int a[100],int n);
void main()
{
    int n;
    int a[100];
    printf("Enter the no: \n");
    scanf("%d",&n);
    read(a,n);
    isequi(a,n);
}
void read(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the array elements: \n");
        scanf("%d",&a[i]);
    }
}
void isequi(int a[100],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        int sum1=0,sum2=0;
        for(j=(i-1);j>=0;j--)
        {
            sum1=sum1+a[j];
        }

        for(j=(i+1);j<n;j++)
        {
            sum2=sum2+a[j];
        }

        if(sum1==sum2)
        {
            printf("The number %d with index %d is at equilibrium\n",a[i],i);
            break;
        }

    }
}
