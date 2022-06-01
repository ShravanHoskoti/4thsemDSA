#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char name[20];
    char from[20];
    char to[20];
    float amt;
    int tran;
}TRN;
void read(TRN *t,int n);
void disp(TRN *t,int n);
void details(TRN *t,int n);
void cost(TRN *t, int n);
int main()
{
    TRN *t;
    int n;
    printf("Enter the number of passengers\n");
    scanf("%d",&n);
    t=(TRN*)calloc(n,sizeof(TRN));
    read(t,n);
    disp(t,n);
    details(t,n);
    cost(t,n);
    free(t);
    return 0;
}
void read(TRN *t,int n)
{
    int i;
    printf("Enter the name, from which date, to which date, amount, no of transaction\n");
    for(i=0;i<n;i++)
    {
        scanf("%s%s%s%f%d",t->name,t->from,t->to,&t->amt,&t->tran);
        t++;
    }
}
void disp(TRN *t,int n)
{
    int i;
    printf("Name\tFrom\t\tTo\tAmount\t\tNO.of Transaction\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t%s\t\t%s\t%0.2f\t%d\n",t->name,t->from,t->to,t->amt,t->tran);
        t++;
    }
}
void details(TRN *t,int n)
{
    int i;
    printf("\nDiscount members\n");
    printf("Name\tFrom\t\tTo\tAmount\t\tNo.of Transaction\n");
    for(i=0;i<n;i++)
    {
        if(t->tran==25)
        {
            printf("%s\t%s\t\t%s\t%0.2f\t%d\n",t->name,t->from,t->to,t->amt,t->tran);
        }
        t++;
    }
}
void cost(TRN *t, int n)
{
    int i;
    float b=0.0,c=0.0;
    for(i=0;i<n;i++)
    {
        if(t->tran==25)
        {
            b=t->amt*0.5;
            c=b+c;
        }
        t++;
    }
    printf("\nTotal discount amt: %0.2f",c);
}
