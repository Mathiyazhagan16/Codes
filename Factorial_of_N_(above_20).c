#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* factorial(int n) 
{
    char *result=(char*)calloc(10000,sizeof(char));
    result[0] = '1';
    int size = 1;
    for(int i=2;i<=n;i++) 
    {
        int carry = 0;
        for (int ind=0;ind<size;ind++) 
        {
            int product = (result[ind]-'0') * i + carry;
            result[ind] = (product % 10)+'0';
            carry = product / 10;
        }
        while (carry) 
        {
            result[size] = (carry % 10)+'0';
            carry /= 10;
            size++;
        }
    }
    for(int i=strlen(result)-1;i>=0;printf("%c",result[i--])); 
}
int main() 
{
    int num;
    char *result=factorial(156);
    return 0;
}