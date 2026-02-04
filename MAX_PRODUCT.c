#include<stdio.h>
#include<stdlib.h>
int max = INT_MIN;
int Solve(int N,int *arr,int ind)
{
    if(N == 0)
    {
        int pro=1;
        for(int itr=0;itr<ind;printf("%d ",arr[itr]),itr++);
        printf("\n");
        for(int itr=0;itr<ind;(pro*=arr[itr]),itr++);
        if(max<pro) 
        {
            max = pro;
        }
    }
    else
    {
        for(int val = 1; val<=N ; val++)
        {
            if((N-val) >= 0)
            {
                arr[ind]=val;
                Solve(N-val,arr,ind+1);
                arr[ind]=0;
            }
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int *arr = (int*)calloc(N,sizeof(N));
    Solve(N,arr,0);
    printf("%d",max);
    return 0;

}
