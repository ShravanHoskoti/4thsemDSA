#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;

};
typedef struct Node *node;
node insert_rear(node head);
node getnode();
node swap(node head);
void display_list(node head);
main()
{
	node head = NULL;
	int item,choice;
	while(1)
	{
	printf("1-Insert Rear\n2-Display\n3-Swap \n4-Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
    case 1: head=insert_rear(head);
            break;
    case 2: printf("Display List Inserted\n");
            display_list(head);
            break;
    case 3 : swap(head);
    break;
    case 4:exit(0);

}}}

node getnode()
{
	node t;
	int item;
	t=(node *)malloc(sizeof(struct Node));
	if(t==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
	printf("Enter item to be Inserted: \n");
    scanf("%d",&item);
    t->data = item;
	t->next = NULL;
	return t;
}

void display_list(node head)
{
	node t;
	if(head==NULL)
	{
		printf("Empty List\n");
		return;
	}
	printf("elements are\n");
	t=head;
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t= t->next;
	}
	printf("\n");
}
node insert_rear(node head)
{
	node new,c;
	new=getnode();
    if(head == NULL)
	  return new;
	c=head;
	while(c->next!=NULL)
	{
		c=c->next;
	}
	c->next = new;
	return head;
}
node swap(node head)
{
    node cur,prev;
    cur=head;
    prev=NULL;
    while(cur!=NULL && cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
        int a;
        a=prev->data;
        prev->data=cur->data;
        cur->data=a;
        cur=cur->next;
        prev=cur;
    }
    return head;
}
