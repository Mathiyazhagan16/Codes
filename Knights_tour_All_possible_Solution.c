#include<stdio.h>
#include<stdlib.h>
int cnt = 1;
int x[] = {1,2,2,1,-1,-2,-2,-1};
int y[] = {2,1,-1,-2,-2,-1,1,2};
void display(int N,int **board)
{
    printf("Solution no : %d\n",cnt++);
    for(int row = 0 ; row < N ; row++)
    {
        for(int col = 0 ; col < N ; col++)
        {
            printf("%02d ",board[row][col]);
        }
        printf("\n");
    }
}
int isSafe(int N,int ** board,int row,int col)
{
    return row>=0 & row<N && col>=0 && col<N && board[row][col]==0;
}
int solve(int N,int** board,int row,int col,int moves)
{
    //Write your code here
    if(moves == N*N+1)
    {
        display(N,board);
        return 1;
    }
    else 
    {
        for(int ind = 0 ; ind < 8 ; ind++)
        {
            int next_row = row + x[ind];
            int next_col = col + y[ind];
            if(isSafe(N,board,next_row,next_col) == 1)
            {
                board[next_row][next_col] = moves;
                solve(N,board,next_row,next_col,moves+1);
                board[next_row][next_col] = 0;
            }
        }
    }
    return 0;
}
int main()
{
    int N;
    scanf("%d",&N);
    int ** board;
    board = (int**)calloc(N,sizeof(int*));
    for(int ind = 0 ; ind < N ; ind++)
    {
        board[ind] = (int*)calloc(N,sizeof(int));
    }
    board[0][0] = 1;
    printf("%s",solve(N,board,0,0,2) == 1 ?"Solution Available":"Solution Not Available");
    return 0;
}

