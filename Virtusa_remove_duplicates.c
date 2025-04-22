#include<stdio.h>
void remove_duplicate(char *str,int ref,int len)
{
    for(int ind=ref+1;ind<len;ind++)
    {
        if(str[ref]==str[ind])
        {
            for(int shift=ind;shift<len;shift++)
            str[shift]=str[shift+1];
            len--;
            ind--;
        }
    }
}
int main()
{
    int len;
    char str[1000];
    scanf("%[^\n]",str);
    for(len=0;str[len];len++);
    for(int ref=0;ref<len;ref++)
    {
        remove_duplicate(str,ref,len);
    }
    printf("%s",str);
    return 0;
}