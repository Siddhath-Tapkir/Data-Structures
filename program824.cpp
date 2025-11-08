#include<iostream>
using namespace std;

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