class node
{
    public int data;
    public node next;
}

class QueueX
{
    private node first;
    private int iCount;

    public QueueX()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void enqueue(int No) //InsertLast()
    {
        node newn = new node();
        node temp = null;

        newn.data = No;
        newn.next = null;

        if(null == this.first)
        {
            this.first = newn;
        }
        else
        {
            temp = this.first;
            
            while(null != temp.next)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }

        iCount++;
    }

    public int dequeue() // DeleteFirst()
    {
        node temp = this.first;
        
        if(null == this.first) //Stack empty
        {
            System.out.println("Unable to remove as queue is emtpy");
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
            System.out.print("| "+temp.data+" | -");
            temp = temp.next;
        }
        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

class program381
{
    public static void main(String A[])
    {
        QueueX sobj = new QueueX();
        int iRet = 0;

        sobj.enqueue(10);
        sobj.enqueue(20);
        sobj.enqueue(30);
        sobj.enqueue(40);
        sobj.enqueue(50);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("number of elements in the queue are : "+iRet);
    
        iRet = sobj.dequeue();
        System.out.println("Popped element from queue is : "+iRet);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("number of elements in the queue are : "+iRet);
    
        iRet = sobj.dequeue();
        System.out.println("Removed element from queue is : "+iRet);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("number of elements in the queue are : "+iRet);
    
        iRet = sobj.dequeue();
        System.out.println("Removed element from queue is : "+iRet);
        sobj.Display();
    }
}