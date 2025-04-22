#include<stdio.h>
int main()
{
    int num;
    int *num1;
    int **num2;
    int ***num3;
    int ****num4;
    num=10;
    num1 = &num;
    num2 = &num1;
    num3 = &num2;
    num4 = &num3;
    num=20;
    *num1 = 30;
    **num2 = 40;
    ***num3 = 50;
    ****num4 = 60;
    printf("%p %p %p %p %p %d ",&num4,num4,*num4,**num4,***num4,****num4);
    printf("1");
    return 0;
}