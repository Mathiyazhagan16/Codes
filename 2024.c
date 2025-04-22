#include<stdio.h>
#include<string.h>
#define N 4
int arr[N][N];
void shiftl(int arr[N][N])
{
	for(int row;row<N-1;row++)
		for(int col;col<N-1;col++)
			if(arr[row][col]==arr[row][col+1])
				arr[row][col]*=2,arr[row][col+1]=0;
	int i=0;
	while(arr[0][i]!=0) i++;
	arr[0][i]=2;
}
void shiftr(int arr[N][N])
{
	for(int row;row<N-1;row++)
		for(int col;col<N-1;col++)
			if(arr[row][col]==arr[row][col+1])
				arr[row][col]=0,arr[row][col+1]*=2;
	int i=0;
	while(arr[0][i]==0) i++;
	arr[0][i-1]=2;
}
void shiftt(int arr[N][N])
{
	for(int row;row<N-1;row++)
		for(int col;col<N-1;col++)
			if(arr[row][col]==arr[row+1][col])
				arr[row][col]*=2,arr[row+1][col]=0;
	int i=0;
	while(arr[0][i]==0) i++;
	arr[0][i-1]=2;
}
void shiftb(int arr[N][N])
{
	for(int row;row<N-1;row++)
		for(int col;col<N-1;col++)
			if(arr[row][col]==arr[row+1][col])
				arr[row][col]=0,arr[row+1][col]=0;
	int i=0;
	while(arr[0][i]==0) i++;
	arr[0][i-1]=2;
}
int main()
{
	int row,col,r,c;
	char dir;
	memset(arr,0,N*sizeof(int));
	arr[0][N-1]=2;
	for(row=0;row<N;row++)
	{
		printf(" ______ ______ ______ ______ \n");
		printf("|");
		for(col=0;col<N;col++)
		{
			printf(" %4d |",arr[row][col]);
		}
		printf("\n");
		printf("|______|______|______|______|\n");
	}
	while(1)
	{
		scanf("\n %c",&dir);
		switch(dir)
		{
			case 'L': case 'l':
				shiftl(arr);
				break;
			case 'R': case 'r':
				shiftr(arr);
				break;
			case 'T': case 't':
				shiftt(arr);
				break;
			case 'B': case 'b':
				shiftb(arr);
				break;
		}
		for(row=0;row<N;row++)
		{
			printf(" ______ ______ ______ ______ \n");
			printf("|");
			for(col=0;col<N;col++)
			{
				printf(" %4d |",arr[row][col]);
			}
			printf("\n");
			printf("|______|______|______|______|\n");
		}
		printf("\n");
		printf("\n");
	}
}