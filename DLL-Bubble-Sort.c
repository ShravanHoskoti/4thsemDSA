//Bubble Sort - Doubly Linked List

/*

11-December-2021

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node //Declaring a structure for a node comprising of an integer
{
    int k;
    struct node *next;
    struct node *prev;
}*NODE;//Self Referential Aliasing

NODE DLLinsertNodeAtFront(NODE head);
NODE DLLinsertNodeAtEnd(NODE head);
NODE DLLdeleteNode(NODE head,int n);
void DLLdisplay(NODE head);
int DLL_Bubble_Sort(NODE head);
void Swap(int *a,int *b);
void isDLL_Increasing(NODE head);
void isDLL_Decreasing(NODE head);

//Function returns a node with an integer input by the user
NODE getnode()
{
    NODE newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    
    if(newnode==NULL){
        printf("\n  === Memory Allocation Error === \n");
        exit(0);
    }

    //Pointing previous and next of the node to NULL
    newnode->next=NULL;
    newnode->prev=NULL;

    //Data input

    printf("\n  -->Enter Integer to insert in the node: ");
    scanf("%d",&newnode->k);


    return newnode;
}

int main()
{
    NODE head=NULL;
    int choice,n,count=0;

    while(1){
        DLLdisplay(head);

        printf("\n  ===> DLL Operations <===\n\n");
        printf("  > 1 = Insert Integer at Last\n");
        printf("  > 2 = Insert Integer at Front\n");
        //printf("Deletion");
        printf("  > 4 = Bubble Sort DLL\n");
        printf("  > 5 = Check Increasing Order\n");
        printf("  > 6 = Check Decreasing Order\n");
        printf("  > 0 = Exit\n");
        printf("\n  -->Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:     printf("\n\n  ==> Choice Entered 'Exit'\n\n");
                        exit(0);
                        break;
            case 1:     head=DLLinsertNodeAtEnd(head);
                        break;
            case 2:     head=DLLinsertNodeAtFront(head);
                        break;
            /*case 3:   head=DLLdeleteNode(head,n);
                        break;*/
            case 4:     count=DLL_Bubble_Sort(head);
                        printf("  ==> No. of Swaps = %d\n",count);
                        break;
            case 5:     isDLL_Increasing(head);
                        break;
            case 6:     isDLL_Decreasing(head);
                        break;
            default:    printf("\n  === Choice Entered is Invalid ===\n");
                        break;
        }//End of Switch
    }//End of while
}//End of Main

//Function to Insert Node at front in a DLL
NODE DLLinsertNodeAtFront(NODE head)
{
    NODE newnode;

    newnode=getnode(); //node created and data inserted

    //If new node is the first created node of the list
    if(head==NULL)
    {
        printf("\n  ==> First Node Inserted in the List\n");
        return newnode;
    }

    //if new node is not the first node in list

    newnode->next=head; //Point next of newnode to initial head
    newnode->prev=NULL; //Point previous of newnode to NULL

    head->prev=newnode; //Point previous of initial head to newnode

    head=newnode; //Making the newnode as the new head

    printf("\n  ==> Node Inserted in Front of the List\n");
    return head;
}

//Function to Insert Node at End in a DLL
NODE DLLinsertNodeAtEnd(NODE head)
{
    NODE newnode,temp;

    newnode=getnode(); //node created and data inserted

    //If new node is the first created node of the list
    if(head==NULL)
    {
        printf("\n  ==> First Node Inserted in the List\n");
        return newnode;
    }

    //if new node is not the first node in list

    temp=head; //storing head in temp

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newnode; //after the temp reaches the last node, pointing next of temp to the new node
    newnode->prev=temp; //newnode previous points to the temp(second last node after newnode is inserted)

    printf("\n  ==> Node Inserted in End of the List\n");

    return head;
}

//Function to Delete Node which contains an integer input by the user
NODE DLLdeleteNode(NODE head,int n)
{

}

//Function to Display a DLL
void DLLdisplay(NODE head)
{
    NODE temp=head;
    
    printf("\n --- DLL of Integers:\n");

    if(head==NULL){
        printf("\n  ==> List is Empty\n");
    }
    else{
        printf("  Head\n");
        printf("  |\n");
        printf("  v\n");
        printf("  ");
        while(temp!=NULL){
            printf("%d  ",temp->k);
            temp=temp->next;
        }
    }
}

//Function to Bubble Sort a DLL
int DLL_Bubble_Sort(NODE head)
{
    int swapped, c=0;
    NODE temp1;
    NODE temp2=NULL;
  
    //Checking for empty list
    if(head==NULL){
        printf("\n  ==> List is Empty, No elements to Sort\n");
        return (0);
    }

    //Sorting takes place from End to Front
    do{
        swapped=0;
        temp1=head;
  
        while(temp1->next!=temp2){

            if((temp1->k)>(temp1->next->k)){
                Swap(&(temp1->k),&(temp1->next->k));
                c++;
                swapped=1; //If there are no swaps then value of swapped will be 0, implies List is Sorted
            }

            temp1=temp1->next;
        }

        temp2=temp1;
        //temp2 starts from end of the list and comes forward
        //Elements are in Sorted Order from behind till temp2
    }while(swapped);

    printf("\n  ==> Bubble Sort Complete\n");
    return(c);
}

//Function to Swap
void Swap(int *a,int *b)
{
	int temp;
    
	temp=*a;
	*a=*b;
	*b=temp;
}

//Function returns True if DLL is in Increasing Order
void isDLL_Increasing(NODE head)
{  
    NODE temp;
    int c=0;
    temp=head;

    if(head==NULL){
        printf("\n  ==> List is Empty, No elements to Check\n");
        return;
    }

    while(temp->next!=NULL){

        if ((temp->k)>(temp->next->k)){
            c=1;
            break;
        }

    temp=temp->next;
    }

    if(c==0){
        printf("\n  ==> List is in Increasing Order\n");
    }
    else{
    printf("\n  ==> List is NOT in Increasing Order\n");
    }
}

//Function returns True if DLL is in Decreasing Order
void isDLL_Decreasing(NODE head)
{  
    NODE temp;
    int c=0;
    temp=head;

    if(head==NULL){
        printf("\n  ==> List is Empty, No elements to Check\n");
        return;
    }

    while(temp->next!=NULL){

        if ((temp->k)<(temp->next->k)){
            c=1;
            break;
        }

    temp=temp->next;
    }

    if(c==0){
        printf("\n  ==> List is in Decreasing Order\n");
    }
    else{
    printf("\n  ==> List is NOT in Decreasing Order\n");
    }
}





