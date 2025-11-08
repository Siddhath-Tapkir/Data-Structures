#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyCLL
{
    private:
        int iCount;
        PNODE first;
        PNODE last;
    public:
        SinglyCLL()
        {
            cout<<"Inside constructor of SINGLYCLL\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }
        void InsertFirst(int No)
        {
            PNODE newn = NULL;

            newn = new NODE;

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
        }
        void InsertLast(int No)
        {
            PNODE newn = NULL;

            newn = new NODE;

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
                
            }
        }
        void InsertAtPos(int No, int Pos)
        {}
        void DeleteFirst()
        {}
        void DeleteLast()
        {}
        void DeleteAtPos(int Pos)
        {}
        void Display()
        {}
        int Count()
        {
            return iCount;
        }
};
int main()
{
    SinglyCLL sobj;
    
    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);


    return 0;
}