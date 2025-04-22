#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N;
    scanf("%d",&N);
    int* prime = (int*)calloc(N+1 , sizeof(int));
    for(int ind = 0 ; ind < N ; ind++)
    {
        prime[ind] = 0;
    }
    for(int val = 2 ; val*val <= N ; val++)
    {
        if(prime[val] == 1) continue;
        for(int ind = val * val ; ind <= N ; ind+=val)
        {
            prime[ind] = 1;
        }
    }
    int count = 0;
    int sum = 2;
    for(int ind = 3 ; ind <= N ; ind++)
    {
        if(prime[ind] == 1) continue;
        sum += ind;
        if(sum > N) break;
        if(prime[sum] == 0) 
            count++;
    }
    printf("%d",count);
    return 0;
}