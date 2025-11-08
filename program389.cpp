#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};


class QueueX
{
    private:
        struct node *first;
        int iCount;
    public:
        QueueX();
        void enqueue(int);
        int dequeue();
        void Display();
        int Count();
};
QueueX :: QueueX()
{
    first = NULL;
    iCount = 0;
}

void QueueX :: enqueue(int No)
{
    struct node *newn = NULL;
    struct node *temp = NULL;
    
    newn = new node;

    newn->data = No;
    newn->next = NULL;

    if(NULL == first)
    {
        first = newn;
    }
    else
    {
        temp = first;
        while(NULL != temp->next)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

int QueueX :: dequeue()
{
    struct node *temp = NULL;
    int iVal = 0;
    if(NULL == first)
    {
        cout<<"Unable to remove as queue is emtpy\n";
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

void QueueX :: Display()
{
    struct node * temp = NULL;
    temp = first;

    while(NULL != temp)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<endl;
}

int QueueX :: Count()
{
    return iCount;
}

int main()
{
    QueueX *sobj = new QueueX();
    int iRet = 0;
    sobj->enqueue(10);
    sobj->enqueue(20);
    sobj->enqueue(30);
    sobj->enqueue(40);
    
    iRet = sobj->dequeue();
    sobj->Display();
    cout<<"Popped element from stack is : "<<iRet<<endl;
    cout<<"Elements are : "<<sobj->Count()<<endl;

    delete sobj;

    return 0;
}