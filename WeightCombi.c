#include<stdio.h>
int main()
{
    int K;
    int count = 0;
    int weights[]={1,2,5,10,20,50,100,500,1000};
    int size = sizeof(weights)/sizeof(weights[0]);
    scanf("%d",&K);
    for(int ind = size-1 ; ind >= 0 ; ind--)
    {
        if(weights[ind] <= K)
        {
            K-=weights[ind++];
            count++;
        }
    }
    printf("%d",count);
}