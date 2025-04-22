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
            newnode.next = Head;
        }
        else 
        {
            Node tptr = Head;
            while(tptr.next != Head)
            {
                tptr = tptr.next;
            }
            tptr.next = newnode;
            newnode.next = Head;
        }
    }
    void display()
    {
        if(Head == null) return;
        Node tptr = Head;
        do
        {
            System.out.print(tptr.data+" ");
            tptr = tptr.next;
        }while(tptr != Head);
    }
}
public class CLL_Create_Display 
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
        List.display();
        input.close();
    }
}