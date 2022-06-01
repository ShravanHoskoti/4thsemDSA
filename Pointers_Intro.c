#include<stdio.h>
int main()
{
    int a,b;
    a=10;
    b=9;
    int *p=&a;
    int *q=&b;

    printf("The valve of a is %d",a);
    printf("\nThe valve of a is %d",*p);

    printf("\nAddress of a is %x",&a);
    printf("\nAddress of a is %x",p);

    printf("\nAddress of p is %x",&p);
}