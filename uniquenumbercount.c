#include<stdio.h>
int main()
{
        int start;
        int end;
        scanf("%d %d",&start,&end);
        int count = 0;
        while(start <= end)
        {
            short ref = 0;
            int temp = start;
            while(temp != 0)
            {
                int dig = temp % 10;
                if((ref & (1<<dig)) == 0)
                {
                    ref = (short)(ref | (1<<dig));
                }
                else 
                {
                    break;
                }
                temp /= 10;
            }
            if(temp == 0) count++;
            start++;
        }
        printf("%d",count);
}