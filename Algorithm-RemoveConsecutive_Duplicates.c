#include<stdio.h>
void RemoveDuplicates(char * str)
{
    if(*(str+0)=='\0')
    {
        return;
    }
    if(*(str+0)==*(str+1))
    {
        int ind=0;
        while(str[ind]!='\0')
        {
            *(str+ind)=*(str+(ind+1));
            ind++;
        }
        RemoveDuplicates(str);
    }
    RemoveDuplicates(str+1);
}
int main()
{
    int testcases;
    scanf("%d",&testcases);
    for(int itr=1;itr<=testcases;itr++)
    {
        char str[100000];
        scanf("%s",str);
        RemoveDuplicates(str);
        printf("%s",str);
    }
}