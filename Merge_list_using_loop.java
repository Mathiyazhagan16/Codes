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
class List 
{
    Node Head = null;
    void create_list(int num)
    {
        Node newnode = new Node(num);
        if(Head == null)
        {
            Head = newnode;
        }
        else 
        {
            Node tptr = null;
            Node temp = null;
            for(tptr = Head ; tptr != null && tptr.data < num ; temp = tptr , tptr  =tptr.next);
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
    Node merge_sorted_list(List list2)
    {
        Node Head1 = Head;
        Node Head2 = get_head(list2);
        Node new_Head = null;
        // System.out.print(Head1.data+" "+Head2.data);
        while(Head1 != null && Head2 != null)
        {
            Node temp;
            if(Head1.data < Head2.data)
            {
                temp = Head1;
                Head1 = Head1.next;
            }
            else 
            {
                temp = Head2;
                Head2 = Head2.next;
            }
            temp.next = null;
            if(new_Head == null)
            {
                new_Head = temp;
            }
            else 
            {
                Node tptr = new_Head;
                while(tptr.next != null)
                {
                    tptr = tptr.next;
                }
                tptr.next = temp;
            }
        }
        if(Head1 != null)
        {
            Node tptr = new_Head;
            while(tptr.next != null)
            {
                tptr = tptr.next;
            }
            tptr.next = Head1;
        }
        if(Head2 != null)
        {
            Node tptr = new_Head;
            while(tptr.next != null)
            {
                tptr = tptr.next;
            }
            tptr.next = Head2;
        }
        return new_Head;
    }
    Node get_head(List List2)
    {
        return List2.Head;
    }
}
public class Merge_list_using_loop 
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        List list1 = new List();
        List list2 = new List();
        List list3 = new List();
        int num;
        while(true)
        {
            num = input.nextInt();
            if(num == -1) break;
            list1.create_list(num);
        }
        // list1.display();
        System.out.println();
        while(true)
        {
            num = input.nextInt();
            if(num == -1) break;
            list2.create_list(num);
        }
        // list2.display();
        list3.Head = list1.merge_sorted_list(list2);
        list3.display();
    }
}