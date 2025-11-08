#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first, PPNODE last, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;
    if((NULL == *first) && (NULL == *last))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
    (*last)->next = *first;
}

void InsertLast(PPNODE first, PPNODE last, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;
    if((NULL == *first) && (NULL == *last))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;
        *last = newn;
    }
    (*last)->next = *first;

}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;
    if((NULL == first) && (NULL == last))
    {
        return 0;
    }
    
    do
    {
        iCount++;
        first = first->next;
    } while (first != last->next);
    
    return iCount;
}

void InsertAtPos(PPNODE first, PPNODE last, int No, int Pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCount = 0;
    
    iCount = Count(*first,*last);
    
    if((1 > Pos) || (Pos > (iCount + 1)))
    {
        printf("Invalid position\n");
        return;
    }

    if(1 == Pos)
    {
        InsertFirst(first,last,No);
    }
    else if((iCount + 1) == Pos)
    {
        InsertLast(first,last,No);
    }
    else 
    {

        newn = (PNODE)malloc(sizeof(NODE));
    
        newn->data = No;
        newn->next = NULL;
        
        temp = *first;

        for(int iCnt = 1; iCnt < (Pos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE first, PPNODE last)
{
    if((NULL == *first) && (NULL == *last))
    {
        return;
    }
    else if(*last == *first)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*last)->next);
        (*last)->next = *first;
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;
    if((NULL == *first) && (NULL == *last))
    {
        return;
    }
    
    if(*last == *first)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;
        while(temp->next != *last)
        {
            temp = temp->next;
        }
        free(*last);
        *last = temp;
        
        (*last)->next = *first;
        /*
        free(temp->next);
        *last = temp;
        (*last)->next = *first;
        */
    }
}

void DeleteAtPos(PPNODE first, PPNODE last, int Pos)
{
    int iCount = 0;
    iCount = Count(*first,*last);
    if((1 > Pos) || (Pos > iCount))
    {
        printf("Invalid position\n");
        return;
    }

    if(1 == Pos)
    {
        DeleteFirst(first,last);
    }
    else if(iCount == Pos)
    {
        DeleteLast(first,last);
    }
    else
    {
        PNODE temp = NULL, target = NULL;
        temp = *first;
        for(int iCnt = 1; iCnt < (Pos - 1); iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}

void Display(PNODE first, PNODE last)
{
    if((NULL == first) && (NULL == last))
    {
        return;
    }
    else
    {
        do
        {
            printf("| %d | -> ",first->data);
            first = first->next;
        }while(first != last->next);
    }
    printf("\n");
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);
    InsertAtPos(&head,&tail,105,5);

    Display(head,tail);

    DeleteAtPos(&head,&tail,5);
    Display(head,tail);
    printf("%d\n",Count(head,tail));

    return 0;
}