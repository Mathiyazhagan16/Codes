#include <stdio.h>
#include <limits.h>
int main() 
{
    int N;
    int res;
    int Shop1;
    int Shop2;
    int price1;
    int price2;
    int count1=0;
    int count2=0;
    int min = INT_MAX;
    scanf("%d %d %d %d %d",&N,&Shop1,&price1,&Shop2,&price2);
    if(Shop2 < Shop1)
    {
        int temp = Shop1;
        Shop1 = Shop2;
        Shop2 = temp;
    }
    for(int i=1;i<=N/Shop1;i++)
    {
        count1++;
        if((N - (count1*Shop1))%Shop2 == 0)
        {
            res = count1*price1 + ((N - (count1*Shop1))/Shop2)*price2;
        }
        if(min > res) min = res;
    }
    printf("%d",min);
    return 0;
}




/*
Josh went to the market to buy N apples. He found two shops, shop A and B, where apples were being sold in lots. He can buy any number of the complete lot(s) but not loose apples. He is confused with the price and wants you to figure out the minimum cost to buy exactly N apples.
Write an algorithm for Josh to calculate the minimum cost to buy exactly N apples.
Example
Input
19
3 10
4 15 
Output
65
Explanation
Josh can buy five lots from the first shop and one lot from the second shop (5*10-15)

*/