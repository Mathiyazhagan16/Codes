#include<stdio.h>
#include<stdlib.h>
#define N 8
void display(int **sudoku)
{
    //printf("Solution no : %d\n",cnt++);
    for(int i=0;i<N;printf("\n"),i++)
        for(int j=0;j<N;j++)
            printf("%d ",sudoku[i][j]);
    printf("\n");
}
int issafe(int **sudoku,int row,int col,int digit)
{
    for(int i=0;i<N;i++)
        if(sudoku[row][i]==digit)
            return 0;
    for(int i=0;i<N;i++)
        if(sudoku[i][col]==digit)
            return 0;
    int x=row/4*4,y=col/4*4,count=0;
    for(int i=x;i<x+4;i++)
        for(int j=y;j<y+4;j++)
        {
            if(sudoku[i][j]==digit) count++;
            if(count>2) return 0;
        }
}
int solve(int **sudoku,int row,int col)
{
    static int solution=0;
    if(row==N-1 && col==N)
    {
        solution=1;
        display(sudoku);
        return solution;
    }
    else
    {
        if(col==N)
        {
            col=0;
            row++;
        }
        if(sudoku[row][col]==0 && solution==0)
        {
            for(int i=1;i<=N;i++)
            {
                if(issafe(sudoku,row,col,i) && solution==0)
                {
                    sudoku[row][col]=i;
                    solve(sudoku,row,col+1);
                    sudoku[row][col]=0;
                }
            }
        }
        else
        {
            solve(sudoku,row,col+1);
        }
    }
    return solution;
}
int main()
{
    int **sudoku;
    sudoku=(int**)calloc(N,sizeof(int*));
    for(int i=0;i<N;i++)
        sudoku[i]=(int*)calloc(N,sizeof(int));
    int row,col;
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            scanf("%d",&sudoku[row][col]);
        }
    }
    if(solve(sudoku,0,0)) /*display(sudoku)*/;
    else printf("No");
    //display(sudoku);
}

/*

1 2 3 4 5 6 7 0
5 6 2 1 3 4 0 7
6 5 0 7 2 1 3 4
3 4 7 8 6 5 2 1
2 1 5 6 8 7 4 3
4 3 6 5 7 8 1 2
0 7 1 2 4 3 5 6
7 0 4 3 1 2 6 5


1 2 3 4 5 6 7 8 
5 6 2 1 3 4 8 7 
6 5 8 7 2 1 3 4 
3 4 7 8 6 5 2 1 
2 1 5 6 8 7 4 3 
4 3 6 5 7 8 1 2 
8 7 1 2 4 3 5 6 
7 8 4 3 1 2 6 5


1 2 3 4 5 6 7 8
5 6 2 1 3 4 8 7
6 5 8 7 2 1 3 4
3 4 7 8 6 5 2 1
2 1 5 6 8 7 4 3
4 3 6 5 7 8 1 2
8 7 1 2 4 3 5 6
7 8 4 3 1 2 6 5

*/