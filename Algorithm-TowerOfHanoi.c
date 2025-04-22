#include<stdio.h>
#include<math.h>
int row,cnt=1;
void display(int size,int arr[size][2])
{
    printf("Test case %d Solution\n",cnt++);
    for(int ind=0;ind<size;ind++)
    {
        printf("{%d , %d}\n",arr[ind][0],arr[ind][1]);
    }
}
void TowerOfHanoi(int size,int arr[size][2],int N,int from,int aux,int to)
{
    if(N)
    {
        TowerOfHanoi(size,arr,N-1,from,to,aux);
        arr[row][0]=from;
        arr[row][1]=to;
        row++;
        TowerOfHanoi(size,arr,N-1,aux,from,to);
    }
}
int main()
{
    int T,N;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d",&N);
        int size=pow(2,N)-1;
        int arr[size][2];
        row=0;
        TowerOfHanoi(size,arr,N,1,2,3);
        display(size,arr);
    }
}


/*

4
1 2 3 4
Test case 1 Solution
{1 , 3}
Test case 2 Solution
{1 , 2}
{1 , 3}
{2 , 3}
Test case 3 Solution
{1 , 3}
{1 , 2}
{3 , 2}
{1 , 3}
{2 , 1}
{2 , 3}
{1 , 3}
Test case 4 Solution
{1 , 2}
{1 , 3}
{2 , 3}
{1 , 2}
{3 , 1}
{3 , 2}
{1 , 2}
{1 , 3}
{2 , 3}
{2 , 1}
{3 , 1}
{2 , 3}
{1 , 2}
{1 , 3}
{2 , 3}

*/