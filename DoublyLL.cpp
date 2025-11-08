#include<iostream>
using namespace std;

template <class T>
struct DoublyLLnode
{
    T data;
    struct DoublyLLnode<T> *next;
    struct DoublyLLnode<T> *prev;  
};

template <class T>
class DoublyLL
{
    private:
        int iCount;
        struct DoublyLLnode<T> *first;

    public:
        DoublyLL();
        ~DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    iCount = 0;
    first = NULL;
}

template <class T>
DoublyLL<T> :: ~DoublyLL()
{
    while(iCount != 0)
    {
        DeleteFirst();
    }
}

template <class T>
void DoublyLL<T> :: Display()
{
    struct DoublyLLnode<T> *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}


template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T No)
{
    struct DoublyLLnode<T> * newn = NULL;

    newn = new DoublyLLnode<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T No)
{
    struct DoublyLLnode<T> * newn = NULL;
    struct DoublyLLnode<T> * temp = NULL;

    newn = new DoublyLLnode<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
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
        newn->prev = temp;
    }

    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T No, int iPos)
{
    if(iPos <= 0 || iPos > (iCount + 1))
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

    struct DoublyLLnode<T> * newn = NULL;
    struct DoublyLLnode<T> * temp = NULL;

    newn = new DoublyLLnode<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
    
    temp = first;

    for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
    {
        temp = temp->next;
    }

    newn->next = temp->next;
    temp->next->prev = newn;
    temp->next = newn;
    newn->prev = temp;

    iCount++;
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    if(first->next == NULL)
    {
        struct DoublyLLnode<T> *temp = first;
        first = first->next;
        delete temp;
        iCount--;

        return;
    }
    else
    {
        first = first->next;

        delete first->prev;
        first->prev = NULL;
        
        iCount--;
    }
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    if(first->next == NULL)
    {
        DeleteFirst();
        return;
    }
    else
    {
        struct DoublyLLnode<T> *temp = first;
        
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
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    if(iPos <= 0 || iPos > iCount)
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

    struct DoublyLLnode<T> * temp = NULL;
    
    temp = first;

    for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;

    delete temp->next->prev;
    temp->next->prev = temp;

    iCount--;
}

int main()
{
    DoublyLL<int> *dobj = new DoublyLL<int>;

    dobj->InsertFirst(21);
    dobj->InsertFirst(11);
    dobj->Display();
    dobj->InsertLast(51);
    dobj->InsertLast(101);
    dobj->Display();
    dobj->DeleteFirst();
    dobj->Display();
    dobj->DeleteLast();
    dobj->Display();
    dobj->DeleteAtPos(2);
    
    dobj->Display();
    
    

    return 0;
}