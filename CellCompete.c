#include<stdio.h>
void cellCompete(int arr[],int days)
{
    int temp[8];
    while(days--)
    {
        temp[0]=arr[1];
        temp[7]=arr[6];
        for(int ind=1;ind<7;ind++)
        {
            temp[ind]=arr[ind-1]^arr[ind+1];
        }
        for(int ind=0;ind<8;ind++)
            arr[ind]=temp[ind];
    }
    for(int ind=0;ind<8;ind++)
        printf("%d ",arr[ind]);
}
int main()
{
    int arr[8],days;
    for(int ind=0;ind<8;ind++)
        scanf("%d",&arr[ind]);
    scanf("%d",&days);
    cellCompete(arr,days);
}


/*
There is a colony of 8 cells arranged in a straight line where each day every cell competes with its adjacent cells(neighbour). Each day, for each cell, if its neighbours are both active or both inactive, the cell becomes inactive the next day,. otherwise itbecomes active the next day.

Assumptions: The two cells on the ends have single adjacent cell, so the other adjacent cell can be assumsed to be always inactive. Even after updating the cell state. consider its pervious state for updating the state of other cells. Update the cell informationof allcells simultaneously.

Write a fuction cellCompete which takes takes one 8 element array of integers cells representing the current state of 8 cells and one integer days representing te number of days to simulate. An integer value of 1 represents an active cell and value of 0 represents an inactive cell.





*/