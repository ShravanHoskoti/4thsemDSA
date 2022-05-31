#include<stdio.h>
struct family{
int month;
int exp;
};
typedef struct family fm;
void read(fm f[100]);
void ml_exp(fm f[100]);
void avg(fm f[100]);
void main()
{
    fm f[100];
    read(f);
    ml_exp(f);
    avg(f);
}
void read(fm f[100])
{
    int i;
    for(i=0;i<12;i++)
    {
        printf("Enter the month no: \n");
        scanf("%d",&f[i].month);
        printf("Enter the expenditure: \n");
        scanf("%d",&f[i].exp);
    }
}
void avg(fm f[100])
{
    int sum=0,i,avg;
    for(i=0;i<12;i++)
    {
        sum=sum+f[i].exp;
    }
    avg=sum/12;
    printf("The average expenditure is: %d\n",avg);
}
void ml_exp(fm f[100])
{
    int i,max,min,x,y;
    max=f[0].exp;
    for(i=1;i<12;i++)
    {
        if(max<f[i].exp)
        {
          max=f[i].exp;
          x=i+1;
        }
    }
    printf("The max expenditure occured in %dth month is %d\n",x,max);
    min=f[0].exp;
    for(i=1;i<12;i++)
    {
        if(min>f[i].exp)
        {
          min=f[i].exp;
          y=i;
        }
    }
    printf("The min expenditure occured in %dth month is %d\n",y,min);
    for(i=0;i<12;i++)
    {
        if(f[i].exp>3500)
        {
            printf("Family has spent more than 3500 in moth %d\n",i+1);
        }
    }
}
