/*

Number crunching

seperation
    destruction
    construction
formation
    right side formation
    left side formation


seperation
destruction
Hard method:

num=12345;
dig=num   % 10 ; num  = num   / 10 ; 
5 = 12345 % 10 ; 1234 = 12345 / 10 ;
4 = 1234  % 10 ; 123  = 1234  / 10 ;
3 = 123   % 10 ; 12   = 123   / 10 ;
2 = 12    % 10 ; 1    = 12    / 10 ;
1 = 1     % 10 ; 0    = 1     / 10 ;
0


#include<stdio.h>
int main()
{
    int num;
    int dig;
    scanf("%d",&num);
    while(num!=0)
    {
        dig=num%10;
        printf("%d ",dig);
        num=num/10; 
    }
    printf("\n%d",num);
    return 0;
}


soft method:
num=12345
dig=(num/pv) % 10; pv = pv*10;
5 = (12345/1    ) % 10; 10 = 1*10
4 = (12345/10   ) % 10; 100 = 10*10
3 = (12345/100  ) % 10; 1000 = 100*10
2 = (12345/1000 ) % 10; 10000 = 1000*10
1 = (12345/10000) % 10; 100000 = 10000*10
100000

#include<stdio.h>
int main()
{
    int num;
    int dig;
    int pv;
    scanf("%d",&num);
    pv=1;
    while(pv<=num)
    {
        dig=(num/pv)%10;
        printf("%d ",dig);
        pv=pv*10;
    }
    printf("\n%d",num);
    return 0;
}

digits counting and pv formation

by destructing a number
count=0;
num=num/10;count++;
12345/10 = 1234 ; count++;
1234/10  = 123  ; count++;
123/10   = 12   ; count++;
12/10    = 1    ; count++;
1/10     = 0    ; count++;
0

pv=1;
num=num/10;pv=pv*10;
12345/10 = 1234 ; 10=1*10;
1234/10  = 123  ; 100=10*10;
123/10   = 12   ; 1000=100*10;
12/10    = 1    ; 10000=1000*10;
1/10     = 0    ; 100000=10000*10;
100000

#include<stdio.h>
int main()
{
    int num;
    int count;
    count=0;
    scanf("%d",&num);
    while(num!=0)
    {
        count++;
        num=num/10;
    }
    printf("%d\n%d",count,num);
    return 0;
}


#include<stdio.h>
int main()
{
    int num;
    int pv;
    pv=1;
    scanf("%d",&num);
    while(num>=10)
    {
        pv=pv*10;
        num=num/10;
    }
    //pv=pv/10;
    printf("%d\n%d",pv,num);
    return 0;
}

without altering a number
while(num/pv){ pv=pv*10}
(12345/1) => 10=1*10;
(12345/10) => 100=10*10;
(12345/100) => 1000=100*10;
(12345/1000) => 10000=1000*10;
(12345/10000) => 100000=10000*10;
(12345/100000) =>0

#include<stdio.h>
int main()
{
    int num;
    int pv;
    pv=1;
    scanf("%d",&num);
    while(num/(pv*10))
    {
        pv=pv*10;
    }
    printf("%d\n%d",pv,num);
    return 0;
}

#include<stdio.h>
#include<math.h>
int main()
{
    int num;
    int count;
    scanf("%d%n",&num,&count);
    printf("%d",(int)pow(10,(count-1)));
    return 0;
}


construction
hard method:

num=12345
dig=num/pv;num=num%pv;pv=pv/10;
1 = 12345 / 10000 ; 2345=12345%10000 ; 1000 = 10000 / 10;
2 =  2345 / 1000  ; 345 = 2345%1000  ; 100  = 1000  / 10;
3 =   345 / 100   ; 45  =  345%100   ; 10   = 100   / 10;
4 =    45 / 10    ; 5   =   45%10    ; 1    = 10    / 10;
5 =     5 / 1     ; 0   =    5%1     ; 0    = 1     / 10;
0


#include<stdio.h>
int main()
{
    int num;
    int pv;
    int dig;
    pv=1;
    scanf("%d",&num);
    while(num/(pv*10))
    {
        pv=pv*10;
    }
    while(num!=0)
    {
        dig=num/pv;
        printf("%d ",dig);//1
        num=num%pv;//2345
        pv=pv/10;//1000
    }
    printf("\n%d",num);
    return 0;
}


construction 
soft method:

num=12345
dig=(num%pv) / (pv/10) ;pv=pv/10;  
1 = (12345%100000) / (100000 /10) ;10000=100000 /10;l
2 = (12345%10000 ) / (10000  /10) ;1000 =10000  /10;
3 = (12345%1000  ) / (1000   /10) ;100  =1000   /10;
4 = (12345%100   ) / (100    /10) ;10   =100    /10;
5 = (12345%10    ) / (10     /10) ;1    =10     /10;

#include<stdio.h>
int main()
{
    int num;
    int pv;
    int dig;
    pv=1;
    scanf("%d",&num);
    while(num/pv)
    {
        pv=pv*10;
    }
    while(pv>=10)
    {
        dig=(num%pv)/(pv/10);
        printf("%d ",dig);
        pv=pv/10;
    }
    printf("\n%d",num);
    return 0;
}


formation
Right side formation


res  =dig+res*10
5    =5+0   *10
54   =4+5   *10
543  =3+54  *10
5432 =2+543 *10
54321=1+5432*10

#include<stdio.h>
int main()
{
    int num;
    int dig;
    int pv;
    int res;
    scanf("%d",&num);
    pv=1;
    res=0;
    while(pv<=num)
    {
        dig=(num/pv)%10;
        res  =dig+res*10;
        pv=pv*10;
    }
    printf("%d",res);
    return 0;
}

Left side formation
res  =dig * base + res; base=base*10;
1    =1 * 1     + 0    ; 10 = 1*10
21   =2 * 10    + 1    ; 100 = 10*10
321  =3 * 100   + 21   ; 1000 = 100*10
4321 =4 * 1000  + 321  ; 10000 = 1000*10
54321=5 * 10000 + 4321 ; 100000 = 10000*10

#include<stdio.h>
int main()
{
    int num;
    int pv;
    int dig;
    int res;
    int base;
    pv=1;
    scanf("%d",&num);
    while(num/(pv*10))
    {
        pv=pv*10;
    }
    res=0;
    base=1;
    while(num!=0)
    {
        dig=num/pv;
        res=dig*base+res;
        base=base*10;
        num=num%pv;
        pv=pv/10;
    }
    printf("%d",res);
    return 0;
}



//Palindrome
#include<stdio.h>
int main()
{
    int num;
    int dig;
    int pv;
    int res;
    scanf("%d",&num);
    pv=1;
    res=0;
    while(pv<=num)
    {
        dig=(num/pv)%10;
        res  =dig+res*10;
        pv=pv*10;
    }
    printf("%s",(res==num)?"palindrome":"Not");
    return 0;
}



Adam number

num=12;
input
12------21(rev)      
 |       |
 |------441(rev_sqr)
 |       |
144--=--144(res)
(sqr)


#include<stdio.h>
int main()
{
    int num;
    int square;
    int reverse;
    int sqr_rev;
    int res;
    scanf("%d",&num); 
    square=num*num;
    while(num!=0)
    {
        reverse=reverse*10+(num%10);
        num=num/10;
    } 
    sqr_rev=reverse*reverse;
    res=0;
    while(sqr_rev!=0)
    {
        res=res*10+(sqr_rev%10);
        sqr_rev=sqr_rev/10;
    } 
    printf("%s",(square==res)?"Adam number":"Not");
    return 0;
}


Armstrong number

num=153

      153      (take input)
     / | \
    /  |  \ 
   1   5   3   (seperate the digits of a input)
   |   |   |
   1 +125+ 27  (take a power of digits based on number of digits present in the input)
    \  |  /    (add the resultant values)
     \ | /
      153      (if result equal to input -> armstrong else not)



#include<stdio.h>
int main()
{
    int num;
    int count;
    int pv;
    int dig;
    int sum;
    scanf("%d%n",&num,&count);
    pv=1;
    sum=0;
    while(num>=pv) 
    {
        dig=(num/pv)%10;
        int power;
        int res;
        power=count;
        res=1;
        while(power--)
        {
            res=res*dig;
        }
        sum=sum+res;
        pv=pv*10;
    }
    printf("%s",(sum==num)?"Armstrong":"Not");
    return 0;
}


#include<stdio.h>
#include<math.h>
int main()
{
    int num;
    int count;
    int pv;
    int dig;
    int sum;
    scanf("%d",&num);
    count=(int)log10(num)+1;
    pv=1;
    sum=0;
    while(num>=pv)
    {
        dig=(num/pv)%10;
        int res;
        res=1;
        res=pow(dig,count);
        sum=sum+res;
        pv=pv*10;
    }
    printf("%d",(sum==num)?1:0);
    return 0;
}



Strong number

num=145

      145      (take input)
     / | \
    /  |  \ 
   1!  4!  5!  (seperate the digits of a input)
   |   |   |
   1 + 24+ 120 (take a factorial digits present in the input)
    \  |  /    (add the resultant values)
     \ | /
      145      (if result equal to input -> Strong else not)



#include<stdio.h>
int main()
{
    int num;
    int pv;
    int dig;
    int fact;
    int sum;
    scanf("%d",&num);
    pv=1;
    sum=0;
    while(num>=pv)
    {
        dig=(num/pv)%10;
        fact=1;
        while(dig>0)
        {
            fact=fact*dig;
            dig--;
        }
        sum=sum+fact;
        pv=pv*10;
    }
    printf("%s",(sum==num)?"Strong number":"Not");
    return 0;
}



Happy number

num=82

   82     take input from the user
  /  \ 
8^2+ 2^2 (take square of each digit present in the input and add the results) 
  \  / 
   68    (if res>9 repeat the process (or) equal to 1 -> happy (or) from 2 to 9 not a happy number)
  /  \ 
6^2 +8^2
  \  / 
  100 
 / | \ 
1 +0 +0 
 \ | / 
   1  => res=1=> happy number



#include<stdio.h>
int main()
{
    int num;
    int sum;
    scanf("%d",&num);
    if(num<=9)
    {
        if(num==1) printf("Happy number");
        else printf("Not a happy number");
    }
    else
    {
        while(1)
        {
            sum=0;
            while(num!=0)
            {
                sum=sum+((num%10)*(num%10));
                num=num/10;
            }
            if(sum==1) 
            {
                printf("Happy number");
                break;
            }
            else if(sum>=2 && sum<=9)
            {
                printf("Not a happy number");
                break;
            }
            else 
            {
                num=sum;
            }
        }
    }
    return 0;
}



magic number

num=1729 

add the digits of the number until it reaches a single digit as a sum
if res==1 ->  magic number 
if res from 2 to 9 Not 
else res>9 repeat the process


#include<stdio.h>
int main()
{
    int num;
    int sum;
    scanf("%d",&num);
    if(num<=9)
    {
        if(num==1) printf("magic number");
        else printf("Not a magic number");
    }
    else
    {
        while(1)
        {
            sum=0;
            while(num!=0)
            {
                sum=sum+(num%10);
                num=num/10;
            }
            if(sum==1) 
            {
                printf("magic number");
                break;
            }
            else if(sum>=2 && sum<=9)
            {
                printf("Not a magic number");
                break;
            }
            else 
            {
                num=sum;
            }
        }
    }
    return 0;
}


#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    printf("%s",(num%9==1)?"Magic number":"Not");
    return 0;
}

*/





