// #include<stdio.h>
// int main()
// {
//     int month;
//     int days;
//     scanf("%d",&month);
//     days = 0;
//     switch(month)
//     {
//         case 1:
//             days = days + 31;
//         case 2:
//             days = days + 28;
//         case 3:
//             days = days + 31;
//         case 4:
//             days = days + 30;
//         case 5:
//             days = days + 31;
//         case 6:
//             days = days + 30;
//         case 7:
//             days = days + 31;
//         case 8:
//             days = days + 31;
//         case 9:
//             days = days + 30;
//         case 10:
//             days = days + 31;
//         case 11:
//             days = days + 30;
//         case 12:
//             days = days + 31;
//     }
//     printf("%d",days);
// }









#include<stdio.h>
int main()
{
    int month;
    scanf("%d",&month);
    switch(month)
    {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            printf("31");
            break;
        case 4:case 6:case 9:case 11:
            printf("30");
            break;
        case 2:
            printf("28");
            break;
    }
}