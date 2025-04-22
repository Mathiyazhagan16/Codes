#include<stdio.h>
int isOperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='^') return 1;
    return 0;
}
int prec(char ch)
{
    switch(ch)
    {
        case '+':case '-':         return 1;
        case '*':case '%':case '/':return 2;
        case '^':                  return 3;
        default :                  return 0;
    }
}
void ToPostfix(char *infix)
{
    char postfix[50],stack[20];
    int ind,post_top=-1,stack_top=-1;
    for(ind=0;infix[ind];ind++)
    {
        if(infix[ind]>='0' && infix[ind]<='9')
            postfix[++post_top]=infix[ind];//1
        else if(infix[ind]=='(')
            stack[++stack_top]=infix[ind];//2
        else if(infix[ind]==')')
        {
            while(stack[stack_top]!='(')
                postfix[++post_top]=stack[stack_top--];//3
            if(stack[stack_top]=='(') stack[stack_top--];
        }
        else if(isOperator(infix[ind]))
        {
            while(prec(stack[stack_top]) >= prec(infix[ind]))
                postfix[++post_top]=stack[stack_top--];//3
            stack[++stack_top]=infix[ind];//2
        }
    }
    while(stack_top!=-1)
        postfix[++post_top]=stack[stack_top--];//3
    postfix[++post_top]='\0';
    printf("%s",postfix);
}
int main()
{
    char infix[50];
    scanf("%s",infix);
    ToPostfix(infix);
}

/*
infix    ->  1+2-3*4+(2-3+4*4/2+(1/1+1)+9)-1+1
postfix  ->  12+34*-23-44*2/+11/1++9++1-1+

73+1+11*3973^*4*+/1/-9+

*/