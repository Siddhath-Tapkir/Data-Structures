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

/////////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyCLL
//  Description :   Generic implementation of Doubly circular LinkedList
//  Author :        Siddharth Vikas Tapkir
//
/////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyLL
//  Description :   Generic implementation of Singly Linear LinkedList
//  Author :        Siddharth Vikas Tapkir
//
/////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyLL
//  Description :   Generic implementation of Doubly Linear LinkedList
//  Author :        Siddharth Vikas Tapkir
//
/////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////
//
//  Class :         BST
//  Description :   Generic implementation of Binary Search Tree
//  Author :        Siddharth Vikas Tapkir
//
/////////////////////////////////////////////////////////////////////////

template <class T>
struct BSTnode
{
    T data;
    struct BSTnode<T> *lchild;
    struct BSTnode<T> *rchild;
};

template <class T>
class BinarySearchTree
{
    private:
        struct BSTnode<T> *root;
        int iCount;
    public:
        BinarySearchTree();

        void Insert(T);
        void InorderDisplay();
        void PreOrderDisplay();
        void PostOrderDisplay();
        bool Search(T);
        int Count();

    private:
        void prvInorderDisplay(struct BSTnode<T> *);
        void prvPreOrderDisplay(struct BSTnode<T> *);
        void prvPostOrderDisplay(struct BSTnode<T> *);
        
};

template <class T>
BinarySearchTree<T> :: BinarySearchTree()
{
    this->root = NULL;
    this->iCount = 0;
}

template <class T>
void BinarySearchTree<T> :: Insert(T No)
{
    BSTnode<T> *newn = NULL;
    BSTnode<T> *temp = NULL;

    newn = new BSTnode<T>;

    newn->data = No;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(NULL == root)
    {
        root = newn;
    }
    else
    {
        temp = root;

        while(1)
        {
            if(temp->data == No)
            {
                cout<<"Duplicate element : Unable to insert"<<endl;
                return;
            }
            else
            {
                if(No > temp->data)
                {
                    if(NULL == temp->rchild)
                    {
                        temp->rchild = newn;
                        break;
                    }
                    temp = temp->rchild;
                }
                else if(No < temp->data)
                {
                    if(NULL == temp->lchild)
                    {
                        temp->lchild = newn;
                        break;
                    }
                    temp = temp->lchild;
                }
            }
        }
    }
    iCount++;
}

template <class T>
int BinarySearchTree<T> :: Count()
{
    return iCount;
}

template <class T>
bool BinarySearchTree<T> :: Search(T No)
{
    struct BSTnode<T> *temp = NULL;

    temp = root;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            break;
        }
        else if(No < temp->data)
        {
            temp = temp->lchild;
        }
        else if(No > temp->data)
        {
            temp = temp->rchild;
        }
    }
    return (temp != NULL);
}

template <class T>
void BinarySearchTree<T> :: InorderDisplay()
{
    struct BSTnode<T> *temp = NULL;
    temp = root;
    prvInorderDisplay(temp);
    cout<<"\n";
}

template <class T>
void BinarySearchTree<T> :: PreOrderDisplay()
{
    struct BSTnode<T> *temp = NULL;
    temp = root;
    prvPreOrderDisplay(temp);
    cout<<"\n";
}

template <class T>
void BinarySearchTree<T> :: PostOrderDisplay()
{
    struct BSTnode<T> *temp = NULL;
    temp = root;
    prvPostOrderDisplay(temp);
    cout<<"\n";
}

template <class T>
void BinarySearchTree<T> :: prvInorderDisplay(struct BSTnode<T> *temp)
{
    if(temp != NULL)
    {
        prvInorderDisplay(temp->lchild);
        cout<<temp->data<<"\t";
        prvInorderDisplay(temp->rchild);
    }
}

template <class T>
void BinarySearchTree<T> :: prvPreOrderDisplay(struct BSTnode<T> *temp)
{
    if(temp != NULL)
    {
        cout<<temp->data<<"\t";
        prvPreOrderDisplay(temp->lchild);
        prvPreOrderDisplay(temp->rchild);
    }
}

template <class T>
void BinarySearchTree<T> :: prvPostOrderDisplay(struct BSTnode<T> *temp)
{
    if(temp != NULL)
    {
        prvPostOrderDisplay(temp->lchild);
        prvPostOrderDisplay(temp->rchild);
        cout<<temp->data<<"\t";
    }
}

/////////////////////////////////////////////////////////////////////////
//
//  Class :         Sorting(program595.cpp) -> generic
//  Description :   Generic implementation of sorting algorithms
//  Author :        Siddharth Vikas Tapkir
//
/////////////////////////////////////////////////////////////////////////

template <class T>
class ArraySort
{
    private:
        T *Arr;
        int iSize;
        bool Sorted;
    public:

        ArraySort(int no)
        {
            iSize = no;
            Sorted = true;
            Arr = new T[iSize];
        }
        ~ArraySort()
        {
            delete[]Arr;
        }
        void Accept()
        {
            cout<<"Enter "<<iSize<<" elements : \n";
            
            int i = 0;
            
            for(i = 0; i < iSize; i++)
            {
                cout<<"Enter the element number : "<<i + 1<<endl;
                cin>>Arr[i];

                if(i > 0)
                {
                    if((Arr[i] < Arr[i - 1]) && (true == Sorted))   // Important ahe
                    {
                        Sorted = false;
                    }
                }
            }
        }
        void Display()
        {
            cout<<"The elements of the array are :\n";
            int i = 0;
            for(i = 0; i < iSize; i++)
            {
                cout<<Arr[i]<<" ";
            }
            cout<<endl;
        }

        void BubbleSort()
        {
            if(true == Sorted)
            {
                return;
            }
            
            int i = 0, j = 0; 
            T temp = 0;

            for(i = 0; i < iSize; i++)  // Outer Loop
            {
                for(j = 0; j < (iSize - 1); j++)  // Inner loop
                {
                    if(Arr[j] > Arr[j + 1])
                    {
                        temp = Arr[j];
                        Arr[j] = Arr[j +1];
                        Arr[j + 1] = temp;
                    }
                }
            }
        }

        void BubbleSortEfficient()
        {
            if(true == Sorted)
            {
                return;
            }

            bool bFlag = true;
            
            int i = 0, j = 0;
            T temp = 0;

            for(i = 0; (i < iSize && bFlag == true); i++)  // Outer Loop
            {
                bFlag = false;   
                for(j = 0; j < (iSize - 1 - i); j++)  // Inner loop
                {
                    if(Arr[j] > Arr[j + 1])
                    {
                        temp = Arr[j];
                        Arr[j] = Arr[j +1];
                        Arr[j + 1] = temp;

                        bFlag = true;
                    }
                }
            }
        }

        void SelectionSort()
        {
            int i = 0, j = 0, min_index = 0;
            T temp = 0;

            for(i = 0; i < iSize - 1; i++)
            {
                min_index = i;

                for(j = i + 1; j < iSize; j++)
                {
                    if(Arr[j] < Arr[min_index])
                    {
                        min_index = j;
                    }
                }
                
                if(i != min_index)
                {    
                    temp = Arr[i];
                    Arr[i] = Arr[min_index];
                    Arr[min_index] = temp;
                }
            }
        }

        void InsertionSort()
        {
            int i = 0, j = 0;
            T selected = 0;

            for(i = 1; i < iSize; i++)
            {
                for(j = i - 1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
                {
                    Arr[j + 1] = Arr[j];
                }
                Arr[j + 1] = selected;
            }
        }
};

/////////////////////////////////////////////////////////////////////////
//
//  Class :         Searching(program587.cpp) -> generic
//  Description :   Generic implementation of sorting algorithms
//  Author :        Siddharth Vikas Tapkir
//
/////////////////////////////////////////////////////////////////////////

template <class T>
class ArraySearch  // Increasing
{
    private:
        T *Arr;
        int iSize;
        bool Sorted;
    public:
        ArraySearch(int no)
        {
            iSize = no;
            Sorted = true;
            Arr = new T[iSize];
        }
        ~ArraySearch()
        {
            delete[]Arr;
        }
        void Accept()
        {
            cout<<"Enter "<<iSize<<" elements : \n";
            
            int i = 0;
            
            for(i = 0; i < iSize; i++)
            {
                cout<<"Enter the element number : "<<i + 1<<endl;
                cin>>Arr[i];

                if(i > 0)
                {
                    if((Arr[i] < Arr[i - 1]) && (true == Sorted))   // Important ahe
                    {
                        Sorted = false;
                    }
                }
            }
        }
        void Display()
        {
            cout<<"The elements of the array are :\n";
            int i = 0;
            for(i = 0; i < iSize; i++)
            {
                cout<<Arr[i]<<" ";
            }
            cout<<endl;
        }
        bool LinearSearch(T No)   // N
        {
            int i = 0;
            bool bFlag = 0;

            if(true == Sorted)
            {
                return BinarySearchEfficientInc(No);    // Important
            }

            for(i = 0; i < iSize; i++)
            {
                if(Arr[i] == No)
                {
                    bFlag = true;
                    break;
                }
            }
            return bFlag;
        }
        bool BidirectionalSearch(T No) // N/2
        {
            int iStart = 0;
            int iEnd = 0;
            bool bFlag = 0;
            for(iStart = 0, iEnd = (iSize - 1); iStart <= iEnd; iStart++,iEnd--)
            {
                if((Arr[iStart] == No) || (Arr[iEnd] == No))
                {
                    bFlag = true;
                    break;
                }
            }
            return bFlag;
        }

        bool BinarySearchInc(
                            T iNo
                        )
        {
            int iStart = 0, iEnd = 0, iMid = 0;
            bool bFlag = false;

            iStart = 0;
            iEnd = iSize - 1;
            
            while(iStart <= iEnd)
            {
                iMid = iStart + ((iEnd - iStart) / 2);

                if(Arr[iMid] == iNo)
                {
                    bFlag = true;
                    break;
                }
                
                else if(iNo < Arr[iMid]) // First half(left window)
                {
                    iEnd = iMid - 1;
                }

                else if(iNo > Arr[iMid]) // Second half(right window)
                {
                    iStart = iMid + 1;
                }
            } // End of while

            return bFlag;
        }

        bool BinarySearchDec(
                            T iNo
                        )
        {
            int iStart = 0, iEnd = 0, iMid = 0;
            bool bFlag = false;

            iStart = 0;
            iEnd = iSize - 1;
            
            while(iStart <= iEnd)
            {
                iMid = iStart + ((iEnd - iStart) / 2);

                if(Arr[iMid] == iNo)
                {
                    bFlag = true;
                    break;
                }
                
                else if(iNo > Arr[iMid]) // First half(left window)
                {
                    iEnd = iMid - 1;
                }

                else if(iNo < Arr[iMid]) // Second half(right window)
                {
                    iStart = iMid + 1;
                }
            } // End of while

            return bFlag;
        }

        bool BinarySearchEfficientInc(
                                    T iNo
                                )
        {
            int iStart = 0, iEnd = 0, iMid = 0;
            bool bFlag = false;

            if(false == Sorted)   // new
            {
                return LinearSearch(iNo);   // Import ahe
            }

            iStart = 0;
            iEnd = iSize - 1;
            
            while(iStart <= iEnd)
            {
                iMid = iStart + ((iEnd - iStart) / 2);

                if((Arr[iMid] == iNo) || (Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
                {
                    bFlag = true;
                    break;
                }
                
                else if(iNo < Arr[iMid]) // First half(left window)
                {
                    iEnd = iMid - 1;
                }

                else if(iNo > Arr[iMid]) // Second half(right window)
                {
                    iStart = iMid + 1;
                }
            } // End of while

            return bFlag;
        }

        bool BinarySearchEfficientDec(
                                    T iNo
                                )
        {
            int iStart = 0, iEnd = 0, iMid = 0;
            bool bFlag = false;

            iStart = 0;
            iEnd = iSize - 1;
            
            while(iStart <= iEnd)
            {
                iMid = iStart + ((iEnd - iStart) / 2);

                if((Arr[iMid] == iNo) || (Arr[iStart] == iNo) || (Arr[iEnd] == iNo))    // change
                {
                    bFlag = true;
                    break;
                }
                
                else if(iNo > Arr[iMid]) // First half(left window)
                {
                    iEnd = iMid - 1;
                }

                else if(iNo < Arr[iMid]) // Second half(right window)
                {
                    iStart = iMid + 1;
                }
            } // End of while

            return bFlag;
        }

        bool CheckSortedInc()
        {
            bool bFlag = true;

            for(int i = 0; i < (iSize - 1); i++)
            {
                if(Arr[i] > Arr[i + 1]) // change
                {
                    bFlag = false;
                    break;
                }
            }
            return bFlag;
        }

        bool CheckSortedDec()
        {
            bool bFlag = true;

            for(int i = 0; i < (iSize - 1); i++)
            {
                if(Arr[i] < Arr[i + 1]) // change
                {
                    bFlag = false;
                    break;
                }
            }
            return bFlag;
        }
};

/////////////////////////////////////////////////////////////////////////
//  Assignment no 34,35,36 functions -> .cpp -> generic
//  Write all fucntions logic in all types of linked list
/////////////////////////////////////////////////////////////////////////
int main()
{

    return 0;
}