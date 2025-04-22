import java.util.*;
class Node
{
    int data;
    Node next;
    Node(int num)
    {
        this.data = num;
        this.next = null;
    }
}
class GraphList
{
    final int N;
    Node[] List;
    public GraphList(int Size)
    {
        this.N = Size;
        List = new Node[N];
    }
    public void Add(int src , int dest)
    {
        Node newnode = new Node(dest);
        if(List[src] == null) List[src] = newnode;
        else 
        {
            newnode.next = List[src];
            List[src] = newnode;
        }
        newnode = new Node(src);
        if(List[dest] == null) List[dest] = newnode;
        else 
        {
            newnode.next = List[dest];
            List[dest] = newnode;
        }
    }
    public void Display()
    {
        for(int ind = 0 ; ind < N ; ind++)
        {
            Node tptr = List[ind];
            System.out.printf("Source %d to -> ",ind);
            while(tptr != null)
            {
                System.out.print(tptr.data+" ");
                tptr = tptr.next;
            }
            System.out.println();
        }
    }
}
public class Graph_List 
{
    public static void main(String[] args) 
    {
        GraphList List = new GraphList(5);
        List.Add(0,1);
        List.Add(0,2);
        List.Add(0,3);
        List.Add(1,4);
        List.Add(2,3);
        List.Add(3,4);
        List.Display();
    }
}
