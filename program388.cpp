#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};


class StackX
{
    private:
        struct node *first;
        int iCount;
    public:
        StackX();
        void push(int);
        int pop();
        void Display();
        int Count();
};
StackX :: StackX()
{
    first = NULL;
    iCount = 0;
}

void StackX :: push(int No)
{
    struct node *newn = NULL;
    newn = new node;

    newn->data = No;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

int StackX :: pop()
{
    struct node *temp = NULL;
    int iVal = 0;
    if(NULL == first)
    {
        cout<<"Stack is emtpy\n";
        return NULL;
    }
    else
    {
        temp = first;
        first = first->next;

        iVal = temp->data;
        delete temp;
    }
    iCount--;
    return iVal;
}

void StackX :: Display()
{
    struct node * temp = NULL;
    temp = first;

    while(NULL != temp)
    {
        cout<<"| "<<temp->data<<" |"<<endl;
        temp = temp->next;
    }
    cout<<endl;
}

int StackX :: Count()
{
    return iCount;
}

int main()
{
    StackX *sobj = new StackX();
    int iRet = 0;
    sobj->push(10);
    sobj->push(20);
    sobj->push(30);
    sobj->push(40);
    
    iRet = sobj->pop();
    sobj->Display();
    cout<<"Popped element from stack is : "<<iRet<<endl;
    cout<<"Elements are : "<<sobj->Count()<<endl;

    delete sobj;

    return 0;
}