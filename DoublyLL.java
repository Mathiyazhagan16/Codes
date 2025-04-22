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
class DLinkedList
{
    Node head;
    Node tail;
    public void InsertAtEnd(int num)
    {
        Node newnode = new Node(num);
        if(head == null)
        {
            head = newnode;
            tail = newnode;
        }
        else 
        {
            tail.next = newnode;
            newnode.prev = tail;
            tail = newnode;
        }
        tail.next = head;
        head.prev = tail;
    }
    public void InsertAtBegin(int num)
    {
        Node newnode = new Node(num);
        if(head == null)
        {
            head = newnode;
            tail = newnode;
        }
        else 
        {
            newnode.next = head;
            head.prev = newnode;
            head = newnode;
        }
        tail.next = head;
        head.prev = tail;
    }
    public void DisplayF()
    {
        Node tptr = head;
        do
        {
            System.out.print(tptr.data + " ");
            tptr = tptr.next;
        }while(tptr != head);
    }
    public void DisplayR()
    {
        Node tptr = tail;
        do
        {
            System.out.print(tptr.data + " ");
            tptr = tptr.prev;
        }while(tptr != tail);
    }
}
public class DoublyLL 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        DLinkedList List = new DLinkedList();
        List.InsertAtEnd(10);
        List.InsertAtEnd(20);
        List.InsertAtEnd(30);
        List.InsertAtEnd(40);
        List.InsertAtEnd(50);
        List.InsertAtBegin(60);
        List.InsertAtBegin(70);
        List.InsertAtBegin(80);
        List.InsertAtBegin(90);
        List.InsertAtBegin(100);
        List.DisplayF();
        System.out.println();
        List.DisplayR();
        input.close();
    }
}
