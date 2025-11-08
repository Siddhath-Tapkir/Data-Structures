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
{}
int Count(PNODE first)
{
    return 0;
}
void InsertFirst(PPNODE first, int No)
{}
void InsertLast(PPNODE first, int No)
{}
void InsertAtPos(PPNODE first, int No, int Pos)
{}
void DeleteFirst(PPNODE first)
{}
void DeleteLast(PPNODE first)
{}
void DeleteAtPos(PPNODE first, int Pos)
{}
int main()
{
    PNODE head = NULL;


    return 0;
}