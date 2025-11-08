// Generic implementation of Stack

#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *next;
};

template<class T>
class StackX
{
    private:
        struct node<T> *first;
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
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = No;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

template<class T>
T StackX<T> :: pop()
{
    struct node<T> *temp = NULL;
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
    struct node<T> * temp = NULL;
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
    StackX<double> *sobj = new StackX<double>();
    double iRet = 0.0;
    sobj->push(10.4);
    sobj->push(20.5);
    sobj->push(30.31);
    sobj->push(40.6);
    
    iRet = sobj->pop();
    sobj->Display();
    cout<<"Popped element from stack is : "<<iRet<<endl;
    cout<<"Elements are : "<<sobj->Count()<<endl;

    delete sobj;

    return 0;
}