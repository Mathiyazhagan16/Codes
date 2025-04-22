#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int ind = 0; ind < N ; ind++)
    {
        scanf("%d",&arr[ind]);
    }
    //left Rotation
    int R;
    scanf("%d",&R);
    for(int rot = 1; rot <= R%N ; rot++)
    {
        int temp = arr[0];
        //left shifting
        for(int ind = 0 ; ind<N-1 ; ind++)
        {
            arr[ind] = arr[ind+1];
        }
        arr[N-1] = temp;
    }
    for(int ind = 0; ind < N ; ind++)
    {
        printf("%d ",arr[ind]);
    }
    return 0;
}

