import java.util.*;
public class ListOfDoors 
{
    // public static void main(String[] args) 
    // {
    //     Scanner input = new Scanner(System.in);
    //     int N = input.nextInt();
    //     System.out.println((int)Math.sqrt(N));
    //     input.close();
    // }
    static Node head = null;
    static Node tail = null;
    public static void createList()
    {
        Node newnode = new Node(0);
        if(head == null)
        {
            head = newnode;
            tail = newnode;
        }
        else 
        {
            tail.next =  newnode;
            tail = newnode;
        }
    }
    static void Display()
    {
        Node tptr = head;
        while(tptr != null)
        {
            System.out.print(tptr.data+" ");
            tptr = tptr.next;
        }
    }
    static void Solve(int N)
    {
        for(int cle = 1 ; cle<=N ; cle++)
        {
            Node tptr = head;
            int count=1;
            while(tptr != null)
            {
                if(count%cle == 0)
                {
                    if(tptr.data == 1)
                        tptr.data = 0;
                    else 
                        tptr.data = 1;
                }
                tptr = tptr.next;
                count++;
            }
        }
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int itr = 1;
        while(itr <= N)
        {
            createList();
            itr++;
        }
        Solve(N);
        Display();
        input.close();
    }
}
