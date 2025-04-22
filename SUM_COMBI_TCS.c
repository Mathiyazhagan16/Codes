/*
Write a program to find sum of all characters and their adjacent digit combination
from given number.
Consider the below number:
n=321
All combination of characters and adjacent digit from above string is 3,2,1,32,21,321
Addition of all number (3+2+1+32+21+321) we can get 380 as result.
Input Format:
Candidate has to write the code to accept single number  without any additional message.
Only integer characters are allowed.
Output Format:
Written program code should generate output as single integer value which represents Sum.
Additional message in output will cause to failure of test cases.
Constraints:
1 <= n <= 10^6
Examples:
Examples 1:
Input:
321
Output:
380
Examples 2:
Input:
12
Output:
15
Explanation:
In Examples -2: All possible combinations are 1,2,12
Sum = 1+2+12=15
*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num;
    int copy_num;
    int sum_combi;
    int power;
    int digit_s; // 4 6 9 6 74
    num = 123456;
    power = 10;
    sum_combi = 0;
    while ( num  >=  (power/10)) // 10 100 1000 10000 100000
    {
        copy_num = num;
        while ( copy_num > (power/10))
        {
            digit_s = copy_num % power;
            sum_combi += digit_s;
            copy_num /= 10;
        }
        power *=10;
    }
    printf("Sum of all subnumbers are %d\n", sum_combi);

// 6 9 7 4
// 69 97 74
// 697 974
// 6974
    return EXIT_SUCCESS;
}



















