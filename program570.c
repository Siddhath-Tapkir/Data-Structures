#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Insert(PPNODE first, int No)
{
    PNODE temp = NULL;
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = No;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(NULL == *first) // BTS is emtpy
    {
        *first = newn;
    }
    else    // BTS contains atleast one node
    {
        temp = *first;
        
        while(1)
        {
            if(No == temp->data)
            {
                printf("Duplicate element : Unable to insert node\n");
                free(newn);
                break;
            }
            else if(No > temp->data)        // rchild
            {
                if(NULL == temp->rchild)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(No < temp->data)        // lchild
            {
                if(NULL == temp->lchild)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}
void Inorder(PNODE first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        printf("%d\t",first->data);
        Inorder(first->rchild);
    }
}
void Preorder(PNODE first)
{
    if(first != NULL)
    {
        printf("%d\t",first->data);
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}
void Postorder(PNODE first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        printf("%d\t",first->data);
    }
}
bool Search(PNODE first, int No)
{
    bool bFlag = false;
    int TimeComplexcity = 0;
    while(first != NULL)
    {
        if(No == first->data)
        {
            bFlag = true;
            break;
        }
        else if(No > first->data)
        {
            first = first->rchild;
        }
        else if(No < first->data)
        {
            first = first->lchild;
        }
        TimeComplexcity++;
    }
    printf("Time complexcity of search is : %d\n",TimeComplexcity);
    return bFlag;
}
int Count(PNODE first)
{
    static int iCount = 0;
    if(first != NULL)
    {
        iCount++;
        Count(first->lchild);
        Count(first->rchild);
    }
    return iCount;
}
int CountLeafNodes(PNODE first)
{
    static int iCount = 0;
    if(first != NULL)
    {
        if(first->lchild == NULL && first->rchild == NULL)
        {
            iCount++;
        }
        CountLeafNodes(first->lchild);
        CountLeafNodes(first->rchild);
    }
    return iCount;
}
int main()
{
    PNODE head = NULL;
    auto bool bRet = false;
    auto int iRet = 0;
    Insert(&head,11);
    Insert(&head,9);
    Insert(&head,17);
    Insert(&head,25);
    Insert(&head,7);
    Insert(&head,35);
    Insert(&head,10);
    Insert(&head,15);
    Insert(&head,21);
    Insert(&head,26);
    Insert(&head,37);
    Insert(&head,89);
    Insert(&head,91);
    Insert(&head,65);
    Insert(&head,12);
    Insert(&head,20);
    Insert(&head,44);
    Insert(&head,66);
    Insert(&head,90);
    Insert(&head,88);


    bRet = Search(head,66);
    if(true == bRet)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("There is no such element\n");
    }

    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    iRet = CountLeafNodes(head);
    printf("Number of leaf nodes are : %d\n",iRet);

    return 0;
}