// #include<stdio.h>
// int main()
// {
//     int num;
//     scanf("%d",&num);
//     if(num == 1)
//         printf("January");
//     else if(num == 2)
//         printf("February");
//     else if(num == 3)
//         printf("March");
//     else if(num == 4)
//         printf("April");
//     else if(num == 5)
//         printf("May");
//     else if(num == 6)
//         printf("June");
//     else if(num == 7)
//         printf("July");
//     else if(num == 8)
//         printf("August");
//     else if(num == 9)
//         printf("september");
//     else if(num == 10)
//         printf("October");
//     else if(num == 11)
//         printf("November");
//     else if(num == 12)
//         printf("December");
//     return 0;
// }


#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    switch(num)
    {
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("september");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;
        default:
            printf("Invalid");
            break;
    }
    return 0;
}
