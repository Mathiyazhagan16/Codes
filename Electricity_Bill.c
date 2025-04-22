#include<stdio.h>
int main()
{
    int unit;
    float bill;
    scanf("%d",&unit);
    bill = 0;
    switch(unit)
    {
        case 251 ... 1000:
            bill = (unit - 250) * 1 + bill;
            unit = 250;
        case 151 ... 250:
            bill = (unit - 150) * 0.75 + bill;
            unit = 150;
        case 51 ... 150:
            bill = (unit - 50) * 0.5 + bill;
            unit = 50;
        case 1 ... 50:
            bill = (unit - 0) * 0.25 + bill;
            unit = 0;
            break;
        default:
            printf("Invalid");
            break;
    }
    if(bill != 0) printf("%.2f",bill + bill*0.2);
}
