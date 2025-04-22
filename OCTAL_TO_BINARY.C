#include<stdio.h>
#include<stdlib.h>
int main()
{
    int deci;
    int digit;
    int oct_in_bin;
    long long int binForm;
    long long int power;
    deci = 12345;
    power = 1;
    binForm = 0;
    int safe;
    safe = deci;
    while ( deci != 0 )
    {
       digit = deci % 10;
       if ( digit == 0)
              oct_in_bin = 0;
       else if ( digit == 1)
              oct_in_bin = 1;
       else if ( digit == 2)
              oct_in_bin = 10;
       else if ( digit == 3)
              oct_in_bin = 11;
       else if ( digit == 4)
              oct_in_bin = 100;
       else if ( digit == 5)
              oct_in_bin = 101;
       else if ( digit == 6)
              oct_in_bin = 110;
       else if ( digit == 7)
              oct_in_bin = 111;
       binForm = oct_in_bin * power + binForm;
       power *= 1000;
       deci /=10;
     }
     deci = safe;
     printf("(%d)8 = (%lld)2", deci, binForm);
    return EXIT_SUCCESS;
}

