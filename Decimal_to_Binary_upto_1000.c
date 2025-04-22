#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    int bin=0,temp,i=1;
    temp=num;
    while(temp)
    {
        bin=bin + ((temp&1)*i);
        temp>>=1;
        i*=10;
    }
    printf("%d ",bin);
}

