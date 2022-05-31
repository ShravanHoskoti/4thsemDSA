#include<stdio.h>
void isperfect(int a[100],int n);
void read(int a[100],int n);
void main()
{
   int n;
   int a[100];
   printf("Enter the no of numbers: \n");
   scanf("%d",&n);
   read(a,n);
   isperfect(a,n);
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
void isperfect(int a[100],int n)
{
    int i,j,x;
    for(i=0;i<n;i++)
    {
        int sum=0;
        x=a[i];
        for(j=1;j<=(x-1);j++)
       {
        if(x%j==0)
        {
            sum=sum+j;
        }
       }
      if(sum==x)
      {
          printf("The no %d is perfect\n",x);
      }
    }

}
