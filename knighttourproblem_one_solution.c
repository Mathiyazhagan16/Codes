#include<stdio.h>
#include<string.h>
#define N 9
void display(int board[N][N])
{
    for(int i=0;i<N;printf("\n"),i++)
    for(int j=0;j<N;printf("%02d ",board[i][j]),j++);
    printf("\n");
}
int issafe(int next_i,int next_j,int board[N][N])
{
    if(next_i>=0 && next_i<N && next_j>=0 && next_j<N && board[next_i][next_j]==-1) return 1;
    else return 0;
}
int solve(int cur_i,int cur_j,int move,int board[N][N],int x[],int y[])
{
    if(move==N*N) return 1;
    for(int i=0;i<8;i++)
    {
        int next_i = cur_i+x[i];
        int next_j = cur_j+y[i];
        if(issafe(next_i,next_j,board))
        {
            board[next_i][next_j]=move;
            if(solve(next_i,next_j,move+1,board,x,y))
            {
                return 1;
            }
            else
            {
                board[next_i][next_j]=-1;
            }
        }
    }
    return 0;
}
int main()
{
    int board[N][N];
    int x[]={-2,-2,-1,-1,1,1,2,2};
    int y[]={-1,1,-2,2,-2,2,-1,1};
    memset(board,-1,*board[N]);
    board[0][0]=0;
    if(solve(0,0,1,board,x,y))
        display(board);
}