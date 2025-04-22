
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
    int sum()
    {
        int sum = 0;
        for(Node tptr = Head ; tptr != null ; tptr = tptr.next)
        {
            sum+=tptr.data;
        }
        return sum;
    }
}
public class SLL_Sum 
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
         System.out.println(List.sum());
        input.close();
    }
}
