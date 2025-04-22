//increament of the value by one

//example., input = 1234 : output = 1235 



#include<stdio.h>
int main()
{
    int num;
    int copy_num;
    int invert = 1; 
    scanf("%d",&num);
    while((num & invert) != 0) // loop to access all the bits until it reaches zero
    {
        num = num ^ invert;   // invertion of the bits until it reaches zero 
        invert = invert << 1; // variable to access all place values until it reaches Zero
    }
    num = num ^ invert; // invertion of Zero
    printf("%d",num);
}
