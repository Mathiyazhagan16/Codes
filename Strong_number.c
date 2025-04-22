
// //Strong number
//       145-------  take input from the user
//      / | \     |
//     /  |  \    |
//    1   4   5   |  seperate the digits
//    |   |   |   |
//    1+  24+ 120 |  take factorial of digits and do sum the value
//     \  |  /    |
//      \ | /     |
//       145-------  if sum is equal to input => Armstrong number


#include<stdio.h>
int main()
{
    int num;
    int sum = 0;
    int pv = 1;
    scanf("%d",&num);
    while(num / pv != 0)
    {
        int dig = (num/pv) % 10;
        int fact = 1;
        while(dig)
        {
            fact = fact * dig;
            dig--;
        }
        sum = sum + fact;
        pv = pv * 10;
    }
    printf("%s",(num == sum)?"Strong number":"Not a Strong number");
    return 0;
}  
