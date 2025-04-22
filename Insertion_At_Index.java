import java.util.*;
class Node 
{
    int data;
    Node next;
    Node(int data)
    {
        this.data = data;
        this.next = null;
    }
}
class LinkedList
{
    Node Head = null;
    void CREATE_NODE(int num)
    {
        Node newnode = new Node(num);
        if(Head == null)
        {
            Head = newnode;
        }
        else 
        {
            Node tptr = Head;
            while(tptr.next != null)
            {
                tptr = tptr.next;
            }
            tptr.next = newnode;
        }
    }
    void InsertAtIndex(int index , int ele)
    {
        if(Head == null)
        {
            System.out.print("List is Empty");
            return;
        }
        if(index == 0)
        {
            Node newnode = new Node(ele);
            newnode.next = Head;
            Head = newnode;
            return;
        }
        int count = 1;
        Node tptr = Head;
        while(tptr != null && count < index)
        {
            tptr = tptr.next;
            count++;
        }
        if(tptr == null)
        {
            System.out.print("Index out of boundary\n");
            return;
        }
        Node newnode = new Node(ele);
        newnode.next = tptr.next;
        tptr.next = newnode;
    }
    void display()
    {
        Node tptr = Head;
        while(tptr != null)
        {
            System.out.print(tptr.data+" ");
            tptr = tptr.next;
        }
    }
}
public class Insertion_At_Index 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        LinkedList List = new LinkedList();
        int num;
        while(true)
        {
            num = input.nextInt();
            if(num == -1) break;
            List.CREATE_NODE(num);
        }
        int pos = input.nextInt();
        int ele = input.nextInt();
        List.InsertAtIndex(pos,ele);
        List.display();
        input.close();
    }
}