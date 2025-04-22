#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num,pv=1,product=1,sum=0;
    scanf("%d",&num);
    while(num/pv)
    {
        if((((num/pv)%10)&1)==0)
            product*=((num/pv)%10);
        else 
            sum+=((num/pv)%10);
        pv*=10;
    }
    if(product==1) product=0;
    printf("%d",abs(product-sum));
}































/*

#include<stdio.h>
int main()
{
    int num,fac,res=0,base=1;
    scanf("%d",&num);
    if(num<=9)
    {
        printf("%d",num+10);
    }
    else
    {
        for(fac=9;fac>1;fac--)
        {
            while(num%fac==0)
            {
                res=res+fac*base;
                base*=10;
                num/=fac;
            }
        }
        (num>=10)?printf("Invalid"):printf("%d",res);
    }
}


*/