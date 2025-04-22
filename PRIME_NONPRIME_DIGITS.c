/*
     1234567890
     2357146890
       c1          c2
     2357       146890
    res = c1 * 10^nod in c2 + c2

     1253876
     2537186


     4761825
     7254618



     1253876
     MSD
     ? power     1000000
     Keep increasing the power until the quotient is single digit
     power = 1;
     while ( num / power > 9)
     {
        power *=10;
     }

     digit = num / power            1   2   5   3   8   7   6
     num = num % power              253876  53876   3876    876 76  6
     power /= 10;                   100000  10000   1000    100 10  1
       2537                186
     prime              non_prime       non_prime_power
       0                     0              1
       2                     1              10
       25                    18             100
       253                   186            1000
       2537









*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    long long int num;
    int digit;
    long long int copy;
    long long int power;
    long long int prime_set;
    long long int non_prime_set;
    long long int non_prime_power;
    long long int res;
    num = 1234567890;
    power = 1;
    while ( num / power > 9)
    {
        power *= 10;
    }
    non_prime_power= 1;
    non_prime_set = 0;
    prime_set = 0;
    copy = num;
    while ( power != 0) // MSD access dont rely in the value
    {
        digit = copy / power;
        if ( digit == 2 || digit == 3 || digit == 5 || digit == 7)
        {
            prime_set = prime_set * 10 + digit;
        }
        else
        {
            non_prime_set = non_prime_set * 10 + digit;
            non_prime_power *= 10;
        }
        copy %= power;
        power /=10;
    }
    res = prime_set * non_prime_power + non_prime_set;
    printf("num = %lld res = %lld", num, res);
    return EXIT_SUCCESS;
}

















