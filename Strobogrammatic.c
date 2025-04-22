#include<stdio.h>
int main()
{
    int len;
    char str[100];
    scanf("%[^\n]",str);
    for(len=0;str[len];len++);
    for(int front=0,rear=len-1;front<rear;front++,rear--)
    {
        if(str[front] == str[rear])
        {
            if(!(str[front]=='1' || str[front]=='0' || str[front]=='8'))
            {
                printf("Not A Strobogrammatic number");   
                return 0;
            }
        }
        else if(!((str[front]=='6' && str[rear]=='9') || (str[front]=='9' && str[rear]=='6')))
        {
            printf("Not A Strobogrammatic number");
            return 0;
        }
    }
    printf("Strobogrammatic Number");
}

