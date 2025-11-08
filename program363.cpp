#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
typedef struct node* PNODE;
class DoublyCLL
{
    private:
        int iCount;
        PNODE first;
        PNODE last;
    public:
        DoublyCLL();

        void Display();
        int Count();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        
};
DoublyCLL :: DoublyCLL() 
{
    cout<<"Inside constructor\n";
    iCount = 0;
    first = NULL;
    last = NULL;
}
void DoublyCLL :: InsertFirst(int No)
{
    PNODE newn = NULL;
    
    newn = new NODE;      
    
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
void DoublyCLL :: InsertLast(int No)
{
    PNODE newn = NULL;
    
    newn = new NODE;      
    
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
void DoublyCLL :: DeleteFirst()
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
void DoublyCLL :: DeleteLast()
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
void DoublyCLL :: Display()
{
    cout<<"Elements of the LinkedList are :\n";
    PNODE temp = NULL;

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
int DoublyCLL :: Count()
{
    return iCount;
}
int main()
{
    int iRet = 0;
    DoublyCLL dobj;
    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    
    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);
    dobj.DeleteLast();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"\n"<<iRet<<endl;

    return 0;
}