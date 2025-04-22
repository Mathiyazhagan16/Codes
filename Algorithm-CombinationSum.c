#include<stdio.h>
#include<string.h>
void display(int *val,int *res,int N)
{
    for(int ind=0;ind<N;ind++)
    {
        if(res[ind]!=-1)
            printf("%d ",val[ind]);
    }
    printf("\n");
}
int issafe(int balance,int actual,int K)
{
    if(balance!=0 && actual<=K) return 1;
    return 0;
}
void solve(int N,int *val,int *res,int balance,int actual,int ind,int K)
{
    if(K==actual)
    {
        display(val,res,N);
    }
    else 
    {
        if(issafe(balance,actual,K))
        {
            res[ind]=1;
            solve(N,val,res,balance-val[ind],actual+val[ind],ind+1,K);
            res[ind]=-1;
            solve(N,val,res,balance-val[ind],actual,ind+1,K);
        }
    }
}
int main()
{
    int N,K,balance=0,actual=0;
    scanf("%d",&N);
    int val[N],res[N];
    for(int ind=0;ind<N;scanf("%d",&val[ind++]),(balance+=(val[ind-1])));
    scanf("%d",&K);
    memset(res,-1,N*sizeof(int));
    solve(N,val,res,balance,actual,0,K);
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