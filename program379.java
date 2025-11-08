class node
{
    public int data;
    public node next;
    public node prev;
}
class DoublyCLL
{
    private int iCount;
    private node first;
    private node last;
    
    public DoublyCLL()
    {
        this.iCount = 0;
        this.first = null;
        this.last = null;
    }

    public void Display()
    {
        node temp = null;
        if(null == first)
        {
            System.out.println("LinkedList is empty");
            return;
        }
        temp = first;
        do
        {
            System.out.print(temp.data+"\t");
            temp = temp.next;
        }while(temp != last.next);
        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }

    public void InsertFirst(int No)
    {
        node newn = new node();
        
        newn.data = No;
        newn.prev = null;
        newn.next = null;

        if(null == first)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }
        last.next = first;
        first.prev = last;
        iCount++;
    }

    public void InsertLast(int No)
    {
        node newn = new node();
        
        newn.data = No;
        newn.prev = null;
        newn.next = null;

        if(null == first)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            newn.prev = last;
            newn.next = first;
            last = newn;
        }
        last.next = first;
        first.prev = last;
        iCount++;
    }

    public void InsertAtPos(int No, int iPos)
    {
        node temp = null;
        node newn = null;

        if((1 > iPos) || (iPos > (iCount + 1)))
        {
            System.out.println("Invalid position");
            return;
        }

        if(1 == iPos)
        {
            InsertFirst(No);
            return;
        }
        else if(iPos == (iCount + 1))
        {
            InsertLast(No);
            return;
        }
        else
        {
            temp = first;

            newn = new node();
            newn.data = No;
            newn.next = null;
            newn.prev = null;
            for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next.prev = newn;

            temp.next = newn;
            newn.prev = temp;
        }
        iCount++;
    }

    public void DeleteFirst()
    {
        if(null == first)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            first.prev = last;
            last.next = first;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        if(null == first)
        {
            return;
        }
        else if(last == first)
        {
            first = null;
            last = null;
        }
        else
        {
            last = last.prev;
            last.next = first;
            first.prev = last;
        }
        iCount--;
    }

    public void DeleteAtPos(int iPos)
    {
        node temp = null;

        if((1 > iPos) || (iPos > iCount))
        {
            System.out.println("Invalid position");
            return;
        }

        if(1 == iPos)
        {
            DeleteFirst();
            return;
        }
        else if(iPos == iCount)
        {
            DeleteLast();
            return;
        }
        else
        {
            temp = first;
            for(int iCnt = 1; iCnt < iPos; iCnt++)
            {
                temp = temp.next;
            }
            temp.prev.next = temp.next;
            temp.next.prev = temp.prev;
        }
        iCount--;
    }
}
class program379
{
    public static void main(String A[])
    {
        DoublyCLL dobj = new DoublyCLL();

        dobj.InsertFirst(30);
        dobj.InsertFirst(20);
        dobj.InsertFirst(10);
        dobj.Display();
    }
}