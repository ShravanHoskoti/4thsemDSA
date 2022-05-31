#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 5
struct stack
{
int item[STACKSIZE];
int top;
};
typedef struct stack  STACK;

int isfull(STACK s)
{
    if(s.top==STACKSIZE-1)
    {
        return 1;
    }
    else
        return 0;
}
int isempty(STACK s)
{
    if(s.top==-1)
     {
        return 1;
    }
    else
        return 0;
}
STACK push(STACK s)
{
    if(isfull(s))
    {
        printf("Stack is full\n");
    }
    else{
            int x;
           printf("Enter the data: \n");
           scanf("%d",&x);
           s.top++;
           s.item[s.top]=x;
    }
   return s;
}
STACK pop(STACK s)
{
    if(isempty(s))
    {
        printf("Stack is empty\n");
    }
    else{
        int x;
        x=s.item[s.top];
        s.top=s.top-1;
    }
    return s;
}
void peek(STACK s)
{
    if(isempty(s))
    {
        printf("Empty stack\n");
    }
    else{
        printf("Top= %d\n",s.top+1);
    }
}
void print(STACK s)
{
    if(isempty(s))
    {
        printf("Empty\n");
    }
    else{
        for(int i=s.top;i>=0;i--)
        {
            printf("|%d|\n",s.item[i]);
        }
    }
}
int  main()
{
STACK s;
s.top=-1;
int choice;
while(1)
{
    printf("Enter the choice: 1.Push 2.Pop 3.Print 4.Peek 5.Exit :  \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:s=push(s);
        break;
        case 2:s=pop(s);
        break;
        case 3:print(s);
        break;
        case 4:peek(s);
        break;
        case 5:exit(0);
    }
}
}
