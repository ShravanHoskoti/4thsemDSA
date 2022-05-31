#include<stdio.h>
void read(int a[100],int n);
void bill(int a[100],int n);
void main()
{
    int n;
    int a[100];
    printf("Enter the no of houses: \n");
    scanf("%d",&n);
    read(a,n);
    bill(a,n);
}
void read(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the no of units consumed: \n");
        scanf("%d",&a[i]);
    }
}
void bill(int a[100],int n)
{
    int i;
    float bill1,bill2,bill3,bill4,net;
    for(i=0;i<n;i++)
    {
        if(a[i]>=0 && a[i]<=100)
        {
          bill1=a[i]*1.5;
        }
        else if(a[i]>=101 && a[i]<=250)
        {
          bill2=a[i]*2.3;
        }
        else if(a[i]>=251 && a[i]<=600)
        {
          bill3=a[i]*4.0;
        }
        else if(a[i]>600)
        {
          bill1=a[i]*5.5;
        }
    }
    net=bill1+bill2+bill3+bill4;
    printf("The net bill is %f",net);
}
