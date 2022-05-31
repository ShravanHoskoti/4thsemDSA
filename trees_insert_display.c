#include<stdio.h>
#include<stdlib.h>
struct trees{
int data;
struct trees *lc;
struct trees *rc;
};
typedef struct trees *node;
node insert(node root);
node search(node root);
void main()
{
    node root=NULL;
    int n;
    while(1)
    {
        printf("Enter the choice:1.Insert 2.Display 3.Search 4.Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:root=insert(root);
            break;
            case 2:print(root);
            break;
            case 3:search(root);
            break;
            case 4:exit(0);
        }
    }
}
node getnode()
{
    int item;
    node t;
    t=(node*)malloc(sizeof(struct trees));
    if(t==NULL)
    {
        printf("Tree not created\n");
    }
    printf("Enter the data to insert: \n");
    scanf("%d",&item);
    t->data=item;
    t->lc=NULL;
    t->rc=NULL;
    return t;
}
node insert(node root)
{
    node cur,new1;
    new1=getnode();
    if(root==NULL){
        root=new1;
        return root;
    }
    cur=root;
    while(cur!=NULL)
    {
        if(cur->data>new1->data)
        {
            if(cur->lc!=NULL)
            {
                cur=cur->lc;
            }
            else if(cur->lc==NULL)
            {
                cur->lc=new1;
            }
        }
        else if(cur->data<new1->data)
        {
            if(cur->rc!=NULL)
            {
                cur=cur->rc;
            }
            else if(cur->rc==NULL)
            {
                cur->rc=new1;
            }
        }
    }
}
node search(node root)
{
    int n;
    node cur;
    cur=root;
    printf("Enter the data to search\n");
    scanf("%d",&n);
    while(cur!=NULL)
    {
        if(n>cur->data)
        {
        cur=cur->rc;
        if(n==cur->data)
        {
            printf("Found\n");
            exit(0);
        }
        }
        else if(n<cur->data)
        {
            cur=cur->lc;
            if(n==cur->data)
        {
            printf("Found\n");
            exit(0);
        }
        }
    }
}
void print(node root)
{
    if(root!=NULL)
    {
        print(root->lc);
        printf("%d\t",root->data);
        print(root->rc);
    }
}
