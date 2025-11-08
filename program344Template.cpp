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
            this->first = NULL;
            this->last = NULL;
            iCount = 0;
        }
        void InsertFirst(int No)
        {}
        void InsertLast(int No)
        {}
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

    return 0;
}