//Singly Linear Linked List
// | 11 |->| 21 |->| 51 |->| 101 |->NULL

#include<stdio.h>
#include<stdlib.h>
/////////////////////////////////////////////////////////////////
struct node
{
    int data;
    struct node *next;
};
/////////////////////////////////////////////////////////////////
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;
/////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;
    
    newn = (PNODE) malloc (sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    
    if(NULL == *first)
    {
        // LL is empty
        *first = newn;
    }
    else
    {   
        // LL contains atleast 1 node
        newn->next = *first;
        *first = newn;
    }
}
/////////////////////////////////////////////////////////////////
void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    
    newn = (PNODE) malloc (sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    
    if(NULL == *first)
    {
        // LL is empty
        *first = newn;
    }
    else
    {   
        // LL contains atleast 1 node
        temp = *first;
        while(NULL != temp -> next)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}
/////////////////////////////////////////////////////////////////
void Display(PNODE first)
{
    while(NULL != first)
    {
        printf("| %d | -> ",first->data);
        first = first -> next;
    }
    printf("NULL\n");
}
/////////////////////////////////////////////////////////////////
int Count(PNODE first)
{
    int iCount = 0;
    while(NULL != first)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}
/////////////////////////////////////////////////////////////////
int main()
{
    PNODE head = NULL;
    auto int iRet = 0;
   
    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);
    iRet = Count(head);
    printf("number of elements in the linked list are :%d\n",iRet);

    InsertLast(&head,111);
    InsertLast(&head,121);
    InsertLast(&head,151);
    Display(head);
    iRet = Count(head);
    printf("number of elements in the linked list are :%d\n",iRet);
    return 0;
}
/////////////////////////////////////////////////////////////////