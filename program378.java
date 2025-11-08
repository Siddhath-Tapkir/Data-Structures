class node
{
    public int data;
    public node next;
    public node prev;
}
class DoublyLLL
{
    private int iCount;
    private node first;
    
    public DoublyLLL()
    {
        this.iCount = 0;
        this.first = null;
    }

    public void Display()
    {
        node temp = null;
        temp = first;
        while(null != temp)
        {
            System.out.print(" | "+temp.data+" | ->");
            temp = temp.next;
        }
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
        newn.next = null;
        newn.prev = null;

        if(null == first)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }
        iCount++;
    }

    public void InsertLast(int No)
    {
        node temp = null;
        node newn = new node();
        
        newn.data = No;
        newn.next = null;
        newn.prev = null;

        if(null == first)
        {
            first = newn;
        }
        else
        {
            temp = first;
            while(null != temp.next)
            {
                temp = temp.next;
            }
            temp.next = newn;
            newn.prev = temp;
        }
        iCount++;
    }

    public void InsertAtPos(int No, int iPos)
    {
        node temp = null;
        node newn = new node();

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
        else if(null == first.next)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            first.prev = null;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;
        if(null == first)
        {
            return;
        }
        else if(null == first.next)
        {
            first = null;
        }
        else
        {   
            temp = first;
            while(null != temp.next.next)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        iCount--;
    }

    public void DeleteAtPos(int iPos)
    {
        node temp = null;
        if((1 > iPos) || (iPos > iCount ))
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

            temp.next = null;
            temp.prev = null;
        }
        iCount--;
    }
}
class program378
{
    public static void main(String A[])
    {
        DoublyLLL dobj = new DoublyLLL();
        dobj.InsertFirst(30);
        dobj.InsertFirst(20);
        dobj.InsertFirst(10);
        dobj.InsertLast(40);
        dobj.InsertLast(50);
        dobj.InsertLast(60);
        
        dobj.Display();
        System.out.println(dobj.Count());
        
    }
}