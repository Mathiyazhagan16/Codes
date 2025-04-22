/*

Accept a number
Check if it is a
PANDIGITAL Number

1234567890

What ?
Check whether the number has all the digits
ALL the digits ?
0 1 2 3 4 5 6 7 8 9


Check if the number has 0
Check if the number has 1
Check if the number has 2
Check if the number has 3
Check if the number has 4
Check if the number has 5
Check if the number has 6
Check if the number has 7
Check if the number has 8
Check if the number has 9

Check if the number has 6
4589012763
Destruct the number into digits ? LSD or MSD
LSD
power 10


abc + def = ghij
437 + 589 = 1026
3816547290
3
38
381
3816
38165
381654
3816547
38165472
381654729
3816547290



*/
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {

//     long long int num;
//     long long int copy;
//     int digit;
//     int srch_digit;
//     num = 6709413258;
//     int flag;
//     flag = 1;
//     for( srch_digit = 0; srch_digit < 10 && flag == 1; srch_digit+=1)
//     {
//         copy = num;
//         flag = 0;
//         while ( copy != 0 && flag == 0)
//         {
//             digit = copy % 10;
//             if ( digit == srch_digit)
//             {
//                 flag = 1;
//             }
//             copy /= 10;
//         }
//     }
//     printf("%lld is %s  PANDIGITAL Number",num, srch_digit == 10 ? "A": "NOT A");
//     return EXIT_SUCCESS;
// }










#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{

    long long int num;
    long long int base;
    long long int power;
    int digit;
    num = 6709413258;
    short int ref = 0;
    base = 1;
    power = (pow(2,10)-1);
    while(num/base != 0)
    {
        int digit = num / base % 10;
        ref = (ref | (1<<digit));
        base *= 10;
    }
    printf("%lld is %s  PANDIGITAL Number",num, power == ref ? "A": "NOT A");
    return EXIT_SUCCESS;
}








