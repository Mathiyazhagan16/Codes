#include<stdio.h>
int main()
{
    int num[10]={1,2,3,4,5,6,7,8,9,10,11};
    int ind;
    for(ind=9;ind>=0;ind--)
        printf("%d ",num[ind]);
    return 0;
}