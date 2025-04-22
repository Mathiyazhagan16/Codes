import java.util.*;
public class sudoku 
{
    public static void display(int N,int[][] sudoku)
    {
        for(int row = 0 ; row < N ; row++)
        {
            for(int col = 0 ; col < N ; col++)
            {
                System.out.print(sudoku[row][col]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }
    public static boolean isSafe(int N,int[][] sudoku,int row,int col,int val)
    {
        for(int ind = 0 ; ind < N ; ind++)
        {
            if(sudoku[row][ind] == val)
            {
                return false;
            }
        }
        for(int ind = 0 ; ind < N ; ind++)
        {
            if(sudoku[ind][col] == val)
            {
                return false;
            }
        }
        int c_row = row / 3 * 3;
        int c_col = col / 3 * 3;
        for(int r = c_row ; r < c_row+3 ; r++)
        {
            for(int c = c_col ; c < c_col+3 ; c++)
            {
                if(sudoku[r][c] == val)
                {
                    return false;
                }
            }
        }
        return true;
    }
    public static void Solve(int N,int[][] sudoku,int row,int col)
    {
        if(row == N)
        {
            display(N,sudoku);
        }
        else 
        {
            if(col == N)
            {
                Solve(N,sudoku,row+1,0);
            }
            else if(sudoku[row][col] == 0)
            {
                for(int val = 1 ; val <= 9 ; val++)
                {
                    if(isSafe(N,sudoku,row,col,val) == true)
                    {
                        sudoku[row][col] = val;
                        Solve(N,sudoku,row,col+1);
                        sudoku[row][col] = 0;
                    }
                }
            }
            else 
            {
                Solve(N,sudoku,row,col+1);
            }
        }
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = 9;
        int[][] sudoku = new int[N][N];
        for(int row = 0 ; row < N ; row++)
        {
            for(int col = 0 ; col < N ; col++)
            {
                sudoku[row][col] = input.nextInt();
            }
        }
        Solve(N,sudoku,0,0);
        input.close();
    }
}





/*
 * 
 * 
 * 
 * 
0 2 5 3 4 0 0 0 8
0 6 0 0 0 1 0 7 0
0 5 3 0 0 0 0 2 9
6 1 0 0 0 9 8 0 0
0 0 0 6 0 2 0 0 7
0 0 1 0 9 3 2 0 0
0 0 8 0 0 0 0 0 0
0 4 0 0 7 8 5 9 1



1 3 7 9 8 6 4 5 2 
9 2 5 3 4 7 1 6 8 
8 6 4 5 2 1 9 7 3 
7 5 3 8 1 4 6 2 9 
6 1 2 7 3 9 8 4 5
4 8 9 6 5 2 3 1 7 
5 7 1 4 9 3 2 8 6
2 9 8 1 6 5 7 3 4
3 4 6 2 7 8 5 9 1





1	0	7	0	0	6	4	5	0
0	0	5	3	4	0	0	0	0
0	0	0	0	0	1	0	7	0
0	5	3	0	0	0	0	2	9
6	1	0	0	0	9	8	0	0
0	0	0	0	0	2	0	0	0
0	0	1	0	9	3	2	0	0
0	0	0	0	0	0	0	0	0
0	4	0	0	7	8	0	9	1





 */