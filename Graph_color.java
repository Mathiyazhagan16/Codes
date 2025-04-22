import java.util.*;
public class Graph_color 
{
    static int isSafe(int[][] G,int[] clr, int N ,int ind,int c)
    {
        for(int itr = 0 ; itr < ind ; itr++)
            if(G[itr][ind] == 1 && c == clr[itr])
                return 0;
        return 1;
    }
    static int Solve(int[][] G,int N,int[] clr,int C,int ind)
    {
        if(ind == N)
        {
            for(int itr = 0; itr < N ; itr++)
                System.out.print(clr[itr]+" ");
            System.out.println();
            return 1;
        }
        for(int c = 0 ; c<C ; c++)
            if(isSafe(G,clr,N,ind,c) == 1)
            {
                clr[ind] = c;
                if(Solve(G, N, clr, C, ind+1)==1) return 1;
                //Solve(G, N, clr, C, ind+1);
                clr[ind] = 0;
            }
        return 0;
    }
    public static void main(String[] args) 
    {
        int N = 5;
        int[][] G = new int[][]{{0,1,1,1,0},
                                {1,0,0,1,1},
                                {1,0,0,1,0},
                                {1,1,1,0,1},
                                {0,1,0,1,0}};
        int[] color = new int[N];
        int C = 3;
        color[0] = 0;
        System.out.printf("%s",(Solve(G,N,color,C,1)==1)?"":"Solution not available");
    }
}