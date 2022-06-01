#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
typedef struct node * NODE;
NODE getnode()
{
    NODE newn;
    newn=(NODE)malloc(sizeof(struct node));
    if(newn==NULL)
        printf("Memory allocation failed\n");
    return newn;
}
void read(NODE head)
{
    NODE newn;
    printf("Enter details\n");
    scanf("%d",&newn->data);
    newn->next=head;
    newn->prev=newn;
}
void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        do
        {
            printf("%d ",cur->data);
            cur=cur->next;
        }while(cur!=head);
    }
}
NODE insert_end(NODE head)
{
    NODE newn=getnode();
    NODE cur=NULL;
    if(head==NULL)
        head=newn;
    else
    {
        cur=head->prev;
        cur->next=newn;
        newn->prev=cur;
        newn->next=head;
        head->prev=newn;
    }
    return head;
}
NODE shift(NODE head)
{
    int k,i;
    NODE cur=head;
    printf("Enter the number of shifts: ");
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        while(cur->next!=head)
        {
            cur->prev->data=cur->data;
            cur->data=cur->next->data;
            cur=cur->next;
        }
    }
}
void main()
{
    NODE head=NULL;
    int choice;
    while(1)
    {
        printf("1.Insert end\n2.display\n3.left shift\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insert_end(head);
                    break;
            case 2: printf("Display list\n");
                    display(head);
            case 3: head=shift(head);
                    break;
            case 4: exit(0);
                    break;
            default:printf("Invalid\n");
        }
    }
}