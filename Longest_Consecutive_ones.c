#include <stdio.h>
int max(int a, int b) 
{
    return (a > b) ? a : b;
}
int longestConsecutiveOnes(char S[], int k) 
{
    int n = 0;
    while (S[n] != '\0') 
    {
        n++;
    }
    int left = 0, right = 0;
    int maxOnes = 0, maxLen = 0;
    while (right < n) 
    {
        if (S[right] == '0') 
        {
            k--;
        }
        while (k < 0) 
        {
            if (S[left] == '0') 
            {
                k++;
            }
            left++;
        }
        if (right - left + 1 > maxLen) 
        {
            maxLen = right - left + 1;
            maxOnes = right + 1;
        }
        right++;
    }
    return maxOnes;
}
int main() 
{
    int n, k;
    scanf("%d %d", &n, &k);
    char S[n];
    scanf(" %s", S);
    int result = longestConsecutiveOnes(S, k);
    printf("%d", result);
    return 0;
}





/*


Given a binary string S consisting of only 0s and 1s, write an algorithm to find the number of different ways to get the longest consecutive sub-segment of 1s only. You are allowed to change any k number of 0s to 1s. Note that two ways are similar if they lead to the same string.

Example 
Input
8 2
10101111 
Output
3
Explanation
Since only one change is allowed the different combinations possible are 1110101 1011101 and 1010111. In all the possible combinations the maximum reading with consecutive is 1011101 i.e 111 so 3 is the output.





*/












/*

Given a binary string S consisting of only 0s and 1s, write an algorithm to find the number of different ways to get the longest consecutive sub-segment of 1s only. You are allowed to change any k number of 0s to 1s. Note that two ways are similar if they lead to the same string.

Example 
Input
8 2
10101111 
Output
3
Explanation
Since only one change is allowed the different combinations possible are 1110101 1011101 and 1010111. In all the possible combinations the maximum reading with consecutive is 1011101 i.e 111 so 3 is the output.


*/