
//Adam number

// 12-----21   [ take input and reverse the input        ]
//  |     |  
//  |     441  [ find square of a reversed value         ]
//  |     |
// 144 == 144  [ if square of a number equal to reversed ]
//             [ value of a square of a reversed input   ] [Adam number]



#include<stdio.h>
int main()
{
    int num;
    int square;
    int rev;
    int sqr_rev;
    int rev_sqr_rev;
    scanf("%d",&num);
    rev = 0;
    square = num * num;
    while(num != 0)
    {
        rev = rev * 10 + (num%10);
        num/=10;
    }
    sqr_rev = rev * rev;
    rev_sqr_rev = 0;
    while(sqr_rev != 0)
    {
        rev_sqr_rev = rev_sqr_rev * 10 + (sqr_rev%10);
        sqr_rev/=10;
    }
    printf("%s ",(square == rev_sqr_rev)?"Adam number":"Not a Adam number");
    return 0;
}  