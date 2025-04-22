#include<stdio.h>
void display(int ans[],int N,int set[])
{
    for(int ind=0;ind<N;ind++)
        if(ans[ind]!=-1)
            printf("%d ",set[ind]);
    printf("\n");
}
int isSafe(int actual,int balance,int K)
{
    if(actual<=K && balance!=0) return 1;
    return 0;
}
void Solve(int N,int set[],int balance,int actual,int ans[],int K,int ind)
{
    if(actual==K)
        display(ans,N,set);
    else
    {
        if(isSafe(actual,balance,K))
        {
            ans[ind]=1;
            Solve(N,set,balance-set[ind],actual+set[ind],ans,K,ind+1);
            ans[ind]=-1;
            Solve(N,set,balance-set[ind],actual,ans,K,ind+1);
        }
    }
}
int main()
{
    int N,ind,K,balance=0,actual=0;
    scanf("%d",&N);
    int set[N],ans[N];
    for(ind=0;ind<N;scanf("%d",&set[ind++]),(balance+=set[ind-1]));
    scanf("%d",&K);
    for(ind=0;ind<N;ans[ind++]=-1);
    Solve(N,set,balance,actual,ans,K,0);
}


/*

10
1 2 3 4 5 6 7 8 9 10
11



1 2 3 5 
1 2 8 
1 3 7 
1 4 6 
1 10 
2 3 6 
2 4 5 
2 9 
3 8 
4 7 
5 6 

*/