#include<iostream>
using namespace std;

template <class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};

template <class T>
class DoublyCLL
{
    private:
        int iCount;
        struct DoublyCLLnode<T> * first;
        struct DoublyCLLnode<T> * last;
    public:
        DoublyCLL();

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
DoublyCLL<T> :: DoublyCLL() 
{
    iCount = 0;
    first = NULL;
    last = NULL;
}

template <class T>
void DoublyCLL<T> :: InsertFirst(T No)
{
    struct DoublyCLLnode<T> * newn = NULL;
    
    newn = new struct DoublyCLLnode<T>;      
    
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((NULL == first) && (NULL == last))   //LL is empty
    {
        first = newn;
        last = newn;
    }
    else                                // LL contains atleast one node
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCLL<T> :: InsertLast(T No)
{
    struct DoublyCLLnode<T> * newn = NULL;
    
    newn = new struct DoublyCLLnode<T>;      
    
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((NULL == first) && (NULL == last))   //LL is empty
    {
        first = newn;
        last = newn;
    }
    else                                // LL contains atleast one node
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }

    last->next = first;
    first->prev = last;
    
    iCount++;
}

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if((NULL == first) && (NULL == last))   //LL is empty
    {
        return;
    }
    else if(last == first)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev; //delete last->next

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    if((NULL == first) && (NULL == last))   //LL is empty
    {
        return;
    }
    else if(last == first)
    {
        delete last;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCLL<T> :: Display()
{
    cout<<"Elements of the LinkedList are :\n";
    struct DoublyCLLnode<T> * temp = NULL;

    temp = first;

    if((NULL == first) && (NULL == last))
    {
        cout<<"LinkedList is empty\n";
        return;
    }
    
    do
    {
        cout<<"|"<<temp->data<<"| <=>";
        temp = temp->next;
    } while (temp != first);   
    
}

template <class T>
int DoublyCLL<T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyCLL<T> :: InsertAtPos(T No, int Pos) 
{
    if((1 > Pos) || (Pos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }
    struct DoublyCLLnode<T> * newn = NULL;
    struct DoublyCLLnode<T> * temp = NULL;

    if(1 == Pos)
    {
        InsertFirst(No);
    }
    else if((iCount + 1) == Pos)
    {
        InsertLast(No);
    }
    else
    {
        newn = new struct DoublyCLLnode<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;
        
        for(int iCnt = 1; iCnt < (Pos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next = newn;
        newn->next->prev = newn;
        /*  
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        */
        iCount++;

    }
}

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int Pos) // without target variable
{
    struct DoublyCLLnode<T> * temp = NULL;

    if((1 > Pos) || (Pos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(1 == Pos)
    {
        DeleteFirst();
    }
    else if(iCount == Pos)
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
        /*
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        */
        
        temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        
        iCount--;
    }
}

int main()
{
    int iRet = 0;
    DoublyCLL<int> dobj;
    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    
    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);
    dobj.InsertAtPos(115,5);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"\n"<<iRet<<endl;

    dobj.DeleteAtPos(5);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"\n"<<iRet<<endl;


    return 0;
}