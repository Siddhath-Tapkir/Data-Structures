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

void InsertAtPos(PPNODE first, int No, int Pos)
{}

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
        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE first, int Pos)
{}

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


   // DeleteLast(&head);
    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of elements are : %d\n",iRet);
    return 0;
}