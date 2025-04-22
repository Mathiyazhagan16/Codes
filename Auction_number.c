// Auction Number
// Vehicle problem

// -Problem Description
// Codu is fond of vehicle numbers. Codu wants to compute the number of vehicles can be registered in his state. A vehicle normally has a registration number like ST 01 AB 1234. Each registration number has four parts, separated by spaces. The first part has two letters common for all cars in the state. The next two digit number is the number of the district where the car is registered within the state. It is always two digits, and may have a leading zero. After that, the next part consists of two letters (AB) denoting the series and the last part is a 4 digit number (this will always be four digits, even if it has leading zeroes). The entire registration number is unique to each vehicle. You have been given the number of districts in state and a range of letters and a set of digits that can be used for forming a vehicle registration number. You need to find the maximum number of vehicles that can be registered in the state with non-special numbers, subject to the rules

// The state has identified some numbers as special, and will not be issued normally, but will only be available by auction. In these plates, the last part (consisting of four digits) has three or more repetitions of one digit such as 0001, 0000, 0100, 2212 so on. The output should consist of the maximum number of vehicles that can be registered in the state with non-special numbers

// Constraints

// 1<= Number of districts < 100

// A <=Range of alphabets <= Z

// 0 <= Range of digits <= 9
// Width of district columns will be always equal to 2.
// Ex district 1 will be represented as 01.

// Input

// The input has three lines

// The first line contains an integer denoting the number of districts in the state.

// The second line contains two space separated characters denoting the range of letters that can be used for the third part For example, if the input says BF any of the letters BCDE or F may be used in any combination for the third part

// The third line contains space separated integers denoting the range of digits.

// Output

// Print the total number of vehicles that can be registered

// -Time Limit

// 1

// Explanation

// Example 1

// Input

// 01

// A B

// 0 1

// Output

// 24

// Explanation

// Here, only one district is present. Hence, number plate will start from ST D1 AA 0000, ST 01 AA 0001, etc. However, we need to exclude auction-able numbers. After doing so , the overay count of non special vehicle registration numbers remains 24. For example, ST 01 AA 0011, ST 01 ST 0110.. so on.

// Example 2

// Input

// 2

// AC

// 12

// Output

// 108












#include<stdio.h>
int main()
{
    int dist;
    int start_n;
    int end_n;
    char start_c;
    char end_c;
    int num_r;
    int char_r;
    scanf("%d\n%c %c\n%d %d",&dist,&start_c,&end_c,&start_n,&end_n);
    num_r = end_n - start_n + 1;
    char_r = end_c - start_c +1;
    int res = (num_r*num_r*num_r*num_r) - num_r - (num_r*(num_r-1)*4);
    printf("%d",dist * (char_r*char_r) * res);
    return 0;
}