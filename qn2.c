#include<stdio.h>
int read(int a[100],int n);
void search(int a[100],int n);
void main()
{
    int a[100];
    int n;
    printf("Enter the amount of numbers: \n");
    scanf("%d",&n);
    read(a,n);
    search(a,n);
}
int read(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the no: \n");
        scanf("%d",&a[i]);
    }
    return a[i];
}
void search(int a[100],int n)
{
    int i,x,flag;
    printf("Enter the key no to be found: ");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
          printf("The key is present in the array!\n");
          printf("Index of the array is %d \n",i);
          flag=1;
        }
    }
    if(flag!=1)
        printf("Key isn't present\n");
}
