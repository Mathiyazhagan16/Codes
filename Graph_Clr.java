import java.util.*;
public class Graph_Clr 
{
    static int N = 6;
    static int count=1;
    public static void Display(int[] color)
    {
        System.err.printf("Solution No: %d\n",count++);
        for(int ind = 0 ; ind < N ; ind++)
        {
            System.out.print(color[ind]+" ");
        }
        System.out.println();
    }
    public static int isSafe(int[][] graph,int [] color,int ind , int col)
    {
        for(int itr = 0 ; itr < ind ; itr++)
        {
            if(graph[itr][ind] == 1 && color[itr] == col)
            {
                return 0;
            }
        }
        return 1;
    }
    public static void Solve(int[][] graph,int clr,int ind,int [] color)
    {
        if(ind == N)
        {
            Display(color);
        }
        else 
        {
            for(int col = 0 ; col < clr ; col++)
            {
                if(isSafe(graph,color,ind,col) == 1)
                {
                    color[ind] = col;
                    Solve(graph,clr,ind+1,color);
                    color[ind] = 0;
                }
            }
        }
    }
    public static void main(String[] args) 
    {
        int[][] graph = new int[][]{{0,1,1,1,0,1},
        {1,0,0,0,1,1},
        {1,0,0,1,0,0},
        {1,0,1,0,1,0},
        {0,1,0,1,0,0},
        {1,1,0,0,0,0}};
        int Clr =  4;
        int[] color = new int[6];
        Solve(graph,Clr,1,color);
    }
}
