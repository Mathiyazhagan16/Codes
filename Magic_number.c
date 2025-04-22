// //Magic number

//         1927       take a input from the user
//       / |  | \   
//      /  |  |  \ 
//     1  +9 +2  +7   seperate the digits and do the sum
//      \  |  |  /
//       \ |  | / 
//          19        if sum > 9 do the same process with sum
//         /  \   
//        1  + 9 
//         \  / 
//          10 
//         /  \ 
//        1 +  0 
//         \  / 
//           1        if sum ==  1 -> magic number of else  -> Not a magic number


#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    if(num < 10)
    {
        if(num == 1)
        {
            printf("Magic number");
        }
        else 
        {
            printf("Not a Magic number");
        }
    }
    else 
    {
        while(1)
        {
            int sum = 0;
            while(num != 0)
            {
                sum = sum + (num%10);
                num/=10;
            }
            if(sum == 1) 
            {
                printf("Magic number");
                return 0;
            }
            else if(sum >= 2 && sum <= 9)
            {
                printf("Not a Magic number");
                return 0;
            }
            else 
            {
                num = sum;
            }
        }
    }
    return 0;
}  




// #include<stdio.h>
// int main()
// {
//     int num;
//     scanf("%d",&num);
//     printf("%s",(num%9 == 1)?"Magic number":"Not a magic number");
//     return 0;
// }  