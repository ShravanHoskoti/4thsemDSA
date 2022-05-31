#include<stdio.h>
#include<string.h>
void read(int a[100],int n);
void sum(int a[100],int n);
void main()
{
    int n;
    int a[100];
    printf("Enter the no of numbers: \n");
    scanf("%d",&n);
    read(a,n);
    sum(a,n);
}
void read(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the array elements: \n");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("The array elements are: %d\n",a[i]);
    }
}
void sum(int a[100],int n)
{
    int i,j,k,x,y,max,sum=0,b[100];
    for(i=0;i<n;i++)
    {
        x=a[i];
        for(j=0;j<n;j++)
        {
            y=x%10;
            x=x/10;
            b[j]=y;
        }
        max=b[0];
        for(k=1;k<3;k++)
        {
            if(b[k]>max)
            {
                max=b[k];
            }
        }
        sum=sum+max;
    }
    printf("Sum=%d\n",sum);

}
