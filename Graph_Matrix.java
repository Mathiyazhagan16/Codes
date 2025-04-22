import java.util.*;
class G_Matrix
{
    final int N;
    int[][] graph;
    public G_Matrix(int Size)
    {
        this.N = Size;
        graph = new int[N][N];
    }
    public void Add(int src ,int dest)
    {
        graph[src][dest] = 1;
        graph[dest][src] = 1;
    }
    public void Display()
    {
        for(int row = 0 ; row < N ; row++)
        {
            for(int col = 0 ; col < N ; col++)
            {
                System.out.print(graph[row][col]+" ");
            }
            System.out.println();
        }
    }
}
public class Graph_Matrix 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        G_Matrix Graph = new G_Matrix(N);
        Graph.Add(0,1);
        Graph.Add(0,2);
        Graph.Add(0,3);
        Graph.Add(1,4);
        Graph.Add(2,3);
        Graph.Add(3,4);
        Graph.Display();
        input.close();
    }
}
