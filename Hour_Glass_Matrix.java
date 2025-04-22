import java.util.*;
public class Hour_Glass_Matrix 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int R_size = input.nextInt();
        int C_size = input.nextInt();
        int[][] arr = new int[R_size][C_size];
        for( int row = 0 ; row < R_size ; row++)
        for( int col = 0 ; col < C_size ; col++)
        arr[row][col] = input.nextInt();
        int max = arr[0][0];
        for( int row = 0 ; row < R_size - 2 ; row++)
        {
            int sum = 0;
            for( int col = 0 ; col < C_size - 2 ; col++)
            {
                sum = arr[row][col] + 
                      arr[row][col+1] + 
                      arr[row][col+2] +
                      arr[row+1][col+1] +
                      arr[row+2][col] +
                      arr[row+2][col+1] +
                      arr[row+2][col+2];
                max = Math.max(sum,max);
            }
        }
        System.out.print(max);
        input.close();    
    }
}



1 2 3 4 
1 2 3 4
1 2 3 4
1 2 3 4