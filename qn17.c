#include<stdio.h>
void read(int a[100],int b[100],int n);
void ex(int a[100],int b[100],int n);
void main()
{
    int n;
    int a[100],b[100];
    printf("Enter the no: \n");
    scanf("%d",&n);
    read(a,b,n);
    ex(a,b,n);
}
void read(int a[100],int b[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the elements of array A: \n");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the elements of array B: \n");
        scanf("%d",&b[i]);
    }
}
void ex(int a[100],int b[100],int n)
{
    int i,c[100];
    for(i=0;i<n;i++)
    {
        c[i]=a[i];
        a[i]=b[i];
        b[i]=c[i];
    }
    printf("Array A: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    printf("Array B: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",b[i]);
    }
}
