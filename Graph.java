import java.util.LinkedList;
class Node 
{
    int data;
    Node next;

    public Node(int data) 
    {
        this.data = data;
        this.next = null;
    }
}
class Graph_ 
{
    int numVertices;
    Node[] adjList;
    Graph_(int numVertices) 
    {
        this.numVertices = numVertices;
        adjList = new Node[numVertices];
    }
    public void addEdge(int src, int dest) 
    {
        Node newNode = new Node(dest);
        if(adjList[src] == null) adjList[src] = newNode;
        else
        {
            newNode.next = adjList[src];
            adjList[src]=newNode;
        }
        newNode = new Node(src);
        if(adjList[dest] == null) adjList[dest] = newNode;
        else
        {
            newNode.next = adjList[dest];
            adjList[dest]=newNode;
        }
    }
    public void printGraph() 
    {
        for (int i = 0; i < numVertices; ++i) 
        {
            System.out.print("Adjacency list for vertex " + (i + 1) + ": ");
            Node node = adjList[i];
            while(node != null) 
            {
                System.out.print((node.data + 1) + " -> ");
                node = node.next;
            }
            System.out.println("NULL");
        }
    }
}
public class Graph 
{
    public static void main(String[] args) 
    {
        Graph_ graph = new Graph_(4);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.printGraph();
    }
}