#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
   char **arr = (char**)malloc(3*sizeof(char*));
   for(int ind = 0 ; ind < 3 ; ind++)
   {
    arr[ind] = (char*)malloc(3*sizeof(char));
    memset(arr[ind],'@',3*sizeof(char));
   } 
   for(int row = 0;  row < 3;printf("\n"), row++)
    for(int col = 0 ; col < 3 ; col++)
        printf("%c ",arr[row][col]);
}