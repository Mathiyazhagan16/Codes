import java.util.*;
public class Warndorff_algorithm 
{   
    static int N = 8; 
    static int[][] board = new int[N][N]; 
    static int[] moveX = {2, 1, -1, -2, -2, -1, 1, 2}; 
    static int[] moveY = {1, 2, 2, 1, -1, -2, -2, -1};  
    static void solveKnightTour(int startX, int startY) 
    {    
        board[startX][startY] = 1; 
        int moveCount = 2;
        if (solveKTUtil(startX, startY, moveCount)) 
        { 
             System.out.println("Knight's tour is possible");  
        } 
        else 
        {      
            System.out.println("Knight's tour is not possible");   
        } 
    }
    static boolean solveKTUtil(int x, int y, int moveCount) 
    {    
        if (moveCount > N * N) 
        {   
            return true; 
        }     
        for (int i = 0; i < 8; i++) 
        {
            int nextX = x + moveX[i];    
            int nextY = y + moveY[i];     
            if (isSafe(nextX, nextY)) 
            {      
                board[nextX][nextY] = moveCount;      
                if (solveKTUtil(nextX, nextY, moveCount + 1))   return true;
                else 
                {         
                    board[nextX][nextY] = 0;    
                } 
            }  
        }       
        return false;
    }
    static boolean isSafe(int x, int y) 
    {      
        return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0);   
    }   
    static void printChessboard() 
    {     
        for (int[] row : board) 
        {   
            for (int cell : row) 
            {      
                System.out.printf("%2d ", cell);     
            }            
            System.out.println();      
        }  
    }
    public static void main(String[] args) 
    {   
        solveKnightTour(0, 0);
        printChessboard();    
    }
}           