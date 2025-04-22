import java.util.*;
class Node 
{
    int data;
    Node next;
    Node prev;
    Node(int data)
    {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}
class DCLL 
{
    Node head = null;
    Node tail = null;
    public void create(int num)
    {
        Node newnode = new Node(num);
        if(head == null)
        {
            head = newnode;
            tail = newnode;
            newnode.next = head;
            newnode.prev = tail;
        }
        else 
        {
            tail.next=newnode;
            newnode.prev = tail;
            head.prev= newnode;
            newnode.next=head;
            tail=newnode;
        }
    }
    public Node split(Node head) 
    {
        Node slow = head;
        Node fast = head;
        while (fast.next != null && fast.next.next != null) 
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        Node temp = slow.next;
        slow.next =  null;
        head.prev = null;
        head.prev = null;
        temp.prev = null;
        return temp;
    }
    public Node merge(Node first, Node second) 
    {
        if (first == null) return second;
        if (second == null) return first;
        if (first.data < second.data) 
        {
            first.next = merge(first.next, second);
            first.next.prev = first;
            first.prev = null;
            return first;
        } 
        else 
        {
            second.next = merge(first, second.next);
            second.next.prev = second;
            second.prev = null;
            return second;
        }
    }
    public Node mergeSort(Node head) 
    {
        if (head == null || head.next == null) 
        {
            return head;
        }
        Node second = split(head);
        head = mergeSort(head);
        second = mergeSort(second);
        return merge(head, second);
    }
    public void sort_an_unsorted_DCLL()
    {
        if(head == null) 
        {
            return;
        }
        head.prev.next = null;
        head.prev = null;
        head = mergeSort(head);
        Node temp = head;
        while (temp.next != null) 
        {
            temp = temp.next;
        }
        temp.next = head;
        head.prev = temp;
    }
    public void display()
    {
        Node tptr = head;
        do
        {
            System.out.print(tptr.data+" ");
            tptr = tptr.next;
        }while(tptr != head);
    }
}
public class Sort_unsorted_DCLL 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        DCLL dcll = new DCLL();
        int num;
        while(true)
        {
            num = input.nextInt();
            if( num == -1 ) break;
            dcll.create(num);
        }
        dcll.sort_an_unsorted_DCLL();
        dcll.display();
        input.close();
    }
}