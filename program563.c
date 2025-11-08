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
void DisplayI(PNODE first)
{
    while(NULL != first)
    {
        printf("| %d | -> ",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

void DisplayR(PNODE first)
{
    if(NULL != first)
    {
        printf("| %d | -> ",first->data);
        first = first->next;
        DisplayR(first);    // Tail Recursion
    }
}

void DisplayRX(PNODE first)
{
    if(NULL != first)
    {
        DisplayRX(first->next);    // Head Recursion
        printf("| %d | -> ",first->data);
    }
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
int CountR(PNODE first)
{
    static int iCount = 0;
    if(NULL != first)
    {
        iCount++;
        first = first->next;
        CountR(first);  // Tail Recursion
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
        temp = *first;
        while(NULL != temp->next->next)
        {
            temp = temp->next;
        }
        
        free(temp->next);
        temp->next = NULL;
    }
}
////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE first, int No, int Pos)
{
    auto int iCount = 0, iCnt = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

    iCount = Count(*first);
    if((1 > Pos) || (Pos > (iCount + 1)))
    {
        printf("Invalid position\n");
        return;
    }

    if(1 == Pos)
    {
        InsertFirst(first,No);
    }
    else if((iCount + 1) == Pos)
    {
        InsertLast(first,No);
    }
    else
    {
        
        temp = *first;
        for(iCnt = 1; iCnt <= (Pos - 2); iCnt++)
        {
            temp = temp -> next;
        }
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = No;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;

    }
}
////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE first, int Pos)
{
    auto int iCount = 0, iCnt = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first);
    if((1 > Pos) || (Pos > iCount))
    {
        printf("Invalid position\n");
        return;
    }

    if(1 == Pos)
    {
        DeleteFirst(first);
    }
    else if(iCount == Pos)
    {
        DeleteLast(first);
    }
    else
    {
        
        temp = *first;
        for(iCnt = 1; iCnt <= (Pos - 2); iCnt++)
        {
            temp = temp -> next;
        }
        target = temp->next;
        temp->next = target->next; // temp->next = temp->next->next;
        free(target);
        

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
    DisplayRX(head);
    iRet = CountR(head);
    printf("\nNumber of elements are : %d\n",iRet);

    return 0;
}