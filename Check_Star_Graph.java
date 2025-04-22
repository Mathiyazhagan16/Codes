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
    int Check()
    {
        int ref1 = 0;
        int ref2 = 0;
        for(int row = 0 ; row < N ; row++)
        {
            int count = 0;
            for(int col = 0 ; col < N ; col++)
            {
                if(G[row][col] == 1)
                {
                    count++;
                }
            }
            if(count==1) ref1++;
            if(count==(N-1)) ref2++;
        }
        if((ref1 == (N-1)) && (ref2==1))
            return 1;
        return 0;
    }
}
public class Check_Star_Graph
{
    public static void main(String[] args) 
    {
        graph Graph = new graph(5);
        Graph.add(0,1);
        Graph.add(0,2);
        Graph.add(3,0);
        Graph.add(0,4);
        System.out.printf("%s",(Graph.Check()==1)?"Star":"Not");
    }
}
