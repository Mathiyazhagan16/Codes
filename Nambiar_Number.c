#include<stdio.h>
int main()
{
    long num;
    scanf("%lld",&num);
    int pv = 1000000000;
    int res = 0;
    int ref = (num%10 != 0)?1:0;
    while(num != 0)
    {
        int dig = (int)(num/pv);
        if(dig%2==0)
        {
            res = res + dig;
        }
        else 
        {
            if(res != 0)
            {
                printf("%d",res+dig);
                res = 0;
            }
            else 
            {
                res = res + dig;
            }
        }
        num%=pv;
        pv/=10;
    }
    if(res != 0) printf("%d",res);
    if(ref == 0) printf("0");
    return 0;
}
