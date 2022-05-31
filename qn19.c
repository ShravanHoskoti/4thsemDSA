#include<stdio.h>
void read(int a[100],int n);
void bubble_sort(int a[100],int n);
void main()
{
    int n;
    int a[100];
    printf("Enter the no: \n");
    scanf("%d",&n);
    read(a,n);
    bubble_sort(a,n);
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
void bubble_sort(int a[100],int n)
{
    int i,j,x;
    printf("Array A: \n");
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[i]>a[j])
            {
                x=a[i];
                a[i]=a[j];
                a[j]=x;
            }
        }
        printf("%d\t",a[i]);
    }
}
