#include<stdio.h>
#include<string.h>
#include<malloc.h>
int N,space=0;
int x[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
int y[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };
void display(int ** board)
{
    for(int row=0;row<N;printf("\n"),row++)
        for(int col=0;col<N;printf("%02d ",board[row][col]),col++);
        printf("\n\n");
}
int isSafe(int ** board,int row,int col)
{
    if(row<N && row>=0 && col<N && col>=0 && board[row][col]==-1) return 1;
    else return 0; 
}
int KnightTour(int ** board,int row,int col,int move,int moves)
{
    int i;
    if(move==moves)
    {
        space=1;
        display(board);
        return space;
    }
    for(i=0;i<8;i++)
    {
        int nextr=row+x[i];
        int nextc=col+y[i];
        if(isSafe(board,nextr,nextc) && space==0)
        {
            board[nextr][nextc]=move;
            if(KnightTour(board,nextr,nextc,move+1,moves) && space==0)
                return space;
            else 
            {
                board[nextr][nextc]=-1;
            }
        }
    }
    return space;
}
int main()
{
    int f,r,moves=0;
    scanf("%d",&N);
    int ** board;
    board=(int**)malloc(sizeof(int*)*N);
    for(int ind=0;ind<N;ind++)
    {
        board[ind]=(int*)calloc(N,sizeof(int));
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&f,&r);
        for(int ind=f;ind<f+r;(board[i][ind++]=-1));
        if(f<N)
        moves+=(f+r);
    }
    board[0][0]=1;
    if(!(KnightTour(board,0,0,2,moves)))
        printf("Not Possible");
    return 0;
}




1 6  3  0 0
4 10 7  0 0
6 2  5  9 0
0 8  0  0 0
0 0  0  0 0














#include<stdio.h>
#include<string.h>
#include<malloc.h>
int N,space=0;
int x[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
int y[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };
void display(int ** board)
{
    for(int row=0;row<N;printf("\n"),row++)
        for(int col=0;col<N;printf("%02d ",board[row][col]),col++);
        printf("\n\n");
}
int isSafe(int ** board,int row,int col)
{
    if(row<N && row>=0 && col<N && col>=0 && board[row][col]==-1) return 1;
    else return 0; 
}
int KnightTour(int ** board,int row,int col,int move,int moves)
{
    display(board);
    printf("\n");
    printf(" %d %d ",move,moves);
    int i;
    if(move==moves+1)
    {
        space=1;
        display(board);
        return space;
    }
    for(i=0;i<8;i++)
    {
        int nextr=row+x[i];
        int nextc=col+y[i];
        if(isSafe(board,nextr,nextc) && space==0)
        {
            board[nextr][nextc]=move;
            if(KnightTour(board,nextr,nextc,move+1,moves) && space==0)
                return space;
            else 
            {
                board[nextr][nextc]=-1;
            }
        }
    }
    return space;
}
int main()
{
    int f,r,moves=0;
    scanf("%d",&N);
    int ** board;
    board=(int**)malloc(sizeof(int*)*N);
    for(int ind=0;ind<N;ind++)
    {
        board[ind]=(int*)calloc(N,sizeof(int));
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&f,&r);
        for(int ind=f;ind<f+r;(board[i][ind++]=-1));
        if(f<N)
        moves+=r;
    }
    display(board);
    printf("%d",moves);
    board[0][0]=1;
    printf("%s",((KnightTour(board,0,0,2,moves))?"possible":"Not Possible"));
    return 0;
}
1 0  3  0 0
4 10 7  0 0
6 2  5  9 0
0 8  0  0 0
0 0  0  0 0
1  8 3  6  0  0 
0  5 12 9  14 0 
11 2 7  4  0  0 
0  0 10 13 0  0 
0  0 0  0  0  0 
0  0 0  0  0  0 
1	12	3	16	9	0	0
0	17	8	11	0	0	0
13	2	15	4	19	10	0
0	7	18	0	0	0	0
0	14	5	20	0	0	0
6	0	0	0	0	0	0
0	0	0	0	0	0	0
