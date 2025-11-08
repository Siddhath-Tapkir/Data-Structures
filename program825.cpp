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


/////////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyCLL
//  Description :   Generic implementation of Singly Circular LinkedList
//  Author :        Siddharth Vikas Tapkir
//
/////////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

template <class T>
class SinglyCLL
{
    private:
        int iCount;
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
    public:
        SinglyCLL();
        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int Pos);
        void DeleteAtPos(int Pos);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
};

template <class T>
SinglyCLL<T> :: SinglyCLL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void SinglyCLL<T> :: InsertFirst(T No)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = No;
    newn->next = NULL;

    if((NULL == first) && (NULL == last))       // if (iCount == 0)
    {
        first = newn;
        last = newn;
        
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        
        last->next = first;
    }
    iCount++;
}

template <class T>
void SinglyCLL<T> :: InsertLast(T No)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = No;
    newn->next = NULL;

    if((NULL == first) && (NULL == last))       // if (iCount == 0)
    {
        first = newn;
        last = newn;
        
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }
    iCount++;
}

template <class T>
void SinglyCLL<T> :: InsertAtPos(T No, int Pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * newn = NULL;

    if((1 > Pos) || (Pos > (iCount + 1)))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(1 == Pos)
    {
        InsertFirst(No);
    }
    else if(Pos == (iCount + 1))
    {
        InsertLast(No);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;
        newn->data = No;
        newn->next = NULL;
        temp = first;

        for(int iCnt = 1; iCnt < (Pos - 1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCount++; 
    }
}

template <class T>
void SinglyCLL<T> :: DeleteAtPos(int Pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;

    if((1 > Pos) || (Pos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(1 == Pos)
    {
        DeleteFirst();
    }
    else if(Pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for(int iCnt = 1; iCnt < (Pos - 1); iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next = target->next;

        delete target;

        iCount--;
    }
}

template <class T>
void SinglyCLL<T> :: DeleteFirst()
{
    if((NULL == first) && (NULL == last)) 
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T> :: DeleteLast()
{
    if((NULL == first) && (NULL == last)) 
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        struct SinglyCLLnode<T> * temp = NULL;
        
        temp = first;
        
        while(temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;

        last->next = first;
    }   
    iCount--;
}

template <class T>
void SinglyCLL<T> :: Display()
{
    struct SinglyCLLnode<T> * temp = NULL;
    temp = first;
    if((NULL == first) && (NULL == last))
    {
        return;
    }
    else
    {
        do
        {
            cout<<" | "<<temp->data<<" | ->";
            temp = temp->next;
        } while(temp != last->next);
    }
    cout<<endl;
}

template <class T>
int SinglyCLL<T> :: Count()
{
    return iCount;
}

int main()
{

    return 0;
}