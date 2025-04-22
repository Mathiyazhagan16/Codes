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
    int count()
    {
        int cnt = 0;
        Node tptr = Head;
        while(tptr != null)
        {
            cnt++;
            tptr = tptr.next;
        }
        return cnt;
    }
}
public class Count_Node 
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
        int cnt = List.count();
        System.out.println(cnt);
    }
}