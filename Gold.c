#include<stdio.h>
#include<limits.h>
void display(int N,int arr[N][N])
{
    for(int row=0;row<N;printf("\n"),row++)
        for(int col=0;col<N;printf("%02d ",arr[row][col]),col++);
}
int issafe(int row,int col,int N)
{
    if(row>=0 && row<N && col>=0 && col<N) return 1;
    return 0;
}
int max(int N,int arr[N][N],int row,int col)
{
    int MAX=INT_MIN;
    int r=row-1,c=col-1;
    if(issafe(r,c,N) && MAX<arr[r][c]) MAX=arr[r][c];
    r=row,c=col-1;
    if(issafe(r,c,N) && MAX<arr[r][c]) MAX=arr[r][c];
    r=row+1,c=col-1;
    if(issafe(r,c,N) && MAX<arr[r][c]) MAX=arr[r][c];
    return MAX;
}
void solve(int N,int arr[N][N])
{
    int row,col;
    for(row=1;row<N;row++)
    for(col=0;col<N;col++)
    arr[col][row]=arr[col][row]+max(N,arr,col,row);
}
int main()
{
    int N,row,col;
    scanf("%d",&N);
    int arr[N][N];
    for(row=0;row<N;row++)
    for(col=0;col<N;scanf("%d",&arr[row][col]),col++);
    solve(N,arr);
    //display(N,arr);
    int res=arr[0][N-1];
    for(int ind=0;ind<N;ind++)
        if(res<arr[ind][N-1]) res=arr[ind][N-1];
    printf("\n%d",res);
    return 0;
}

/*
4 
1 7 3 10
2 1 4 1
3 2 5 7
1 1 1 21



01 09 12 23 
02 04 13 14 
03 05 10 20 
01 04 06 31

MaxVal = 31
*/