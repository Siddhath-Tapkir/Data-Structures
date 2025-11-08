#include<stdio.h>
#include<stdlib.h>

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
int main()
{
    PNODE head = NULL;

    Insert(&head,11);
    Insert(&head,9);
    Insert(&head,17);
    printf("Inorder data is : \n");
    Inorder(head);
    printf("\nPreorder data is :\n");
    Preorder(head);
    printf("\nPostorder data is :\n");
    Postorder(head);

    return 0;
}