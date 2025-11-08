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
        newn->next->prev = newn;    // $
        temp->next = newn;
        newn->prev = temp;          // $
    }
}

int main()
{
    int iChoice = 0, iValue = 0, iPos = 0, iRet = 0;
    PNODE head = NULL;
    printf("-----------------------------------------------Sidd-----------------------------------------------\n");
    printf("------------------------------------Doubly Linear Linked List--------------------------------------\n");
    printf("-----------------------------------------------Sidd-----------------------------------------------\n");
    while(1)
    {
        printf("---------------------------------------Please select the option-----------------------------------\n");
        printf("-----------------------------------------------Menu-----------------------------------------------\n");
        printf("-----------------------------------------------Menu-----------------------------------------------\n");
        printf("1 : Insert new node at first position\n");
        printf("2 : Insert new node at last position\n");
        printf("3 : Insert new node at given position\n");
        printf("4 : Delete new node from first position\n");
        printf("5 : Delete new node from last position\n");
        printf("6 : Delete new node from given position\n");
        printf("7 : Display all elements of linked list\n");
        printf("8 : count elements int the linked list\n");
        printf("0 : Terminate the application\n");
        printf("-----------------------------------------------Menu-----------------------------------------------\n");
        printf("-----------------------------------------------Menu-----------------------------------------------\n");
        scanf("%d",&iChoice);


        if(iChoice == 1)
        {
            printf("Enter the data that u want to insert :\n");
            scanf("%d",&iValue);
            InsertFirst(&head,iValue);
        }
        else if(iChoice == 2)
        {
            printf("Enter the data that u want to insert :\n");
            scanf("%d",&iValue);
            InsertLast(&head,iValue);
        }
        else if(iChoice == 3)
        {
            printf("Enter the data that u want to insert :\n");
            scanf("%d",&iValue);
            printf("Enter the position at which you want to insert new node :\n");
            scanf("%d",&iPos);

            InsertAtPos(&head,iValue,iPos);
        }
        else if(iChoice == 4)
        {
            printf("Deleting the first element from linked list :\n");
            DeleteFirst(&head);
        }
        else if(iChoice == 5)
        {
            printf("Deleting the last element from linked list :\n");
            DeleteLast(&head);
        }
        else if(iChoice == 6)
        {
            printf("Enter the position at which you want to delete the element from linked list :\n");
            scanf("%d",&iPos);

            DeleteAtPos(&head,iPos);
        }
        else if(iChoice == 7)
        {
            printf("Elements of the linked list are :\n");
            Display(head);
        }
        else if(iChoice == 8)
        {
            iRet = Count(head);
            printf("Number of elements in the linked list are : %d\n",iRet);
        }
        else if(iChoice == 0)
        {
            printf("Thank you for wasting your time\n");
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
        printf("------------------------------------Doubly Linear Linked List--------------------------------------\n");


        
    }
    return 0;
}