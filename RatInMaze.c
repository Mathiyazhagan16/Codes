#include<stdio.h>
#include<stdlib.h>
int cnt=1;
void display(int **maze,int N)
{
    printf("Solution no: %d\n",cnt++);
    for(int row = 0 ; row<N ;printf("\n"),row++)
    for(int col = 0 ; col<N ;printf("%d ",maze[row][col]),col++);
    printf("\n");
}
int isSafe(int row,int col,int N)
{
    return row<N && col<N && row>=0 && col>=0;
}
int solve(int **maze, int N , int row,int col)
{
    int r;
    int c;
    if(row==(N-1) && col==(N-1))
    {
        maze[row][col]=1;
        display(maze,N);
        maze[row][col]=0;
        return 0;
    }
    else
    {
        r = row;
        c = col + 1;
        if(isSafe(r,c,N))
        {
            maze[row][col] = 1;
            solve(maze,N,r,c);
            maze[row][col] = 0;
        }
        r = row + 1;
        c = col;
        if(isSafe(r,c,N))
        {
            maze[row][col] = 1;
            solve(maze,N,r,c);
            maze[row][col] = 0;
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int ** maze = (int**)calloc(N,sizeof(int*));
    for(int ind = 0; ind<N ; ind++)
    {
        maze[ind] = (int*)calloc(N,sizeof(int));
    }
    solve(maze,N,0,0);
    return 0;
}