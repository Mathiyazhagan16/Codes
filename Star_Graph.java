import java.util.*;
public class Star_Graph 
{
    public static int Check_Star_Graph(int[][] graph , int N)
    {
        int centre = 0;
        int surr = 0;
        for(int row = 0 ; row < N ; row++)
        {
            int count = 0;
            for(int col = 0 ; col < N ; col++)
            {
                if(graph[row][col] == 1)
                {
                    count++;
                }
            }
            if(count == N-1)
            {
                centre++;
            }
            else if(count == 1)
            {
                surr++;
            }
        }
        if(centre == 1 && surr == N-1) return 1;
        return 0;
    }
    public static void main(String[] args) 
    {
        int N = 4;
        int[][] graph = new int[][]{{0,1,1,1},
                                    {1,0,0,0},
                                    {1,0,0,0},
                                    {1,0,0,0}};
        System.out.printf("%s",(Check_Star_Graph(graph,N)==1)?"Yes":"No");;
    }
}
