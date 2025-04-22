#include<stdio.h>
int main()
{
    char ones[20][10] = {"Zreo","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    char tens[10][8] = {"","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    for(int val = 0 ; val < 1000 ; val++)
    {
        int N = val;
        if(N > 99)
        {
            printf("%s Hundred ",ones[N/100]);
            N %= 100;
            if(N == 0) printf("Only");
            else if(N >= 1 && N <= 19)
                printf("and %s",ones[N]);
            else
            {
                printf("and %s",tens[N/10]);
                if(N%10 != 0) printf(" %s",ones[N%10]);
            }
        }
        else 
        {
            if(N >= 0 && N <= 19)
                printf("and %s",ones[N]);
            else
            {
                printf("and %s",tens[N/10]);
                if(N%10 != 0) printf(" %s",ones[N%10]);
            }
        }
        printf("\n");
    }
    return 0;
}