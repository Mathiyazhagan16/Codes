#include<stdio.h>
int main()
{
    int len;
    char str[100];
    scanf("%[^\n]%n",str,&len);
    char *Name = str;
    while(Name[0])
        printf("%*s\n",len,Name++);
}
/*
Mathi

Mathi
 athi
  thi
   hi
    i
*/