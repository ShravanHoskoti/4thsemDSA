#include<stdio.h>
#include<stdlib.h>
struct node{
int value;
struct node *lc,*rc;
};
typedef struct node *Node;

Node new_node(int value)
{
    Node temp=(Node*)malloc(sizeof(struct node));
    temp->value=value;
    temp->lc=NULL;
    temp->rc=NULL;
    return temp;
}
Node insert_node(Node root ,int value)
{
    if (root==NULL)
    {
        return new_node(value);
    }
    if(value<root->value)
    {
        root->lc = insert_node(root->lc,value);
    }
    else if(value>root->value)
    {
        root->rc=insert_node(root->rc,value);
    }
    return root;
}
void print(Node root)
{
    if(root!=NULL)
    {
        print(root->lc);
        printf("%d\t",root->value);
        print(root->rc);
    }
}
Node search(Node root,int data) {
    int n;
    Node cur;
    cur=root;
    printf("Enter the data to search\n");
    scanf("%d",&n);
    while(cur!=NULL)
    {
        if(n>cur->value)
        {
        cur=cur->rc;
        if(n==cur->value)
        {
            printf("Found\n");
            exit(0);
        }
        }
        else if(n<cur->value)
        {
            cur=cur->lc;
            if(n==cur->value)
        {
            printf("Found\n");
            exit(0);
        }
        }
    }
}

void main()
{
    Node root=NULL;
   int n,x,key;
    while(1)
    {
        printf("Enter the choice:1.Insert 2.Display 3.Search 4.Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:scanf("%d",&x);
                root=insert_node(root,x);
            break;
            case 2:print(root);
            break;
            case 3:printf("Enter the key to search: \n");
            scanf("%d",&key);
                search(root,key);
            break;
            case 4:exit(0);
        }
    }
}
