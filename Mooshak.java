import java.util.*;
public class Mooshak 
{
    static int[] r = new int[]{0,-1,0,1};
    static int[] c = new int[]{-1,0,1,0};
    static int found = 0; 
    public static boolean isSafe(int N ,int[][] maze,int row,int col)
    {
        return (row>=0 && col>=0 && row<N && col<N && maze[row][col]!=0 && maze[row][col]!=2);
    }
    public static void Display(int N ,int[][] maze)
    {
        for(int row = 0 ; row < N ; row++)
        {
            for(int col = 0 ; col < N ; col++)
            {
                if(maze[row][col] == 2 || maze[row][col]==9)
                    System.out.print(maze[row][col]+" ");
                else 
                    System.out.print("  ");
            }
            System.out.println();
        }
        System.out.println();
    }
    public static int isPath(int N,int[][] maze,int row,int col)
    {
        if(maze[row][col] == 9)
        {
            Display(N,maze);
            found = 1;
            return 1;
        }
        else 
        {
            for(int ind = 0 ; ind<4 ; ind++)
            {
                int nrow = row + r[ind];
                int ncol = col + c[ind];
                if((isSafe(N,maze,nrow,ncol))==true)
                {
                    maze[row][col] = 2;
                    isPath(N,maze,nrow,ncol);
                    maze[row][col] = 1;
                }
            }
        }
        return found;
    }
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[][] maze = new int[N][N];
        for(int row = 0 ; row < N ; row++)
            for(int col = 0 ; col < N ; col++)
                maze[row][col] = input.nextInt();
        System.out.printf("%d",(isPath(N,maze,0,0)==1)?1:0);
        input.close();
    }
}
