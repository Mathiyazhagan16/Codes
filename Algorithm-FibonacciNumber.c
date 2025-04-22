#include<stdio.h>
long long int Fibonacci(int N)
{
    if(N<=1) return N;
    return Fibonacci(N-1) + Fibonacci(N-2);
}
int main()
{
    int N;
    scanf("%d",&N);
    long long int res=Fibonacci(N);
    printf("%d",res);
}