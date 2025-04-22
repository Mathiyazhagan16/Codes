#include<stdio.h>
#include<malloc.h>
short int size,cnt=1;
void display(char ** board)
{
    printf("Solution No : %d\n",cnt++);
    for(int row=0;row<size;printf("\n"),row++)
        for(int col=0;col<size;col++)
            printf("%c ",board[row][col]);
    printf("\n");
}
int isSafe(char ** board,int row,int col)
{
    int i,j;
    for(i=row;i>=0;i--)
        if(board[i][col]=='Q') return 0;
    for(i=row,j=col;j>=0 && i>=0;j--,i--)
        if(board[i][j]=='Q') return 0;
    for(i=row,j=col;j<size && i>=0;j++,i--)
        if(board[i][j]=='Q') return 0;
    return 1;
}
void NQueen(char ** board,int row)
{
    if(row==size)
    {
        display(board);
    }
    else
    {
        for(int col=0;col<size;col++)
        {z
            if(isSafe(board,row,col))
            {
                board[row][col]='Q';
                NQueen(board,row+1);
                board[row][col]='-';
            }
        }
    }
}
int main()
{
    scanf("%hi",&size);
    char ** board;
    board=(char**)malloc(sizeof(char*)*size);
    for(int ind=0;ind<size;ind++)
        board[ind]=(char*)malloc(sizeof(char)*size);
    for(int row=0;row<size;row++)
        for(int col=0;col<size;col++)
            board[row][col]='-';
    NQueen(board,0);
}

