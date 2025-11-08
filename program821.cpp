#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class SinglyCLL
{
    private:
        int iCount;
        struct node * first;
        struct node * last;
    public:
        SinglyCLL();
        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No, int Pos);
        void DeleteAtPos(int Pos);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
};

SinglyCLL :: SinglyCLL()
{
    cout<<"Inside constructor of SINGLYCLL\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

void SinglyCLL :: InsertFirst(int No)
{
    struct node * newn = NULL;

    newn = new struct node;

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

void SinglyCLL :: InsertLast(int No)
{
    struct node * newn = NULL;

    newn = new struct node;

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

void SinglyCLL :: InsertAtPos(int No, int Pos)
{
    struct node * temp = NULL;
    struct node * newn = NULL;

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
        newn = new struct node;
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

void SinglyCLL :: DeleteAtPos(int Pos)
{
    struct node * temp = NULL;
    struct node * target = NULL;

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

void SinglyCLL :: DeleteFirst()
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

void SinglyCLL :: DeleteLast()
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
        struct node * temp = NULL;
        
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

void SinglyCLL :: Display()
{
    struct node * temp = NULL;
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

int SinglyCLL :: Count()
{
    return iCount;
}

int main()
{
    SinglyCLL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.DeleteFirst();

    sobj.DeleteLast();

    sobj.InsertAtPos(105,3);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements are :"<<iRet<<endl;

    sobj.DeleteAtPos(3);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements are :"<<iRet<<endl;


    return 0;
}