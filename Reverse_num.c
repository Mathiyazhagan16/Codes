#include<stdio.h>
int main()
{
    int num;
    int res = 0;
    scanf("%d",&num);
    while(num!=0)
    {
        int dig = num%10;
        res = res * 10 + dig;
        num/=10;
    }
    printf("%d",res);
}


/*
N = 12345 

res = dig + res * 10

5     = 5 + 0    * 10
54    = 4 + 5    * 10
543   = 3 + 54   * 10
5432  = 2 + 543  * 10
54321 = 1 + 5432 * 10


sum = val + sum 

01 = 1 + 0
03 = 2 + 1
06 = 3 + 3
10 = 4 + 6
15 = 5 + 10








*/
