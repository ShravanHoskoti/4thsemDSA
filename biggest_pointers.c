#include<stdio.h>
void big(int *p,int *q);
void main()
{
    int *p,*q,a,b;
    printf("Enter 2 no: \n");
    scanf("%d%d",&a,&b);
    p=&a;
    q=&b;
    big(p,q);
}
void big(int *p,int *q)
{
    int x;
    if(*p>*q)
    {
        x=*p;
    }
    else{
        x=*q;
    }
    printf("The biggest no is: %d\n",x);
}
