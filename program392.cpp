#include<iostream>
using namespace std;
template<class T>
struct node
{
    T data;
    struct node<T> *next;
};

template<class T>
class QueueX
{
    private:
        struct node<T> *first;
        int iCount;
    public:
        QueueX();
        void enqueue(T);
        T dequeue();
        void Display();
        int Count();
};
template<class T>
QueueX<T> :: QueueX()
{
    first = NULL;
    iCount = 0;
}
template<class T>
void QueueX<T> :: enqueue(T No)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;
    
    newn = new node<T>;

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
template<class T>
T QueueX<T> :: dequeue()
{
    struct node<T> *temp = NULL;
    T iVal = 0;
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
template<class T>
void QueueX<T> :: Display()
{
    struct node<T> * temp = NULL;
    temp = first;

    while(NULL != temp)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<endl;
}
template<class T>
int QueueX<T> :: Count()
{
    return iCount;
}

int main()
{
    QueueX<int> *sobj = new QueueX<int>();
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