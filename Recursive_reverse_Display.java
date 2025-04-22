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
    // Node Tail = null;
    void CREATE_NODE(int num)
    {
        Node newnode = new Node(num);
        if(Head == null)
        {
            Head = newnode;
            // Tail = newnode;
        }
        else 
        {
            Node tptr = Head;
            while(tptr.next != null)
            {
                tptr = tptr.next;
            }
            tptr.next = newnode;
            // Tail.next = newnode;
            // Tail = newnode;
        }
    }
    void reverse_display_Helper(Node tptr)
    {
        if(tptr != null)
        {
            reverse_display_Helper(tptr.next);
            System.out.print(tptr.data+" ");
        }
    }
    void reverse_display()
    {
        reverse_display_Helper(Head);
    }
}
public class Recursive_reverse_Display
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
        List.reverse_display();
    }
}