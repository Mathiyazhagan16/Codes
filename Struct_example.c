#include<stdio.h>
typedef struct data
{
    char str[20];
    short int marks[5];
    int reg_no;
    char res;
    float percent;
}DATA;
typedef int A;
A num;
int main()
{
    DATA students[5]={{"sai" ,{1,2,3,4,95},123456789,'P',95.00},
                             {"ram" ,{5,6,7,8,35},987654321,'P',35.00},
                             {"abi" ,{9,10,11,12,20},876432533,'F',20.00},
                             {"vishwa",{12,14,15,16,100},986325938,'P',100.00},
                             {"bala" ,{17,18,19,20,45},876345129,'P',45.00}};
    printf("%d",((*(students+2)->marks)+2));
    return 0;
}
