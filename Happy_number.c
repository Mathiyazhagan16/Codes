// //happy number



//      82      take input from the user
//     /  \ 
//    8    2    seperate the digits
//    |    |
//   64  + 4    square the digits
//     \  / 
//      68      if sum if squares is > 9(more than 1 digit) do the process with sum again
//     /  \ 
//    6    8
//    |    | 
//   36  + 64 
//     \  /  
//     100
//    / | \ 
//   1  0  0 
//   |  |  |
//   1 +0 +0
//    \ | / 
//      1       if sum == 1 Happy number (or) if it is between (2 - 9) not a happy number 



#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    if(num < 10)
    {
        if(num == 1)
        {
            printf("Happy number");
        }
        else 
        {
            printf("Not a Happy number");
        }
    }
    else 
    {
        while(1)
        {
            int sum = 0;
            while(num != 0)
            {
                sum = sum + ((num%10) * (num%10));
                num/=10;
            }
            if(sum == 1) 
            {
                printf("happy number");
                return 0;
            }
            else if(sum >= 2 && sum <= 9)
            {
                printf("Not a Happy number");
                return 0;
            }
            else 
            {
                num = sum;
            }
        }
    }
    return 0;
} 