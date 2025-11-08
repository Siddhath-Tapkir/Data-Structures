#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node *prev;      // $
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE first)
{
    printf("NULL<=>");

    while(NULL != first)
    {
        printf("| %d |<=>",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

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

void InsertFirst(PPNODE first, int No)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;    // $
    
    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;   // $
        *first = newn;
    }

}

void InsertLast(PPNODE first, int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE) malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;    // $
    
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
        newn->prev = temp;  // $
        temp->next = newn;
        
    }
}

void DeleteFirst(PPNODE first)
{
    if(NULL == *first)
    {
        return;
    }
    else if(NULL == (*first)->next)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        // WITH TEMP VARIBLE
        *first = (*first)->next;
        free((*first)->prev);
        (*first)->prev = NULL; 
    }
}

void DeleteLast(PPNODE first)
{
    if(NULL == *first)
    {
        return;
    }
    else if(NULL == (*first)->next)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        PNODE temp = *first;
        while(temp->next != NULL) // change
        {
            temp = temp -> next;
        }
        temp->prev->next = NULL; // $
        free(temp);
    }
}

void DeleteAtPos(PPNODE first, int Pos)
{
    int iCount = 0, iCnt = 0;
    
    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first);
    if((1 > Pos) || (Pos > iCount))
    {
        printf("Invalid position\n");
        return;
    }

    if(Pos == 1)
    {
        DeleteFirst(first);
    }
    else if(Pos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;
        for(iCnt = 1; iCnt < (Pos - 1); iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp; // $
        
        free(target);
    }
}

void InsertAtPos(PPNODE first, int No, int Pos)
{
    int iCount = 0, iCnt = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count(*first);
    if((1 > Pos) || (Pos > (iCount + 1)))
    {
        printf("Invalid position\n");
        return;
    }

    if(Pos == 1)
    {
        InsertFirst(first,No);
    }
    else if(Pos == (iCount + 1))
    {
        InsertLast(first,No);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;
        for(iCnt = 1; iCnt < (Pos - 1); iCnt++)
        {
            temp = temp -> next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;    //$
        temp->next = newn;
        newn->prev = temp;      //$
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    InsertAtPos(&head,105,5);

    Display(head);
    iRet = Count(head);
    printf("Number of elements are : %d\n",iRet);


    DeleteAtPos(&head,5);

    Display(head);
    iRet = Count(head);
    printf("Number of elements are : %d\n",iRet);
    return 0;
}