// #include<stdio.h>
// void   Addition(int *a,int *b,int *c)
// {
//     *c=*a+*b;
// }


// int main()
// {
//     int a,b,c;
//     printf("Enter two numbers:");
//     scanf("%d %d",&a ,&b);

//     Addition(&a,&b,&c);

//     printf("%d+%d=%d",a,b,c);

//     return 0;
// }

//  <><><><><><><><><><>        METHOD 2    <><><><><><><><><><>         

#include<stdio.h>
void   Addition(int a,int b,int *c)
{
    *c=a+b;
}


int main()
{
    int a,b,c;
    printf("Enter two numbers:");
    scanf("%d %d",&a ,&b);

    Addition(a,b,&c);

    printf("%d+%d=%d",a,b,c);

    return 0;
}