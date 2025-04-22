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
    int max()
    {
        int max = Head.data;
        for(Node tptr = Head ; tptr != null ; tptr = tptr.next)
        {
            if(max < tptr.data)
                max = tptr.data;
        }
        return max;
    }
}
public class SLL_Max 
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
         System.out.println(List.max());
        input.close();
    }
}