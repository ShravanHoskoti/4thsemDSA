#include<stdio.h>
#include<stdlib.h>
struct Node{
int height;
struct Node *next;
struct Node *prev;
};
typedef struct Node *node;
node getnode()
{
    node t;
    int height;
    t=(node)malloc(sizeof(struct Node));
    scanf("%d",&t->height);
    t->prev=NULL;
    t->next=NULL;
    return t;
}
node insert(node head)
{
    node cur,new1;
    new1=getnode();
    cur=head;
    if(head == NULL)
	  return new1;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=new1;
    new1->prev=cur;
    return head;
}
node check(node head)
{
    node cur,prev,temp,x,y;
    prev=NULL;
    int count=0;
    x=head->next;
    y=head;
    if(y->height<= x->height)
    {
        printf("%d\t",head->height);
        count=count+1;
    }
    cur=head->next;
    while(cur->next!=NULL)
    {
        prev=cur->prev;
        temp=cur->next;
        if(cur->height<= temp->height && cur->height >= prev->height)
        {
            printf("%d\t",cur->height);
            count++;
        }
        cur=cur->next;
    }
    if(cur->height>=150 && cur->height>= prev->height)
    {
        printf("%d\t",cur->height);
        count=count+1;
    }
    printf("%d\n",count);
}
void main(){
    node head=NULL;
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
    head=insert(head);
    n=n-1;
    }
    check(head);
}
