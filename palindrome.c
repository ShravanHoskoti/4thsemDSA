#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct stack{
char data;
int top;
};
typedef struct stack *stk;
void push(stk top);
void pop(stk top);
void main()
{
    stk top=-1;
    int n;
    while(1)
    {
        printf("Enter the choice: \n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: top=push(top);
            break;
            case 2:pop(top);
            break;
            case 3:display(top);
            break;
        }
    }
}
