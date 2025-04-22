import java.util.*;
class graph
{
    int N;
    int[][] G;
    graph(int N)
    {
        this.N = N;
        G = new int[N][N];
    }
    void add(int src,int dest)
    {
        G[src][dest] = 1;
        G[dest][src] = 1;
    }
    void Display()
    {
        for(int row = 0 ; row < N ; row++)
        {
            for(int col = 0 ; col < N ; col++)
                System.out.print(G[row][col]+" ");
            System.out.println();
        }
    }
}
public class AdjMat 
{
    public static void main(String[] args) 
    {
        graph Graph = new graph(5);
        graph Graph = new graph(5);
        graph Graph = new graph(5);
        graph Graph = new graph(5);
        Graph.add(0,1);
        Graph.add(0,2);
        Graph.add(1,2);
        Graph.add(1,2);
        Graph.add(1,3);
        Graph.add(1,4);
        Graph.add(2,3);
        Graph.add(3,4);
        Graph.Display();
    }
}
