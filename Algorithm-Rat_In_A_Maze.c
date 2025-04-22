#include<stdio.h>
#include<malloc.h>
#include<string.h>
int cnt=1;
void display(int **maze,int N,int M)
{
    printf("Path : %d\n",cnt++);
    for(int i=0;i<N;printf("\n"),i++)
    for(int j=0;j<M;printf("%2d ",maze[i][j]),j++);
    printf("\n");
}
int isSafe(int i,int j,int N,int M)
{
    if(i>=0 && i<N && j>=0 && j<M)
        return 1;
    else 
        return 0;
}
void solve(int ** maze,int i,int j,int N,int M,int val)
{
    if(i==N-1 && j==M-1)
    {
        display(maze,N,M);
    }
    else
    {
        int next_i,next_j;
        next_i=i;next_j=j+1;
        if(isSafe(next_i,next_j,N,M))
        {
            maze[next_i][next_j]=val;
            solve(maze,next_i,next_j,N,M,val);
        }
        next_i=i+1;
        next_j=j;
        if(isSafe(next_i,next_j,N,M))
        {
            maze[next_i][next_j]= val;
            solve(maze,next_i,next_j,N,M,val);
        }
    }
    maze[i][j]=0;
}
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int **maze;
    maze=(int**)malloc(sizeof(int*)*N);
    for(int ind=0;ind<N;ind++)
    {
        maze[ind]=(int*)malloc(sizeof(int)*M);
        memset(maze[ind],0,M*sizeof(int));
    }
    maze[0][0]=1;
    solve(maze,0,0,N,M,1);
}


/*

Given a Maze of N*N matrix of blocks. Consider the source block is the upper left most block i.e., Maze[0][0] and destination block is lower rightmost block i.e., Maze[N-1][N-1]. Consider a rat is placed on a source block and has to reach the destination. The rat can be allowed to move only in two directions (forward and down).
Print all the possible paths that th e rat can move to reach the destination block.


*/