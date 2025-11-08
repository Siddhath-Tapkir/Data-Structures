class node
{
    public int data;
    public node next;
}

class SinglyLL
{
    private node first;
    private int iCount;
   
    public SinglyLL()
    {
        System.out.println("Inside constructor");
        this.iCount = 0;
        this.first = null;
    }

    public void InsertFirst(int No)
    {
        node newn = null;

        newn = new node();

        newn.data = No;
        newn.next = null;

        if(null == first)   // LL is empty
        {
            first = newn;
        }
        else        // LL contains atleast one node
        {
            newn.next = first;
            first = newn;
        }
        iCount++;
    }

    public void InsertLast(int No)
    {
        node newn = null;
        node temp = null;
        newn = new node();

        newn.data = No;
        newn.next = null;

        if(null == first)   // LL is empty
        {
            first = newn;
        }
        else        // LL contains atleast one node
        {
            temp = first;

            while(null != temp.next)
            {
                temp = temp.next;
            }

            temp.next = newn;
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
        }
        else
        {
            first = first.next;
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

    public void InsertAtPos(int No, int iPos)
    {
        node temp = null;
        node newn = null;

        if((1 > iPos) || (iPos > (iCount + 1)))
        {
            System.out.println("Invalid Positon");
            return;
        }

        if(1 == iPos)
        {
            InsertFirst(No);
        }
        else if(iPos == (iCount + 1))
        {
            InsertLast(No);
        }
        else
        {
            temp = first;
            
            newn = new node();

            newn.data = No;
            newn.next = null;

            for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteAtPos(int iPos)
    {
        node temp = null;

        if((1 > iPos) || (iPos > iCount))
        {
            System.out.println("Invalid Positon");
            return;
        }

        if(1 == iPos)
        {
            DeleteFirst();
        }
        else if(iPos == iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = first;

            for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            
            iCount--;
        }
    }

    public void Display()
    {
        node temp = null;
        temp = first;
        while(null != temp)
        {
            System.out.print("|"+temp.data+"|->");
            temp = temp.next;
        }
        System.out.print("null\n");
    }

    public int Count()
    {
        return iCount;
    }
}

class program375
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);

        sobj.InsertAtPos(105,5);
        sobj.Display();

        int iRet = 0;
        iRet = sobj.Count();
        System.out.println("Number of elements in the linked list are : "+iRet);

        sobj.DeleteAtPos(5);
        sobj.Display();

        iRet = 0;
        iRet = sobj.Count();
        System.out.println("Number of elements in the linked list are : "+iRet);
    }
}