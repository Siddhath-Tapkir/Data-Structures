#include<stdio.h>
#include<stdlib.h>
////////////////////////////////////////////////////////////
typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE, **PPNODE;
////////////////////////////////////////////////////////////
void InsertFirst(PPNODE first, int No)
{
    PNODE newn = NULL;
    newn = (PNODE) malloc (sizeof(NODE));
    
    newn->data = No;
    newn->next = NULL;

    newn->next = *first;
    *first = newn;

}
////////////////////////////////////////////////////////////
void InsertLast(PPNODE first, int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE) malloc (sizeof(NODE));
    
    newn->data = No;
    newn->next = NULL;
    
    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while(NULL != temp->next)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    
}
////////////////////////////////////////////////////////////
void Display(PNODE first)
{
    while(NULL != first)
    {
        printf("| %d | -> ",first->data);
        first = first->next;
    }
    printf("NULL\n");
}
////////////////////////////////////////////////////////////
int Count(PNODE first)
{
    auto int iCount = 0;
    while(NULL != first)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}
////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;
    if(NULL == *first) // Empty LL
    {
        return;
    }
    else if(NULL == (*first) -> next) // Single node
    {
        free(*first);
        *first = NULL;
    }
    else // More than one node
    {
        temp = *first;
        *first = (*first)->next;
        
        free(temp);
    }
}
////////////////////////////////////////////////////////////
void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
    if(NULL == *first) // Empty LL
    {
        return;
    }
    else if(NULL == (*first) -> next) // Single node
    {
        free(*first);
        *first = NULL;
    }
    else // More than one node
    {
        
    }
}
////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    auto int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    iRet = Count(head);
    
    printf("Number of elemnets are : %d\n",iRet);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);

    iRet = Count(head);
    
    printf("Number of elemnets are : %d\n",iRet);


    DeleteFirst(&head);

    Display(head);
    
    iRet = Count(head);
    
    printf("Number of elemnets are : %d\n",iRet);
    
    return 0;
}