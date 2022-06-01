#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * NODE;

NODE getnode();
void read(NODE);
NODE insert(NODE);

NODE getnode()
{
    NODE newn;
    newn = (NODE *)malloc(sizeof(struct node));

    return newn;
}

void read(NODE newn)
{
    printf("Enter the height of candidate:");
    scanf("%d", &newn->data);

    newn->next = NULL;
    newn->prev = NULL;
}

NODE insert(NODE head)
{
    NODE cur = head;
    NODE newn = getnode();
    read(newn);
    if (head == NULL)
    {
        return newn;
    }
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newn;
    newn->prev = cur;
    newn->next = NULL;

    return head;
}

void select(NODE head)
{
    NODE ptr = head;
    int count = 0;
    while (ptr->next != NULL)
    {
        if (ptr->prev == NULL)
        {
            if (ptr->data < 150)
            {
                printf("d", ptr->data);
                count++;
            }
            ptr = ptr->next;
        }
        ptr = ptr->next;

        if (ptr->data > 150 && ptr->data > ptr->prev->data && ptr->data < ptr->next->data)
        {
            printf("%d", ptr->data);
            count++;
        }
        ptr = ptr->next;
    }
    printf("%d\n", count);
}

void main()
{
    int N; // number of candidates
    NODE head = NULL;
    printf("Enter the number of Candidates:");
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        head = insert(head);
    }
    select(head);
}
