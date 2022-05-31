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
node shift(node head,int k);
void display_list(node head);
main()
{
	node head = NULL;
	int item,choice,k;
	while(1)
	{
	printf("1-Insert Rear\n2-Display\n3-Left shift \n4-Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
    case 1: head=insert_rear(head);
            break;
    case 2: printf("Display List Inserted\n");
            display_list(head);
            break;
    case 3 : printf("Enter the no of shifts: \n");
        scanf("%d",&k);
        shift(head,k);
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
node shift(node head,int k)
{
    node prev,temp,last,cur;
    prev=NULL;
    temp=head;
    last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=temp;
    for(int i=0;i<k;i++)
    {
        prev=head;
        head=head->next;
    }
    cur=head;
    printf("%d",head->data);
    prev->next=NULL;
    printf("--------- The new list is -----------\n");
    display_list(cur);
    exit(0);
}
