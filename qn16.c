#include<stdio.h>
void read(int a[100],int n);
void rev(int a[100],int n);
void main()
{
    int n;
    int a[100];
    printf("Enter the lenth of array: \n");
    scanf("%d",&n);
    read(a,n);
    rev(a,n);
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
void rev(int a[100],int n)
{
    int i;
    printf("Reversed array is: \n");
    int temp;
    for(int i = 0; i<n/2; i++){
        temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
    for(int i = 0; i < n; i++){
        printf("%d", a[i]);
    }
}
