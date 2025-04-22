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
    void SORTED_INSERT(int num)
    {
        Node newnode = new Node(num);
        if(Head == null)
        {
            Head = newnode;
        }
        else 
        {
            Node temp = null;
            Node tptr = null;
            for(tptr = Head ; tptr != null && tptr.data < num ; temp = tptr , tptr = tptr.next);
            if(tptr == Head)
            {
                newnode.next = Head;
                Head = newnode;
            }
            else if(tptr == null)
            {
                temp.next = newnode;
            }
            else 
            {
                temp.next = newnode;
                newnode.next = tptr;
            }
        }
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

public class Sorted_Insertion 
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
            List.SORTED_INSERT(num);
        }
        List.display();
    }
}