#include<stdio.h>
#include<math.h>
int fib(int num)//T(n) = T(n-1) + T(n-2)
{
    if(num<=1)//1 unit
        return num;
    return fib(num-1) + fib(num-2);//T(n-1) + T(n-2)
}
int fib_opti(int n)
{
    double term_1=(1+sqrt(5))/2;
    double term_2=(1-sqrt(5))/2;
    term_1=pow(term_1,n);
    term_2=pow(term_2,n);
    double mul=1/sqrt(5);
    return mul*(term_1-term_2);
}
int main()
{
    int num;
    scanf("%d",&num);
    printf("%d %d",fib(num),fib_opti(num));
}



/*
T(n) = T(n-1) + T(n-2)

T(n) - T(n-1) - T(n-2) = 0
ax^2 + bx + c = 0

a=1,b=-1,c=-1

(1 + sqrt(5))/2

a * ((1 + sqrt(5))/2)^n + b * ((1 - sqrt(5))/2)^n
n=0, n=1
a + b = 0 -> 1
a * ((1 + sqrt(5))/2) + b * ((1 - sqrt(5))/2)  -> 2
a * ((1 + sqrt(5))/2) + (-a) * ((1 - sqrt(5))/2)

a/2 + asqrt(5)/2 + -a/2 + asqrt(5)/2
asqrt(5)/2 + asqrt(5)/2 = 1

asqrt(5)=1
1/sqrt(5)=a


1/sqrt(5) * [((1+sqrt(5))/2)^n - ((1+sqrt(5))/2)^n]

O (1.618^n)





*/