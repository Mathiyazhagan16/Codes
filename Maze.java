import java.util.*;
public class Maze
{
    static int[] r = {0,-1,0,1};
    static int[] c = {-1,0,1,0};
    public static boolean isSafe(int N,int[][] maze , int row,int col)
    {
        return col>=0 && col<N && row>=0 && row<N && maze[row][col]!=0 && maze[row][col]!=2;
    }
    public static int Solve(int N,int[][] maze , int row,int col)
    {
        if(maze[row][col] == 9)
        {
            return 1;
        }
        else 
        {
            for(int ind = 0 ; ind < 4 ; ind++)
            {
                int n_row = row + r[ind];
                int n_col = col + c[ind];
                if(isSafe(N,maze,n_row,n_col)==true)
                {
                    maze[row][col] = 2;
                    if(Solve(N,maze,n_row,n_col)==1) return 1;
                    maze[row][col] = 1;
                }
            }
        }
        return 0;
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[][] maze = new int[N][N];
        for(int row = 0 ; row < N ; row++)
            for(int col = 0 ; col < N ; col++)
                maze[row][col] = input.nextInt();
        System.out.printf("%d" ,Solve(N,maze,0,0));
    }
}