#include<stdio.h>
#include<limits.h>
int main()
{
   printf("%-25s","signed char ");
   printf("- Range %d to %d\n", CHAR_MIN, CHAR_MAX);
   printf("%-25s","unsigned char ");
   printf("- Range %d to %d\n", 0, UCHAR_MAX);
   printf("%-25s","signed short int ");
   printf("- Range %d to %d\n", SHRT_MIN, SHRT_MAX);
   printf("%-25s","unsigned short int ");
   printf("- Range %d to %d\n", 0, USHRT_MAX);
   printf("%-25s","signed long int ");
   printf("- Range %d to %d\n", INT_MIN, INT_MAX);
   printf("%-25s","unsigned long int ");
   printf("- Range %d to %u\n", 0, UINT_MAX);
   printf("%-25s","signed long long int ");
   printf("- Range %lld to %lld\n", LLONG_MIN, LLONG_MAX);
   printf("%-25s","unsigned long int ");
   printf("- Range %lld to %llu\n", 0LL, ULLONG_MAX);
  return 0;
}
