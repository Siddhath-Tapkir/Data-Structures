#include<iostream>
using namespace std;

template <class T>
struct SinglyLLnode
{
    T data;
    struct SinglyLLnode<T> *next;
};

template <class T>
class SinglyLL
{
    private:
        struct SinglyLLnode<T> * first;
        int iCount;
    public:
        SinglyLL();
        ~SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
SinglyLL<T> :: ~SinglyLL()
{
    while(first != NULL)
    {
        DeleteFirst();
    }
}

template <class T>
void SinglyLL<T> :: Display()
{
    struct SinglyLLnode<T> *temp = first;

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T> :: Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T No)
{
    struct SinglyLLnode<T> * newn = NULL;
    
    newn = new struct SinglyLLnode<T>;

    newn->data = No;
    newn->next = NULL;

    if(NULL == first)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> :: InsertLast(T No)
{
    struct SinglyLLnode<T> * newn = NULL;
    struct SinglyLLnode<T> * temp = NULL;
    
    newn = new struct SinglyLLnode<T>;

    newn->data = No;
    newn->next = NULL;

    if(NULL == first)
    {
        first = newn;
    }
    else
    {
        temp = first;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> :: InsertAtPos(T No, int iPos)
{
    if((iPos <= 0) || (iPos > (iCount + 1)))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
        return;
    }

    if(iPos == (iCount + 1))
    {
        InsertLast(No);
        return;
    }

    struct SinglyLLnode<T> * newn = NULL;
    struct SinglyLLnode<T> * temp = NULL;

    newn = new struct SinglyLLnode<T>;

    newn->data = No;
    newn->next = NULL;

    temp = first;

    for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
    {
        temp = temp->next;    
    }

    newn->next = temp->next;
    temp->next = newn;

    iCount++;
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else
    {
        struct SinglyLLnode<T> * temp = NULL;
    
        temp = first;

        first = first->next;
        temp->next = NULL;
        
        delete temp;
        
        iCount--;
    }
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    if(first == NULL)
    {
        return;
    }

    if(first->next == NULL)
    {
        delete first;

        first = NULL;
        iCount--;

        return;
    }
    else
    {
        struct SinglyLLnode<T> * temp = NULL;
    
        temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;

        temp->next = NULL;
        
        iCount--;
    }
}

template <class T>
void SinglyLL<T> :: DeleteAtPos(int iPos)
{
    if((iPos <= 0) || (iPos > iCount))
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
        return;
    }

    if(iPos == iCount)
    {
        DeleteLast();
        return;
    }

    struct SinglyLLnode<T> * temp = NULL;
    struct SinglyLLnode<T> * target = NULL;

    temp = first;

    for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
    {
        temp = temp->next;
    }

    target = temp->next;
    temp->next = target->next;
    target->next = NULL;
    
    delete target;

    iCount--;
}
int main()
{
    

    return 0;
}