class node
{
    public int data;
    public node next;
}

class StackX
{
    private node first;
    private int iCount;

    public StackX()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void push(int No) //InsertFirst()
    {
        node newn = new node();

        newn.data = No;
        newn.next = null;

        newn.next = first;
        first = newn;

        iCount++;
    }

    public int pop() // DeleteFirst()
    {
        node temp = this.first;
        
        if(null == this.first) //Stack empty
        {
            System.out.println("Unable to pop as stack is emtpy");
            return -1;
        }
        else
        {
            first = first.next;
            iCount--;
            return temp.data;
        }
    }

    public void Display()
    {
        node temp = null;

        temp = this.first;

        while(null != temp)
        {
            System.out.println("| "+temp.data+" |");
            temp = temp.next;
        }
    }

    public int Count()
    {
        return iCount;
    }
}

class program380
{
    public static void main(String A[])
    {
        StackX sobj = new StackX();
        int iRet = 0;

        sobj.push(10);
        sobj.push(20);
        sobj.push(30);
        sobj.push(40);
        sobj.push(50);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("number of elements in the stack are : "+iRet);
    
        iRet = sobj.pop();
        System.out.println("Popped element from stack is : "+iRet);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("number of elements in the stack are : "+iRet);
    
        iRet = sobj.pop();
        System.out.println("Popped element from stack is : "+iRet);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("number of elements in the stack are : "+iRet);
    
        iRet = sobj.pop();
        System.out.println("Popped element from stack is : "+iRet);
        sobj.Display();
    }
}