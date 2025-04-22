import java.util.*;
class Node 
{
    int data;
    Node next;
    Node(int num)
    {
        data = num;
        next = null;
    }
}
class ref_Node 
{
    Node ref;
    ref_Node add;
    ref_Node(Node ref)
    {
        this.ref = ref;
        this.add = null;
    }
}
class List 
{
    Node Head = null;
    void Create_List(int num)
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
    void display()
    {
        Node tptr = Head;
        while(tptr != null)
        {
            System.out.print(tptr.data+" ");
            tptr = tptr.next;
        }
    }
    void create_loop(int index)
    {
        Node tptr = Head;
        Node temp = null;
        int itr = 0;
        while(tptr.next != null)
        {
            if(itr == index)
            {
                temp = tptr;
            }
            tptr = tptr.next;
            itr++;
        }
        tptr.next = temp;
    }
    void remove_loop()
    {
        Node tptr = Head;
        Node prev = null;
        ref_Node ref_head = null;
        while(true)
        {
            if(ref_head == null)
            {
                ref_Node newnode = new ref_Node(tptr);
                ref_head = newnode;
            }
            else 
            {
                ref_Node newnode = new ref_Node(tptr);
                ref_Node ptr = ref_head;                
                ref_Node temp = null;               
                while(ptr != null)
                {
                    if(ptr.ref == tptr)
                        break;
                    temp = ptr;
                    ptr = ptr.add;
                }
                if(ptr == null)
                    temp.add = newnode;
                else 
                {
                    prev.next = null;
                    break;
                }
            }
            prev = tptr;
            tptr = tptr.next;
        }
    }
}
public class Loop_Creation_and_removal
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        List list = new List();
        int num;
        while(true)
        {
            num = input.nextInt();
            if(num == -1) break;
            list.Create_List(num);
        }
        int N = list.count();
        System.out.println(N);
        int pos = input.nextInt();
        list.create_loop(pos);
        list.remove_loop();
        list.display();
    }
}