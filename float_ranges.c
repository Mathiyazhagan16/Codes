#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() 
{
    printf("Storage size for float : %d \n", sizeof(float));
    printf("FLT_MAX     :   %e\n", (float) FLT_MAX);
    printf("FLT_MIN     :   %e\n", (float) FLT_MIN);
    printf("-FLT_MAX    :   %e\n", (float) -FLT_MAX);
    printf("-FLT_MIN    :   %e\n", (float) -FLT_MIN);
    printf("DBL_MAX     :   %e\n", (double) DBL_MAX);
    printf("DBL_MIN     :   %e\n", (double) DBL_MIN);
    printf("-DBL_MAX     :  %e\n", (double) -DBL_MAX);
    printf("Precision value: %d\n", FLT_DIG );

    return 0;
}
