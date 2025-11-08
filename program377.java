class node
{
    public int data;
    public node next;
}
class SinglyCLL
{
    private int iCount;
    private node first;
    private node last;
    
    public SinglyCLL()
    {
        this.iCount = 0;
        this.first = null;
        this.last = null;
    }

    public void Display()
    {
        node temp = null;
        if((null == first) && (null == last))
        {
            return;
        }
        temp = first;
        do
        {
            System.out.print(" | "+temp.data+" | -> ");
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
        node newn = null;
        newn = new node();

        newn.data = No;
        newn.next = null;

        if((null == first) && (null == last))
        {
            first = newn;
            last = newn;
            last.next = first;
        }
        else
        {
            newn.next = first;
            first = newn;
            last.next = first;
        }
        iCount++;
    }

    public void InsertLast(int No)
    {
        node newn = null;

        newn = new node();
        newn.data = No;
        newn.next = null;

        if((null == first) && (null == last))
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            last = newn;
        }
        last.next = first;
        iCount++;
    }

    public void InsertAtPos(int No, int iPos)
    {
        node newn = null;
        node temp = null;

        if((1 > iPos) || (iPos > (iCount + 1)))
        {
            System.out.println("Invaid position");
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
            newn = new node();
            newn.data = No;
            newn.next = null;

            temp = first;
            for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteFirst()
    {
        if((null == first) && (null == last))
        {
            return;
        }
        if(first == last)
        {
            first = null;
            last = null;
        }
        else 
        {
            first = first.next;
        }
        last.next = first;
        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;
        if((null == first) && (null == last))
        {
            return;
        }
        if(first == last)
        {
            first = null;
            last = null;
        }
        else 
        {
            temp = first;
            do
            {
                temp = temp.next;
            }while(temp.next != last);
            last = temp;
        }
        last.next = first;
        iCount--;
    }

    public void DeleteAtPos(int iPos)
    {
        node temp = null;
        if((1 > iPos) || (iPos > iCount))
        {
            System.out.println("Invaid position");
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
            for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            
            iCount--;
        }
    }
}
class program377
{
    public static void main(String A[])
    {
        SinglyCLL sobj = new SinglyCLL();

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        //sobj.InsertLast(111);
        //sobj.InsertLast(121);


        sobj.InsertAtPos(105,2);
        //sobj.DeleteFirst();
        //sobj.DeleteLast();
        sobj.Display();

        int iRet = 0;
        iRet = sobj.Count();
        System.out.println("Number of elements in the linked list are : "+iRet);
    
        sobj.DeleteAtPos(2);
        sobj.Display();

        iRet = 0;
        iRet = sobj.Count();
        System.out.println("Number of elements in the linked list are : "+iRet);
        
    }
}