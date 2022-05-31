#include<stdio.h>
struct employee{
  int id;
  int exp;
};
typedef struct employee em;
void read(em p[100],int n);
void salary(em p[100],int n);
void main()
{
    em p[100];
    int n;
    printf("Enter the no of employees: \n");
    scanf("%d",&n);
    read(p,n);
    salary(p,n);
}
void read(em p[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter employee ID, Experience: ");
        scanf("%d %d",&p[i].id,&p[i].exp);
    }
}
void salary(em p[100],int n)
{
   int i,net,bs,bonus;
   for(i=0;i<n;i++)
   {
      if(p[i].exp>=5 && p[i].exp<=7)
      {
        bs=10600;
        printf("Basic salary = %d\n",bs);
        net=(bs*0.1)+bs;
        bonus=bs*0.1;
        printf("Bonus: %d\n",bonus);
        printf("Net salary of employee %d id is %d\n",p[i].id,net);
      }
      else if(p[i].exp>=8 && p[i].exp<=10)
      {
        bs=21300;
        printf("Basic salary = %d\n",bs);
        net=(bs*0.2)+bs;
        bonus=bs*0.2;
        printf("Bonus: %d\n",bonus);
        printf("Net salary of employee %d id is %d\n",p[i].id,net);
      }
      if(p[i].exp>10)
      {
        bs=32100;
        printf("Basic salary = %d\n",bs);
        net=(bs*0.3)+bs;
        bonus=bs*0.3;
        printf("Bonus: %d\n",bonus);
        printf("Net salary of employee %d id is %d\n",p[i].id,net);
      }
   }
}
