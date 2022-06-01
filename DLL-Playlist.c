
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20

// Structure 'node' that holds song details
typedef struct node
{
    char name[MAXSIZE];  // Name of song
    char artist[MAXSIZE];  // Artist of song
    char album[MAXSIZE];  // Album of song
    float size;  // Size of the song file

    struct node *next;
    struct node *prev;
}*NODE;  // Self Referring Pointer and Aliasing

//Function Prototyping
NODE getnode();
void PlayerDisplay(NODE playing); // For Player Display
NODE DLLplaySong(NODE head,NODE playing,char key[]); // To play a song
void DLLsearchByArtist(NODE head,char artistname[]); // To Search the songs of an Artist

NODE DLLinsertNodeAtFront(NODE head);
NODE DLLinsertNodeAtPosition(NODE head,int n);
NODE DLLinsertNodeAtEnd(NODE head);
NODE DLLdeleteNodeAtFront(NODE head);
NODE DLLdeleteNodeAtPosition(NODE head,int n);
NODE DLLdeleteNodeAtEnd(NODE head);
void DLLdisplayList(NODE head);


NODE getnode()
{
    NODE newnode;

    newnode=(NODE)malloc(sizeof(struct node));

    if(newnode==NULL){
        printf("Error Creating Node\n");
        exit(0);
    }

    //Pointing previous and next of the node to NULL
    newnode->next=NULL;
    newnode->prev=NULL;

    //Data input

    printf("\nEnter Song Name: ");
    scanf("%s",newnode->name);
    printf("Enter Artist Name: ");
    scanf("%s",newnode->artist);
    printf("Enter Album Name: ");
    scanf("%s",newnode->album);
    printf("Enter audio file size (in MB): ");
    scanf("%f",&newnode->size);


    return newnode;
}

int main()
{
    NODE head=NULL;
    NODE playing=NULL;
    int choice,k,b;
    char key[MAXSIZE],artistname[MAXSIZE];


    do{
        printf(" \n===================== MUSIC PLAYER =====================\n\n");
        PlayerDisplay(playing);
        printf(" \n  =Player operations=\n\n");
        printf(" >Play Song - 1\n");
        //printf(" >Play next Song - 2\n");
        //printf(" >Play previous Song - 3\n");
        printf(" >Search Songs by Artist - 4\n");//Similarly for albums etc.


        printf(" \n  =Playlist operations=\n\n");
        printf(" >Enter the required operation: \n");
        printf(" >Insert node at the front - 5\n");
        printf(" >Insert node at the end - 6\n");
        printf(" >Insert node at a specific position in the List - 7\n");
        printf(" >Delete node at the front - 8\n");
        printf(" >Delete node at a specific position - 9\n");
        printf(" >Delete node at the end - 10\n");
        printf(" >Display created list - 11\n");
        printf(" >Exit - 0\n");
        printf("\n\n >Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 0:
                exit(0);
                break;

            case 5:
                head=DLLinsertNodeAtFront(head);
                break;

            case 6:
                head=DLLinsertNodeAtEnd(head);
                break;
            case 7:
                printf("Enter the position to add a node\n");
                scanf("%d",&b);
                head=DLLinsertNodeAtPosition(head,b);
                break;
            case 8:
                head=DLLdeleteNodeAtFront(head);
                break;

            case 9:
                printf("Enter the position of the node to delete\n");
                scanf("%d",&k);
                head=DLLdeleteNodeAtPosition(head,k);
                break;

            case 10:
                head=DLLdeleteNodeAtEnd(head);
                break;
            case 11:
                DLLdisplayList(head);
                break;

            case 1:
                printf("Enter the Name of the Song you want to Play: ");
                scanf("%s",key);
                playing=DLLplaySong(head,playing,key);
                break;
            case 4:
                printf("Enter the Name of the Artist: ");
                scanf("%s",artistname);
                DLLsearchByArtist(head,artistname);
                break;
        }
      }while(choice!=0);
    return 0;
}
//End of Main Function

//=======================

//Function Definitions

NODE DLLinsertNodeAtEnd(NODE head)
{
    NODE newnode,temp;
    newnode=getnode(); //node created and data inserted

    if(head==NULL)//if new node is the first created node of the list
    {
        printf("\n First Song Added in the List\n");
        printf("===\n\n");
        return newnode;
    }

    //if new node is not the first node in list

    temp=head;//storing head in temp

    while(temp->next!=NULL)//temp traverses from head till null
    {
        temp=temp->next;
    }
    temp->next=newnode; //after the temp reaches the last node, pointing it to the new node
    newnode->prev=temp; //newnode previous points to the temp(second last node after newnode is inserted)

    printf("\n");
    printf(" Song Added at End of the List\n");
    printf("===\n\n");

    return head;
}
//===End of DLLinsertNodeAtEnd===



NODE DLLinsertNodeAtPosition(NODE head,int n)
{
    NODE newnode,temp,p,next1;

    newnode=getnode();

    n=n-1;//n will be the position of node in visible list, so n-1 will be the actual position


    if(head==NULL)//If new node is the first created node of the list
    {
        printf("\n First Song Added in the List\n");
        printf("===\n\n");
        return newnode;
    }

    temp=head;//storing head in temp

    if(n==0)//if position is the first node
    {

        newnode->next=head;//Point next of newnode to initial head
        newnode->prev=NULL;//Point previous of newnode to NULL

        head->prev=newnode;//Point previous of initial head to newnode

        head=newnode;//Making the newnode as the new head

        printf("\n");
        printf(" Song Added at Beginning of the List\n");
        printf("===\n\n");
        return head;
    }

    for(int i=0;(i<n-1)&&temp!=NULL;i++){

        temp=temp->next;

    // If position is more than number of nodes
        if(temp==NULL||temp->next==NULL){

            printf("\n Position is more than number of nodes\n");
            printf("===\n\n");
            return head;
        }
    //At the end of loop temp reaches the previous node from the required position
    }

    //Now
    //Node temp->next is the position where node must be added

    // next1 has pointer of the node which will be pushed from required position
    next1=temp->next;
    //Pointing next of temp to newnode
    temp->next=newnode;

    newnode->prev=temp;//Pointing previous of newnode to temp

    //Pointing next of newnode to next1 node
    newnode->next=next1;

    next1->prev=newnode;//Pointing previous of newnode to temp

    printf("\n Song Added at the required position\n");
    printf("===\n\n");
    return head;
}
//===End of DLLinsertNodeAtPosition===



NODE DLLinsertNodeAtFront(NODE head)
{
    NODE newnode;

    newnode=getnode();

    if(head==NULL)//If new node is the first created node of the list
    {
        printf("\n First Song Added in the List\n");
        printf("===\n\n");
        return newnode;
    }

    newnode->next=head;//Point next of newnode to initial head
    newnode->prev=NULL;//Point previous of newnode to NULL

    head->prev=newnode;//Point previous of initial head to newnode

    head=newnode;//Making the newnode as the new head

    printf("\n");
    printf(" Song Added at Beginning of the List\n");
    printf("===\n\n");
    return head;
}
//===End of DLLinsertNodeAtFront===



NODE DLLdeleteNodeAtEnd(NODE head)
{
    NODE p1,p2;
    if(head==NULL)//no nodes to delete
    {
        printf("\n List is empty\n");
        printf("===\n\n");
        return head;
    }

    p1=head;
    p2=head;
    while(p1->next!=NULL)//temp traverses from head till null
    {
        p2=p1;
        p1=p1->next;
    }
    //after the loop is over p2 is the second last node
    p2->next=NULL;//pointing the second last node to NULL

    p1->prev=NULL;//Pointing previous of p1(last node) to NULL

    free(p1);//deleting the last node

    printf("\nLast Song is deleted\n");
    printf("===\n\n");

    return head;
}
//===End of DLLdeleteNodeAtEnd===



NODE DLLdeleteNodeAtFront(NODE head)
{
    NODE temp;
    if(head==NULL)//no nodes to delete
    {
        printf("\n List is empty\n");
        printf("===\n\n");
        return head;
    }

    temp=head;//storing head in temp

    head=head->next;//Making the next node(making second node as head as the first node will be deleted)

    head->prev=NULL;//Pointing previous of new head to NULL

    free(temp);

    printf("\n First Song is deleted\n");
    printf("===\n\n");

    return head;
}
//===End of DLLdeleteNodeAtFront===



NODE DLLdeleteNodeAtPosition(NODE head,int n)
{
    NODE temp,p;
    NODE next1;
    n=n-1;//n will be the position of node in visible list, so n-1 will be the actual position

    if(head==NULL)//If list is empty
    {
        printf("\n No nodes to delete\n");
        printf("===\n\n");
        return NULL;
    }

    temp=head;//storing head in temp

    if(n==0)//If Node is the first node of the list
    {
        temp=head;//storing head in temp

        head=head->next;//Making second node - head as the first node will be deleted

        head->prev=NULL;//Pointing previous of new head to NULL

        free(temp);

        printf(" First Song is deleted\n");
        printf("===\n\n");
        return head;
    }


    for(int i=0;(i<n-1)&&temp!=NULL;i++){

        temp=temp->next;

    // If position is more than number of nodes
        if (temp==NULL||temp->next==NULL){
            printf("\n\n Position is more than number of nodes\n");
            printf("===\n\n");
            return head;
        }
    //at the end of loop temp reaches the previous node from the required position
    }

    if(temp->next->next!=NULL)//The position of the node to be deleted is NOT the last in the List
    {
        //Now
        // Node p is the node to be deleted
        p=temp->next;

        // next1 has pointer of the node which is next to the deleted node
        next1=p->next;

        //Pointing next and previous of p node to NULL
        p->prev=NULL;
        p->next=NULL;

        //Unlink the node from linked list
        free(p);
        //Pointing temp to the node next to deleted node
        temp->next=next1;

        next1->prev=temp;//Pointing previous of next1 node to temp

        printf("\n Song at the required position is deleted\n");
        printf("===\n\n");
        return head;
    }
    if(temp->next->next==NULL)//The position of the node to be deleted is the last in the List
    {
        //Now p is the last node
        //Node p is the node to be deleted
        p=temp->next;

        // next1 has pointer of the node which is next to the deleted node
        next1=p->next;

        //Pointing next and previous of p node to NULL
        p->prev=NULL;
        //next of p is already pointing to NULL

        //Unlink the node from linked list
        free(p);
        //Pointing next of temp to NULL
        temp->next=NULL;

        printf("\n Song at the Last position is deleted\n");
        printf("===\n\n");
        return head;
    }
    return NULL;
}
//===End of DLLdeleteNodeAtPosition===



void DLLdisplayList(NODE head)
{
    NODE temp;
    int i;
    i=1;
    if(head==NULL)
    {
        printf(" List is empty\n\n");
        return;
    }
    printf("\n===========\n");
    printf(" Doubly Linked List is:\n");

    temp=head;//temp begins from head
    while(temp!=NULL){

        printf("  || ||\n");
        printf("-%d-",i);
        printf("  Song  : %s\n",temp->name);
        printf("  Artist: %s\n",temp->artist);
        printf("  Album : %s\n",temp->album);
        printf("  Audio File Size: %f MB\n",temp->size);
        temp=temp->next;//traverses from head till null
        i++;
    }
    printf("===========\n\n");
}
//===End of DLLdisplayList===


void PlayerDisplay(NODE playing)
{
    if(playing==NULL)
    {
        printf("\n---------------------No Song Playing---------------------\n\n");
    }
    else
    {
        printf("\n\n-----------------------Now Playing---------------------\n\n");
        printf("\n\n-------------------------%s---------------------\n",playing->name);
        printf("                  By:%s                     \n",playing->artist);
        printf("               Album:%s                     \n",playing->album);
    }
}
//===End of Function PlayerDisplay===



NODE DLLplaySong(NODE head,NODE playing,char key[])
{
    NODE temp;

    if(head==NULL)
    {
        printf(" List is empty\n\n");
        return NULL;
    }
    printf("\n===========\n");

    temp=head;//temp begins from head
    while(temp!=NULL){
        if(strcmp(temp->name,key)==0)
        {
            playing=temp;
            printf("\n Song found\n");
            printf("===========\n\n");
            break;
        }
        else
        {
            printf("\n Song not found\n");
            printf("===========\n\n");
            break;
        }
        temp=temp->next;//traverses from head till null
    }
    return playing;
}
//===End of DLLplaySong===



void DLLsearchByArtist(NODE head,char artistname[])
{
    NODE temp;
    int i;
    i=0;
    if(head==NULL)
    {
        printf(" List is empty\n\n");
        return;
    }

    temp=head;//temp begins from head
    while(temp!=NULL){
        if(strcmp(temp->artist,artistname)==0)
        {
            printf("\n  || ||\n");
            printf("  Song  : %s\n",temp->name);
            printf("  Artist: %s\n",temp->artist);
            printf("  Album : %s\n",temp->album);
            printf("  Audio File Size: %f MB\n",temp->size);
            i++;
        }
        temp=temp->next;
    }//traverses from head till null
    if(i==0){
        printf("Artist not found\n\n");
    }
    printf("===========\n\n");

}
//===End of DLLsearchByArtist===



//End of Program
//=====================
