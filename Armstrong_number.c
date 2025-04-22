// //Armstrong number
//       153-------  take input from the user
//      / | \     |
//     /  |  \    |
//    1   5   3   |  seperate the digits
//    |   |   |   |
//    1+ 125+ 27  |  take power based on number of digits and do sum the value
//     \  |  /    |
//      \ | /     |
//       153-------  if sum is equal to input => Armstrong number


#include<stdio.h>
int main()
{
    int num;
    int sum = 0;
    int digits;
    int pv = 1;
    scanf("%d%n",&num,&digits);
    while(num / pv != 0)
    {
        int dig = (num/pv) % 10;
        int power = digits;
        int exp = 1;
        while(power--)
        {
            exp = exp * dig;
        }
        sum = sum + exp;
        pv = pv * 10;
    }
    printf("%s",(num == sum)?"Armstrong number":"Not a armstrong number");
    return 0;
}  
