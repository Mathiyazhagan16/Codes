/*
ABC + DEF = GHIJ
437 + 589 = 1026

Generate three digit numbers 100 to 999 - ABC
     Generate three digit numbers 100 to 999 - DEF
          GHIJ = ABC + DEF
          VERIFY IF THEY ARE MADE OF UNIQUE DIGITS
abc         def
first       second
p1             p2
p1 * (10^ nod in p2 ) + p2
123         456

123 * 1000 + 456
123456
123456 * 10000 + 7890

1234567890







23      890         1048

23 * 1000
23000
  890
23890 * 10000
238900000
     1048
238901048

2389801048
















*/

#include<stdio.h>
int main()
{
    int first;
    int second;
    int third;
    long long int combined;
    long long int copy;
    int digit;
    int srch_digit;
    /*
    first,second AND third should combine and it should be made of 0 to 9
    */
    // first to start from 100 to 999
    for( first = 100; first <= 999; first += 1)
    {
        for( second = 100; second <= 999; second +=1)
        {
            third = first + second;
            // choose, is it satisfying our criteria
            if ( third > 1000)
            {
                combined = ( ( (first * 1000LL ) + second) * 10000 ) + third;
            // printf("%d %d %d %lld\n", first, second, third,combined);
                //getchar();
                for( srch_digit = 0; srch_digit < 10; srch_digit +=1)
                {
                    copy = combined;
                    while ( copy != 0)
                    {
                        digit = copy % 10;
                        if( digit == srch_digit)
                            break;
                            copy/=10;
                    }
                    if (copy == 0) break;
                }
                if ( srch_digit == 10)
                {
                    if ( first < second)
                    printf("%d + %d = %d\n", first, second, third);
                }
            }
        }
    }
}




















