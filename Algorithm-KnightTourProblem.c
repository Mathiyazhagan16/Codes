#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N,cnt=1;
int x[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
int y[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };
void display(int **board)
{
    printf("Solution no: %d\n",cnt++);
    for(int row=0;row<N;printf("\n"),row++)
    for(int col=0;col<N;printf("%02d ",board[row][col++]));
    printf("\n\n");
}
int issafe(int **board,int row,int col)
{
    if(row>=0 && col>=0 && row<N && col<N && board[row][col]==-1) 
        return 1;
    return 0;
}
int solve(int ** board,int row,int col,int move)
{
    static int solution=0;
    if(move==N*N+1)
    {
        display(board);
        solution=1;
    }
    for(int i=0;i<8;i++)
    {
        int next_row=x[i]+row;
        int next_col=y[i]+col;
        if(issafe(board,next_row,next_col) && solution!=1)
        {
            board[next_row][next_col]=move;
            solve(board,next_row,next_col,move+1);
            board[next_row][next_col]=-1;
        }
    }
    return solution;
}
int main()
{
    scanf("%d",&N);
    int **board=(int **)malloc(N*sizeof(int*));
    for(int ind=0;ind<N;ind++)
    {
        board[ind]=(int *)malloc(N*sizeof(int));
        memset(board[ind],-1,N*sizeof(int));
    }
    board[0][0]=1;
    if(!solve(board,0,0,2)) printf("Not Available");
    return 0;
}

/*
Given an integer N to create N*N board with the Knight placed on the first block of an empty board (Board[0][0]). the Knight can move according to the rules of chess, knight must visit each square exactly once. Print the order of each square in which the knignt have visited.
*/


/*
7

01 38 31 08 19 36 15 
32 29 20 37 16 07 18 
39 02 33 30 09 14 35 
28 25 40 21 34 17 06 
41 22 03 26 45 10 13 
24 27 48 43 12 05 46 
49 42 23 04 47 44 11





5
01 06 15 10 21 
14 09 20 05 16 
19 02 07 22 11 
08 13 24 17 04 
25 18 03 12 23


4
Not Possible


6
01 16 07 26 11 14 
34 25 12 15 06 27 
17 02 33 08 13 10 
32 35 24 21 28 05 
23 18 03 30 09 20
36 31 22 19 04 29

7
01 38 31 08 19 36 15 
32 29 20 37 16 07 18 
39 02 33 30 09 14 35 
28 25 40 21 34 17 06 
41 22 03 26 45 10 13 
24 27 48 43 12 05 46 
49 42 23 04 47 44 11 


3
Not Possible

1
01 

2
Not Possible


8
01 60 39 34 31 18 09 64 
38 35 32 61 10 63 30 17 
59 02 37 40 33 28 19 08 
36 49 42 27 62 11 16 29 
43 58 03 50 41 24 07 20 
48 51 46 55 26 21 12 15
57 44 53 04 23 14 25 06
52 47 56 45 54 05 22 13



	5---  ---4
6       |	     3
|	   	|        |
--- --- K --- --- 
|		|		 |
7    	|        2	
    8---  ---1 


0	5	0	4	0
6	0	0	0	3
0	0	K	0	0
7	0	0	0	2
0	8	0	1	0



*/