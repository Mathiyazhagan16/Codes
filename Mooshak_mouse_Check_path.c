#include<stdio.h>
#include<stdlib.h>
#define N 8
void display(int ** maze)
{
    for(int row=0;row<N;printf("\n"),row++)
    for(int col=0;col<N;col++)
    printf("%c ",(maze[row][col]==2 || maze[row][col]==9)?(maze[row][col]+48):32);
}
int isSafe(int val)
{
    if(val>=0 && val<N) return 1;
    return 0;
}
int solve(int **maze,int row,int col)
{
    static int found=0;
    int next_row;
    int next_col;
    if(maze[row][col]==9)
    {
        display(maze);
    }
    else 
    {
        //Left
        next_row=row;
        next_col=col-1;
        if(isSafe(next_row) && isSafe(next_col) && (maze[next_row][next_col]==1 || maze[next_row][next_col]==9))
        {
            maze[row][col]=2;
            solve(maze,next_row,next_col);
            maze[row][col]=1;
        }
        //Top
        next_row=row-1;
        next_col=col;
        if(isSafe(next_row) && isSafe(next_col) && (maze[next_row][next_col]==1 || maze[next_row][next_col]==9))
        {
            maze[row][col]=2;
            solve(maze,next_row,next_col);
            maze[row][col]=1;
        }
        //Right
        next_row=row;
        next_col=col+1;
        if(isSafe(next_row) && isSafe(next_col) && (maze[next_row][next_col]==1 || maze[next_row][next_col]==9))
        {
            maze[row][col]=2;
            solve(maze,next_row,next_col);
            maze[row][col]=1;
        }
        //Down
        next_row=row+1;
        next_col=col;
        if(isSafe(next_row) && isSafe(next_col) && (maze[next_row][next_col]==1 || maze[next_row][next_col]==9))
        {
            maze[row][col]=2;
            solve(maze,next_row,next_col);
            maze[row][col]=1;
        }
    }
    return found;
}
int main()
{
    int **maze=(int**)malloc(N*sizeof(int*));
    for(int itr=0;itr<N;itr++)
    {
        maze[itr]=(int*)malloc(N*sizeof(int));
        for(int ind=0;ind<N;ind++)
        {
            scanf("%d",&maze[itr][ind]);
        }
    }
    solve(maze,0,0);
    return 0;
}