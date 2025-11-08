#include<iostream>
using namespace std;

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
int main()
{
    BinarySearchTree<int> *bobj = new BinarySearchTree<int>;
    
    bobj->Insert(11);
    bobj->Insert(9);
    bobj->Insert(7);
    bobj->Insert(17);
    bobj->Insert(15);
    bobj->Insert(25);
    bobj->Insert(21);
    bobj->Insert(35);

    bobj->PreOrderDisplay();

    cout<<bobj->Count()<<endl;

    delete bobj;

    return 0;
}