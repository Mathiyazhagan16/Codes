#include<stdio.h>
#include<stdlib.h>
int main()
{
    char str [] = "NivethA KrishnaVeni DivYADharshini";
    int ind;
    char ch;
    printf("%s\n", str);
    for( ind = 0; str [ ind ] ; ind+=1)
    {
        ch = str [ ind ];
        if ( (ch >= 65 && ch <= 90 ) || (ch >=97 && ch <= 122))
            str [ ind ] ^= 32;
    }
    printf("%s\n", str);


    return EXIT_SUCCESS;
}
