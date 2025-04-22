#include<stdio.h>
#include<malloc.h>
#include<string.h>
int cnt=1;
void display(int *arr,int size)
{
    for(int i=0;i<size && arr[i]!=-1;printf("%d ",arr[i]),i++);
    printf("\n\n");
}
int isSafe(int i,int j,int N,int M)
{
    if(i>=0 && i<N && j>=0 && j<M)
        return 1;
    else 
        return 0;
}
void solve(int ** maze,int i,int j,int *arr,int size,int N,int M,int ind)
{
    if(i==N-1 && j==M-1)
    {
        display(arr,size);
    }
    else
    {
        int next_i,next_j;
        next_i=i;next_j=j+1;
        if(isSafe(next_i,next_j,N,M))
        {
            arr[ind]=maze[next_i][next_j];
            solve(maze,next_i,next_j,arr,size,N,M,ind+1);
        }
        next_i=i+1;
        next_j=j;
        if(isSafe(next_i,next_j,N,M))
        {
            arr[ind]=maze[next_i][next_j];
            solve(maze,next_i,next_j,arr,size,N,M,ind+1);
        }
    }
    arr[ind]=-1;
}
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int size=N+M;
    int arr[size];
    for(int ind=0;ind<size;(arr[ind]=-1),ind++);
    int **maze;
    maze=(int**)malloc(sizeof(int*)*N);
    for(int ind=0;ind<N;ind++)
    {
        maze[ind]=(int*)malloc(sizeof(int)*M);
    }
    for(int i=0;i<N;i++)
    for(int j=0;j<M;scanf("%d",&maze[i][j++]));
    arr[0]=maze[0][0];
    solve(maze,0,0,arr,size,N,M,1);
}
/*

1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

*/