/*
convert binary to OCtal

000     0
001     1
010     2
011     3
100     4
101     5
110     6
111     7

        10 101 011 011 011
                        3
                    3
                3

           5
        2








                10101011011011 % 1000   011 3
                                                1 * 3 + 0
                                                3

                10101011011011 / 1000
                   10101011011 % 1000  011  3   3 * 10 + 3
                                                33

                   10101011011 / 1000
                      10101011 % 1000   011 3
                                                3 * 100 + 33
                                                333
                      10101011 / 1000
                         10101 % 1000  101  5
                                                5 * 1000 + 333
                                                5333
                         10101 / 1000
                            10 % 1000  10   2
                                                2 * 10000 + 5333
                                                25333


               digits = binnum % 1000;

               octNum = (REP) * power + octnum;

               power *= 1000;
               binnum /= 1000

   */
   #include<stdio.h>
   #include<stdlib.h>

   int main()
   {
       long long int binNum;
       long long int copy;
       long long int power;
       int digits;
       int octalRep;

       binNum = 10110111011011;
       power = 1;
       octalRep = 0;
       copy = binNum;
       while ( copy != 0 )
       {
            digits = copy % 1000;
            switch ( digits )
            {
                case 0 : octalRep = 0 * power + octalRep; break;
                case 1 : octalRep = 1 * power + octalRep; break;
                case 10 : octalRep = 2 * power + octalRep; break;
                case 11 : octalRep = 3 * power + octalRep; break;
                case 100 : octalRep = 4 * power + octalRep; break;
                case 101 : octalRep = 5 * power + octalRep; break;
                case 110 : octalRep = 6 * power + octalRep; break;
                case 111 : octalRep = 7 * power + octalRep; break;
            }
            power *= 10;
            copy /= 1000;
       }
       printf("(%lld)2 = (%d)8", binNum, octalRep);
       return EXIT_SUCCESS;
   }


















