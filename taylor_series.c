#include<stdio.h>
double e_opti(int x,int n)
{
    static int p=1,f=1;
    double r;
    if(n==0)
        return 1;
    else 
    {
        r=e_opti(x,n-1);
        p=p*x;
        f=f*n;
        return r + (double)p/f;
    }
}
int main()
{
    int num;
    scanf("%d",&num);
    printf("%lf",e_opti(2,num));
}




/*

e^x = 1 + x^1/1! + x^2/2! + x^3/3! + .... + x^n/n!

e(2,4) = 1 + 2^1/1! + 2^2/2! + 2^3/3! + 2^4/4!
e(2,4) = 1 + 2 + 2 + 1.333333 + 0.666667


e(2,4) = e(2,4-1) + 2^4/4!
e(2,3) = e(2,3-1) + 2^3/3!
e(2,2) = e(2,2-1) + 2^2/2!
e(2,1) = e(2,1-1) + 2^1/1!
e(2,0) = 1




    p(2,4) = 2*p(2,4-1)
    p(2,3) = 2*p(2,3-1)
    p(2,2) = 2*p(2,2-1) 
    p(2,1) = 2*p(2,1-1)
    p(2,0) = 1

f(4) = 4*f(4-1)
f(3) = 3*f(3-1)
f(2) = 2*f(2-1)
f(1) = 1




*/