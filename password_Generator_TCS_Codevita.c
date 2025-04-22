#include<stdio.h>
#include<math.h>
char Dig_in_words[10][4]={"zer","one","two","thr","fou","fiv","six","sev","eig","nin"};
void Generate_Pass()
{
    char string[210];
    char sign;
    int dec;
    int ind;
    int res;
    int dig_count;
    sign='+';
    res=-1;
    scanf(" %[^\n]",string);
    for(ind=0;string[ind]!=' ';ind++)
    {
        if(string[ind]=='.')
            sign='-';
        if(string[ind]>=49 && string[ind]<=57)
        {
            if(res==-1)
            {
                res=0;
                dec=(string[ind]-48);
                continue;
            }
            res=res*10+(string[ind]-48);
        }
        else if((!(string[ind]>=48 && string[ind]<=57)) && string[ind]!='.')
        {
            printf("Invalid");
            return;
        }
    }
    dig_count=(int)log10(res)+1;
    res=(res%9==0)?9:(res%9);
    printf("%s.%se%c%s@",Dig_in_words[dec],Dig_in_words[res],sign,Dig_in_words[dig_count]);
    ind++;
    if(ind%2==1) ind++;
    while(string[ind]!='\0')
    {
        printf("%c",string[ind]);
        ind=ind+2;
    }
}
int main()
{
    int testcase;
    scanf("%d",&testcase);
    while(testcase--)
        Generate_Pass();
}