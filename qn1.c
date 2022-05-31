#include<stdio.h>
int read(int a[100],int n);
void freq(int a[100],int n);
void main()
{
    int a[100];
    int n;
    printf("Enter the amount of no: \n");
    scanf("%d",&n);
    read(a,n);
    freq(a,n);
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
void freq(int a[100],int n)
{
    int i,x=0,y=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>0)
        {
          x=x+1;
        }
        else if(a[i]<0)
        {
          y=y+1;
        }
        else{
            printf("Invalid\n");
        }
    }
    printf("Positive no: %d\n",x);
    printf("negative no: %d\n",y);
}

