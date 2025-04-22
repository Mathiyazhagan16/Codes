// WRITING BOT
// Problem Description

// A scientist has created a Writing Bot which will read from one book and write into another. Both books may have different dimensions i,e number of lines on each page and number of pages itself. Reads and writes also happen at different speed.

// The Bot first reads from the first book fully, then processes the format to write into the second book (done instantaneously) and finally starts writing into the second book.

// Your task is to identify, after a specified interval of time, if the Bot is reading or writing For each of these activities how much read and write activity has happened needs to be captured in terms of number of pages and number of lines on the current page

// - Constraints
// 1<=number of lines in first book, Number of pages in second book <10^3
// 1<=Number of lines in first book, Number of lines in second book < 10^2

// Input.

// The Input has 7 lines

// The first line contains an integer denoting the number of pages in the first book.

// The second line contains an integer denoting the number of lines per page of first book 

// The third line contains an integer denoting the number of pages in second book

// The fourth line contains an integer denoting the number of lines per page of second book.

// The fifth line contains an integer denoting the reading speed in lines/second

// The sixth line contains an Integer denoting the writing speed in lines/second

// The seventh line contains an integer denoting the time in seconds at which the result is to be processed.

// - Output

// On one line, print three items viz current activity performed (READ or WRITE), page number and line number . All three items should be determined by space





//                     READ                   125       145 WRITE
// <---------------------------------------->|<--------|----------------------------->


// 100 * 10 / 8  =125 SEC


// 145 - 125 = 20 * 4 = 80 -> 13(6) + 2




#include<stdio.h>
int main()
{
    int page1;
    int line1;
    int page2;
    int line2;
    int read;
    int write;
    int sec;
    scanf("%d%d%d%d%d%d%d",&page1,&line1,&page2,&line2,&read,&write,&sec);
    int read_t = page1 * line1 / read;
    if( read_t < sec )
    {
        printf("WRITE %d ",(sec-read_t)*write/line2);
        if(((sec-read_t)*write%line2)==0)
        {
            printf("%d",line2);
        }
        else
        {
            printf("%d",(sec-read_t)*write%line2);
        }
    }
    else 
    {
        printf("READ %d ",(sec*read)/line1);
        printf("%d",(((sec*read)/line1)==0)?line1:(sec*read)%line1);
    }
    return 0;
}
