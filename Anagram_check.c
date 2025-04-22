#include<stdio.h>
#include<math.h>
int main()
{
    int input1;
    int input2;
    int place ;
    place = 1 ;
    int ref_ind;
    scanf("%d",&input1);
    scanf("%d",&input2);
    int digits_count1 = log10(input1)+1;
    int digits_count2 = log10(input2)+1;
    int digit_ref[10] = {0};
    if(digits_count1 == digits_count2)
    {
        while(input1 != 0)
        {
            digit_ref[input1%10]++;
            digit_ref[input2%10]--;
            place = place * 10;
            input1 = input1 / 10;
            input2 = input2 / 10;
        }
    }
    for(ref_ind = 0 ; ref_ind < 10 ; ref_ind++)
    {
        if(digit_ref[ref_ind] != 0)
        {
            break;
        }
    }
    printf("%s",ref_ind==10 ? "Anagram" : "Not a Anagram");
}
