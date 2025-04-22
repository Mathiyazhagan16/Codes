#include<stdio.h>
int main()
{
    return 0;
}
/*
Number crunching

seperation

destruction(LSD)

12345
dig=(input/p_val) % 10; p_val = p_val * 10;
5 = (12345/1    ) % 10; 10     = 1     * 10; 
4 = (12345/10   ) % 10; 100    = 10    * 10;
3 = (12345/100  ) % 10; 1000   = 100   * 10;
2 = (12345/1000 ) % 10; 10000  = 1000  * 10;
1 = (12345/10000) % 10; 100000 = 10000 * 10;
pv > input (or) input/pv == 0 -> stop

#include<stdio.h>
int main()
{
    int input;
    int p_val;
    p_val = 1;
    scanf("%d",&input);
    while(input/p_val != 0)
    {
        int dig = (input/p_val) % 10;
        printf("%d ",dig);
        p_val = p_val*10;
    }
}



construction(MSD)

12345
dig=( input / p_val ) % 10; p_val = p_val / 10;
1 = ( 12345 / 10000 ) % 10; 1000 = 10000 / 10;
2 = ( 12345 / 1000  ) % 10; 100  = 1000  / 10;
3 = ( 12345 / 100   ) % 10; 10   = 100   / 10;
4 = ( 12345 / 10    ) % 10; 1    = 10    / 10;
5 = ( 12345 / 1     ) % 10; 0    = 1     / 10;


#include<stdio.h>
int main()
{
    int input;
    int p_val;
    p_val = 1;
    scanf("%d",&input);
    while(input/p_val != 0)
    {
        p_val *= 10;
    }
    p_val/=10;
    while(p_val!=0)
    {
        int dig=( input / p_val ) % 10; 
        printf("%d ",dig);
        p_val = p_val / 10;
    }
}




formation

right side formation

12345
5 4 3 2 1
res = dig + res * 10
5     = 5 + 0 * 10
54    = 4 + 5 * 10 
543   = 3 + 54 * 10
5432  = 2 + 543 * 10
54321 = 1 + 5432 * 10

//Reversing a Number
#include<stdio.h>
int main()
{
    int input;
    int p_val;
    int rev;
    rev = 0;
    p_val = 1;
    scanf("%d",&input);
    while(input/p_val != 0)
    {
        int dig = (input/p_val) % 10;
        rev = rev * 10 + dig; 
        p_val = p_val*10;
    }
    printf("%d",rev);
}





//Palindrome
#include<stdio.h>
int main()
{
    int input;
    int p_val;
    int rev;
    rev = 0;
    p_val = 1;
    scanf("%d",&input);
    while(input/p_val != 0)
    {
        int dig = (input/p_val) % 10;
        rev = rev * 10 + dig; 
        p_val = p_val*10;
    }
    printf("%s",(rev == input)?"Palindrome":"Not a Palindrome");
}


left side formation

12345

1 2 3 4 5
rev   = dig * p_val + rev;p_val = p_val * 10;
1     = 1 * 1 + 0       ; 10     = 1     * 10;
21    = 2 * 10 + 1      ; 100    = 10    * 10;
321   = 3 * 100 + 21    ; 1000   = 100   * 10;
4321  = 4 * 1000 + 321  ; 10000  = 1000  * 10;
54321 = 5 * 10000 + 4321; 100000 = 10000 * 10;

#include<stdio.h>
int main()
{
    int input;
    int p_val;
    int rev;
    int base;
    rev = 0;
    base = 1;
    p_val = 1;
    scanf("%d",&input);
    while(input/p_val != 0)
    {
        p_val *= 10;
    }
    p_val/=10;
    while(p_val!=0)
    {
        int dig=( input / p_val ) % 10; 
        rev   = dig * base + rev;
        base = base * 10;
        p_val = p_val / 10;
    }
    printf("%d",rev);
}





#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    printf("%s",(num%9 == 1)?"Magic number":"Not a magic number");
    return 0;
}  






/*
 Number crunching

 Seperation

 Destruction ( LSD )

 12345
dig = (input/pv)%10;pv = pv * 10;
5=(12345/1    )%10; 10     = 1     * 10;
4=(12345/10   )%10; 100    = 10    * 10;
3=(12345/100  )%10; 1000   = 100   * 10;
2=(12345/1000 )%10; 10000  = 1000  * 10;
1=(12345/10000)%10; 100000 = 10000 * 10;
input / pv == 0 (or) input < pv

//Soft method
#include<stdio.h>
int main()
{
    int input;
    int pv;
    scanf("%d",&input);
    pv = 1;
    while(input / pv != 0)
    {
        int dig = (input/pv)%10;
        printf("%d ",dig);
        pv = pv * 10;
    }
    return 0;
}  


//hard method
#include<stdio.h>
int main()
{
    int input;
    scanf("%d",&input);
    while(input != 0)
    {
        int dig = input%10;
        printf("%d ",dig);
        input/=10;
    }
    return 0;
} 



Construction (MSD)
 12345
dig = (input/pv)%10;pv = pv / 10;
1=(12345/10000)%10; 1000 = 10000 / 10;
2=(12345/1000 )%10; 100  = 1000  / 10;
3=(12345/100  )%10; 10   = 100   / 10;
4=(12345/10   )%10; 1    = 10    / 10;
5=(12345/1    )%10; 0    = 1     / 10;
pv == 0 -> stop



#include<stdio.h>
int main()
{
    int input;
    int pv = 1;
    scanf("%d",&input);
    while(input/pv != 0)
    {
        pv*=10;
    }
    pv/=10;
    while(pv != 0)
    {
        int dig = (input/pv)%10;
        printf("%d ",dig);
        pv/=10;
    }
    return 0;
}  



formation

right side formation

12345

5 4 3 2 1
rev   =dig+ rev  * 10;
5     = 5 + 0    * 10;
54    = 4 + 5    * 10;
543   = 3 + 54   * 10;
5432  = 2 + 543  * 10;
54321 = 1 + 5432 * 10;

//Reverse a number
#include<stdio.h>
int main()
{
    int input;
    int rev;
    int pv;
    scanf("%d",&input);
    pv = 1;
    rev = 0;
    while(input / pv != 0)
    {
        int dig = (input/pv)%10;
        rev = rev * 10 + dig;
        pv = pv * 10;
    }
    printf("%d",rev);
    return 0;
}



//Palindrome
#include<stdio.h>
int main()
{
    int input;
    int rev;
    int pv;
    scanf("%d",&input);
    pv = 1;
    rev = 0;
    while(input / pv != 0)
    {
        int dig = (input/pv)%10;
        rev = rev * 10 + dig;
        pv = pv * 10;
    }
    printf("%s",(rev == input)?"palindrome":"Not a palindrome");
    return 0;
} 


12345

1 2 3 4 5
rev   =dig* pv    + rev  ; pv = pv * 10;
1     = 1 * 1     + 0    ; 10     = 1     * 10;
21    = 2 * 10    + 1    ; 100    = 10    * 10;
321   = 3 * 100   + 21   ; 1000   = 100   * 10;
4321  = 4 * 1000  + 321  ; 10000  = 1000  * 10; 
54321 = 5 * 10000 + 4321 ; 100000 = 10000 * 10;


//reverse
#include<stdio.h>
int main()
{
    int input;
    int base = 1;
    int pv = 1;
    int rev = 0;
    scanf("%d",&input);
    while(input/pv != 0)
    {
        pv*=10;
    }
    pv/=10;
    while(pv != 0)
    {
        int dig = (input/pv)%10;
        rev   =dig* base    + rev  ; 
        base = base * 10;
        pv/=10;
    }
    printf("%d",rev);
    return 0;
}  
*/