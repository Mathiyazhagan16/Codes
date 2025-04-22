// Unique Number
// Write a program to find the count of numbers which consists of unique digits

// Input
// Input consists of 2 integer lower and upper value of an range

// Output
// Output consists of single line, print the count of numbers made of unique digits in given range. Use print "No Unique Number"

// Sample Input
// 10
// 15
// 10 11 12 13 14 15
// Output
// 5






#include<stdio.h>
int main()
{
    int start;
    int end;
    int digit;
    int count;
    int copy_num;
    scanf("%d",&start); // starting number for the range
    scanf("%d",&end);   // ending number for the range
    count = 0;
    while(start <= end) // loop to access the numbers from the range
    {
        short int ref = 0;//memory allocation to take referance
        copy_num = start;
        while(copy_num != 0) // loop to access all the digits of the number
        {
            digit = copy_num % 10; // digit seperation
            if((ref & (1<<digit)) == 0) // condition to check the referance
            {
                ref = ref | (1<<digit); // expression to copy the reference
            }
            else 
            {
                break; // if duplicate digits are there terminate the loop
            }
            copy_num = copy_num / 10; //digit removal
        }
        if(copy_num == 0) // if pending digits is not there loop got terminated because of no repeating digits
        {
            count++;
        }
        start = start + 1;
    }
    printf("%d",count);
}
