#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int prec(char c) {
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
int Do_Eval(int num1,int num2,char operator)
{
    switch(operator)
    {
        case '+': return num1+num2;
        case '-': return num1-num2;
        case '*': return num1*num2;
        case '/': return num1/num2;
        case '%': return num1%num2;
        case '^': return pow(num1,num2);
    }
}
void evaluate(char* str)
{
    int stack[100];
    int stack_top=-1;
    int res;
    for(int ind=0;ind<strlen(str);ind++)
    {
        if(str[ind]>='0' && str[ind]<='9')
        {
            stack[++stack_top]=str[ind]-'0';
        }
        else 
        {
            int val1 = stack[stack_top--];
            int val2 = stack[stack_top--];
            stack[++stack_top]=Do_Eval(val2,val1,str[ind]);
        }
    }
    printf("%d",stack[stack_top]);
}
void infixToPostfix(char* str) 
{
	char result[100];
	int resultIndex=0;
	int len = strlen(str);
	char stack[1000];
	int stackIndex = -1;
	for (int i = 0; i < len; i++) 
    {
		char c = str[i];
		if (c >= '0' && c <= '9')
        {
			result[resultIndex++] = c;
		}
		else if (c == '(') 
        {
			stack[++stackIndex] = c;
		}
		else if (c == ')') 
        {
			while (stackIndex >= 0 && stack[stackIndex] != '(') 
            {
				result[resultIndex++] = stack[stackIndex--];
			}
			stackIndex--;
		}
		else 
        {
			while (stackIndex >= 0 && (prec(str[i]) < prec(stack[stackIndex]) || prec(str[i]) == prec(stack[stackIndex]))) 
            {
				result[resultIndex++] = stack[stackIndex--];
			}
			stack[++stackIndex] = c;
		}
	}
	while (stackIndex >= 0) 
    {
		result[resultIndex++] = stack[stackIndex--];
	}
	result[resultIndex] = '\0';
	evaluate(result);
}
int main() 
{
	char exp[100];
    scanf("%s",exp);
    infixToPostfix(exp);
	return 0;
}
