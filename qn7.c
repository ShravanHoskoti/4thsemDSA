#include<stdio.h>
void read(int a[100],int n);
void cal(int a[100],int n);
void main()
{
    int n;
    long int a[100];
    printf("Enter the no of tax payers: \n");
    scanf("%d",&n);
    read(a,n);
    cal(a,n);
}
void read(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the amount of tax paid: \n");
        scanf("%d",&a[i]);
    }
}
void cal(int a[100],int n)
{
    int i,x=0,y=0,sum=0,avg;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
        if(a[i]>=250000)
        {
            x=x+1;
        }
        else if(a[i]>=50000 && a[i]<=150000)
        {
            y=y+1;
        }
    }
    printf("No of tax payes who paid more than 2.5L : %d\n",x);
    printf("No of tax payes who paid between 50k and 1.5L : %d\n",y);
    avg=sum/n;
    printf("Average tax paid : %d",avg);

}
