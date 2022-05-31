#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct STACK{
int data;
struct STACK *top;
};
typedef struct STACK *s;

s getnode()
{
    s t;
    t=malloc(sizeof(struct STACK));
    t->top=NULL;
    int x;
    printf("Enter the data: \n");
    scanf("%d",&x);
    t->data=x;
    return t;
}
s push(s base)
{
    s cur,new1;
    new1=getnode();
    if(base==NULL)
    {
        base=new1;
        return base;
    }
    else{
            cur=base;
            new1->top=cur;
            base=new1;
            return base;
    }
}
s pop(s base)
{
    s cur,prev=NULL;
    if(base==NULL)
    {
        printf("Empty stack\n");
        return 0;
    }
    else{
        cur=base;
        prev=cur;
        cur=cur->top;
        base=cur;
        prev->top=NULL;
        return base;
    }
}
s print(s base)
{
    s cur;
    cur=base;
    while(cur->top!=NULL)
    {

        printf("%d\n",cur->data);
        cur=cur->top;
    }
     printf("%d\n",cur->data);
    return 0;
}
void main()
{
    s base=NULL;
    int n;
    while(1)
    {
        printf("Enter the choice: 1.Push 2.Pop 3.Print 4.Peek 5.Exit :  \n");
    scanf("%d",&n);
        switch(n)
        {
            case 1:base=push(base);
        break;
        case 2:base=pop(base);
        break;
        case 3:print(base);
        break;
        case 4:exit(0);
        }
    }
}
