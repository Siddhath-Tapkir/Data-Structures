#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////
//
//  Class :         QueueX
//  Description :   Generic implementation of queue
//  Author :        Siddharth Vikas Tapkir
//
/////////////////////////////////////////////////////////////////////////

template<class T>
struct Queuenode
{
    T data;
    struct Queuenode<T> *next;
};

template<class T>
class QueueX
{
    private:
        struct Queuenode<T> *first;
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
    struct Queuenode<T> *newn = NULL;
    struct Queuenode<T> *temp = NULL;
    
    newn = new Queuenode<T>;

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
    struct Queuenode<T> *temp = NULL;
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
    struct Queuenode<T> * temp = NULL;
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

/////////////////////////////////////////////////////////////////////////
//
//  Class :         StackX
//  Description :   Generic implementation of stack
//  Author :        Siddharth Vikas Tapkir
//
/////////////////////////////////////////////////////////////////////////

template<class T>
struct Stacknode
{
    T data;
    struct Stacknode<T> *next;
};

template<class T>
class StackX
{
    private:
        struct Stacknode<T> *first;
        int iCount;
    public:
        StackX();
        void push(T);
        T pop();
        void Display();
        int Count();
};
template<class T>
StackX<T> :: StackX()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void StackX<T> :: push(T No)
{
    struct Stacknode<T> *newn = NULL;
    newn = new Stacknode<T>;

    newn->data = No;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

template<class T>
T StackX<T> :: pop()
{
    struct Stacknode<T> *temp = NULL;
    T iVal;
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
template<class T>
void StackX<T> :: Display()
{
    struct Stacknode<T> * temp = NULL;
    temp = first;

    while(NULL != temp)
    {
        cout<<"| "<<temp->data<<" |"<<endl;
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int StackX<T> :: Count()
{
    return iCount;
}

int main()
{

    return 0;
}