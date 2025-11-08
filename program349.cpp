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
            iCount++;
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
                last->next = newn;
                last = newn;

                last->next = first;
            }
            iCount++;
        }
        void InsertAtPos(int No, int Pos)
        {}
        void DeleteFirst()
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

        void DeleteLast()
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
                
            }
            iCount--;
        }
        void DeleteAtPos(int Pos)
        {}

        void Display()
        {
            PNODE temp = NULL;
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

        int Count()
        {
            return iCount;
        }
};
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

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements are :"<<iRet<<endl;


    return 0;
}