// Breaking an Integer to get Maximum Product

// Given an number n, the task is to be broken in such a way that multiplication of its parts is maximized.

// Input : n = 10
// Output : 36
// exp:
// 10 = 4 + 3 + 3 and 4 * 3 * 3 = 36
// is maximum possible product.

// Input : n = 8
// Output : 18
// 8 = 2 + 3 + 3 and 2 * 3 * 3 = 18
// is maximum possible product.



// #include<stdio.h>
// #include<math.h>
// int main()
// {
//     int num;
//     int res;
//     scanf("%d",&num);
//     if(num%3 == 0)
//     {
//         res = pow(3,(num/3));
//     }
//     else if(num%3 == 1)
//     {
//         res = pow(3,(num/3-1)) * 4;
//     }
//     else 
//     {
//         res = pow(3,(num/3)) * 2;
//     }
//     printf("%d",res);
//     return 0;
// }


#include<stdio.h>
int main()
{
    int num;
    int res;
    scanf("%d",&num);
    switch(num%3)
    {
        case 0:
            res = pow(3,num/3);
            break;
        case 1:
            res = pow(3,(num/3-1)) * 4;
            break;
        case 2:
            res = pow(3,(num/3)) * 2;
            break;
    }
    printf("%d",res);
    return 0;
}     