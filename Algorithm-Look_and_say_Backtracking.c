#include <stdio.h>
#include <string.h>
void solve(int num,char *input)
{
	char result[1024];
	if(num==0)
    {
        printf("%s\n",input);
        return;
    }
    else
    {
	    char prev = input[0];
	    int count = 1;
	    int i, j = 0;           
        for(i=1;input[i]; i++)
        {
            if(input[i] == prev)
            {
                count++;
            } 
            else
            {
                result[j++] = count + '0';
                result[j++] = prev;
                count = 1;
            }
            prev = input[i];
        }	
        result[j++] = count + '0';
        result[j++] = prev;
        result[j]='\0';
        solve(num-1,result);
    }
}
int main()
{
	char input[1024]="1";
	int num;  
	scanf("%d",&num);
    solve(num-1,input);
	return 0;
}

