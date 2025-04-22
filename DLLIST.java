import java.util.*;
class Node
{
    int data;
    Node next;
    Node prev;
    Node(int num)
    {
        this.data = num;
        this.next = null;
        this.prev = null;
    }
}
class DLL
{
    Node head;
    Node tail;
    public void insert(int num)
    {
        Node newnode = new Node(num);
        if(head == null)
        {
            tail = head = newnode;
        }
        else 
        {
            tail.next = newnode;
            newnode.prev = tail;
            tail = newnode;
        }
    }
    public void displayF()
    {
        Node tptr = head;
        while(tptr != null)
        {
            System.out.print(tptr.data+" ");
            tptr = tptr.next;
        }
    }
    public void displayR()
    {
        Node tptr = tail;
        while(tptr != null)
        {
            System.out.print(tptr.data+" ");
            tptr = tptr.prev;
        }
    }
    public void Display()
    {
        displayF();
        System.out.println();
        displayR();
    }
}
public class DLLIST 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        DLL list = new DLL();
        int num;
        while(true)
        {
            num = input.nextInt();
            if(num == -1) break;
            list.insert(num);
        }
        list.Display();
        input.close();
    }
}
