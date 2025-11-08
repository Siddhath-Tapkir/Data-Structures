class node
{
    public int no;
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
}

class program372
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();

    }
}