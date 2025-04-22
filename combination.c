#include<stdio.h>
int fact(int num)
{
    if(num<=1)
        return 1;
    return num*fact(num-1);
}
int comb(int n,int r)
{
    int num1,num2,num3;
    num1=fact(n);
    num2=fact(r);
    num3=fact(n-r);
    return num1 / (num2*num3);
}
int comb_2(int n,int r)
{
    if(r==0 ||  n==r)
        return 1;
    return comb_2(n-1,r-1) + comb_2(n-1,r);
}
int main()
{
    short int n,r;
    scanf("%hd %hd",&n,&r);
    printf("%d %d",comb(n,r),comb_2(n,r));
}



/*


a b c d e f
a b c 
a b d 
a b e 
a b f 


nCr = n! / (r! * (n-r)!)


*/