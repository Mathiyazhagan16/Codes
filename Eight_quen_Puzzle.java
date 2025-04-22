import java.util.*;
public class Eight_quen_Puzzle 
{
    public static boolean check(int N , int [][] mat , int row,int col)
    {
        int temp_row;
        int temp_col;
        for(temp_row = row-1 ; temp_row >= 0 ; temp_row--)
        {
            if(mat[temp_row][col] == 1)
            {
                return false;
            }
        }
        for(temp_col = col-1 ; temp_col >= 0 ; temp_col--)
        {
            if(mat[row][temp_col] == 1)
            {
                return false;
            }
        }
        for(temp_row = row-1 , temp_col = col-1 ; temp_row >= 0 && temp_col >= 0 ; temp_row-- , temp_col--)
        {
            if(mat[temp_row][temp_col] == 1)
            {
                return false;
            }
        }
        for(temp_row = row-1 , temp_col = col+1 ; temp_row >= 0 && temp_col < N ; temp_row-- , temp_col++)
        {
            if(mat[temp_row][temp_col] == 1)
            {
                return false;
            }
        }
        return true;
    }
    public static boolean Verify(int N,int[][] mat)
    {
        for(int row = 0 ; row < 8 ; row++)
        {
            for(int col = 0 ; col < 8 ; col++)
            {
                if(mat[row][col] == 1)
                {
                    if(check(N,mat,row,col) == false)
                    {
                        return false;
                    }
                }
            }
        } 
        return true;
        
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = 8;
        int[][] matrix = new int[N][N];
        for(int row = 0 ; row < 8 ; row++)
            for(int col = 0 ; col < 8 ; col++)
                matrix[row][col] = input.nextInt();
        System.out.printf("%s",(Verify(N,matrix)==true)?"Valid":"Invalid");
        input.close();
    }
}
