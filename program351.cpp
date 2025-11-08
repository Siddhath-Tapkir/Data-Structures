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
        {
            PNODE temp = NULL;
            PNODE newn = NULL;

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
                newn = new NODE;
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

        void DeleteAtPos(int Pos)
        {
            PNODE temp = NULL;

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

            }
        }

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
                PNODE temp = NULL;
                
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

    sobj.DeleteLast();

    sobj.InsertAtPos(105,3);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements are :"<<iRet<<endl;


    return 0;
}