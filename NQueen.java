import java.util.*;
public class NQueen 
{
    static int cnt = 1;
    static int found = 0;
    public static void Display(int N,int[][] matrix)
    {
        System.out.printf("Solution no : %d\n",cnt++);
        for(int row = 0 ; row < N ; row++)
        {
            for(int col = 0 ; col < N ; col++)
            {
                System.out.printf("%c ",matrix[row][col] == 1?'Q':'-');
            }
            System.out.println();
        }
        System.out.println();
    }
    public static int isSafe(int N,int[][] matrix,int row,int col)
    {
        int r=0,c=0;
        for(r=row,c=col;r>=0;r--)
            if(matrix[r][c] == 1) return 0;
        for(r=row,c=col;r>=0 && c>=0;r--,c--)
            if(matrix[r][c] == 1) return 0;
        for(r=row,c=col;r>=0 && c<N;r--,c++)
            if(matrix[r][c] == 1) return 0;
        return 1;
    }
    public static void Solve(int N,int[][] matrix,int row)
    {
        if(row == N)
        {
            Display(N,matrix);
            found = 1;
        }
        else 
        {
            for(int col = 0 ; col < N ; col++)
            {
                if(isSafe(N,matrix,row,col)==1 && found == 0)
                {
                    matrix[row][col] = 1;
                    Solve(N, matrix, row+1);
                    matrix[row][col] = 0;
                }
            }
        }
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[][] matrix = new int[N][N];
        Solve(N,matrix,0);
        input.close();
    }
}






/*
 


import java.util.*;
public class NQueen 
{
    static int cnt = 1;
    public static void Display(int N,int[][] matrix)
    {
        System.out.printf("Solution no : %d\n",cnt++);
        for(int row = 0 ; row < N ; row++)
        {
            for(int col = 0 ; col < N ; col++)
            {
                System.out.printf("%c ",matrix[row][col] == 1?'Q':'-');
            }
            System.out.println();
        }
        System.out.println();
    }
    public static int isSafe(int N,int[][] matrix,int row,int col)
    {
        int r=0,c=0;
        for(r=row,c=col;r>=0;r--)
            if(matrix[r][c] == 1) return 0;
        for(r=row,c=col;r>=0 && c>=0;r--,c--)
            if(matrix[r][c] == 1) return 0;
        for(r=row,c=col;r>=0 && c<N;r--,c++)
            if(matrix[r][c] == 1) return 0;
        return 1;
    }
    public static void Solve(int N,int[][] matrix,int row)
    {
        if(row == N)
        {
            Display(N,matrix);
        }
        else 
        {
            for(int col = 0 ; col < N ; col++)
            {
                if(isSafe(N,matrix,row,col)==1)
                {
                    matrix[row][col] = 1;
                    Solve(N, matrix, row+1);
                    matrix[row][col] = 0;
                }
            }
        }
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[][] matrix = new int[N][N];
        Solve(N,matrix,0);
        input.close();
    }
}







import java.util.*;
public class NQueen 
{
    static int cnt = 1;
    static int found = 0;
    // public static void Display(int N,int[][] matrix)
    // {
    //     System.out.printf("Solution no : %d\n",cnt++);
    //     for(int row = 0 ; row < N ; row++)
    //     {
    //         for(int col = 0 ; col < N ; col++)
    //         {
    //             System.out.printf("%c ",matrix[row][col] == 1?'Q':'-');
    //         }
    //         System.out.println();
    //     }
    //     System.out.println();
    // }
    public static int isSafe(int N,int[][] matrix,int row,int col)
    {
        int r=0,c=0;
        for(r=row,c=col;r>=0;r--)
            if(matrix[r][c] == 1) return 0;
        for(r=row,c=col;r>=0 && c>=0;r--,c--)
            if(matrix[r][c] == 1) return 0;
        for(r=row,c=col;r>=0 && c<N;r--,c++)
            if(matrix[r][c] == 1) return 0;
        return 1;
    }
    public static void Solve(int N,int[][] matrix,int row)
    {
        if(row == N)
        {
            found = 1;
        }
        else 
        {
            for(int col = 0 ; col < N ; col++)
            {
                if(isSafe(N,matrix,row,col)==1 && found == 0)
                {
                    matrix[row][col] = 1;
                    Solve(N, matrix, row+1);
                    matrix[row][col] = 0;
                }
            }
        }
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[][] matrix = new int[N][N];
        System.out.printf("%d ",Solve(N,matrix,0));
        input.close();
    }
}














 */