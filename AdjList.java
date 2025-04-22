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
class graph
{
    int N;
    Node[] start;
    graph(int N)
    {
        this.N = N;
        start = new Node[N];
    }
    void add(int src,int dest)
    {
        Node newnode = new Node(dest);
        if(start[src] == null)
        {
            start[src] = newnode;
        }
        else 
        {
            newnode.next = start[src];
            start[src] = newnode;
        }
        newnode = new Node(src);
        if(start[dest] == null)
        {
            start[dest] = newnode;
        }
        else 
        {
            newnode.next = start[dest];
            start[dest] = newnode;
        }
    }
    void Display()
    {
        for( int ind = 0 ; ind < N ; ind++ )
        {
            Node tptr = start[ind];
            System.out.printf("From source %d -> ",ind);
            while(tptr != null)
            {
                System.out.print(" -> "+tptr.data);
                tptr = tptr.next;
            }
            System.out.println();
        }
    }
}
public class AdjList 
{
    public static void main(String[] args) 
    {
        graph Graph = new graph(5);
        Graph.add(0,1);
        Graph.add(0,2);
        Graph.add(1,2);
        Graph.add(1,3);
        Graph.add(1,4);
        Graph.add(2,3);
        Graph.add(3,4);
        Graph.Display();
    }
}
