import java.util.*;
public class PrintPaths 
{ 
    public static void display(int N,int M,int[][] matrix)
    {
        for(int row = 0; row < N; row++)
        {
            for(int col = 0; col < M ; col++)
            {
                System.out.print(matrix[row][col]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }
    public static void Solution(int N,int M,int[][] matrix,int row,int col)
    {
        if(row == N-1 && col == M-1)
        {
            matrix[row][col] = 1;
            display(N,M,matrix);
            matrix[row][col] = 0;
        }
        else 
        {
            int next_row = row;
            int next_col = col + 1;
            if(next_row < N && next_col < M)
            {
                matrix[row][col] = 1;
                Solution(N,M,matrix,next_row,next_col);
                matrix[row][col] = 0;
            }
            next_row = row + 1;
            next_col = col;
            if(next_row < N && next_col < M)
            {
                matrix[row][col] = 1;
                Solution(N,M,matrix,next_row,next_col);
                matrix[row][col] = 0;
            }
        }
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int row = input.nextInt();
        int col = input.nextInt();
        int[][] matrix = new int[row][col];
        matrix[0][0] = 1;
        Solution(row,col,matrix,0,0);
        input.close();
    }
}
