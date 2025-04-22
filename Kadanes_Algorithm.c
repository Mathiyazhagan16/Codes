#include<stdio.h>
#include<limits.h>
int main()
{
     int N;
     int max;
     int maxsum;
     scanf("%d",&N);
     int arr[N];
     for(int ind=0;ind<N;ind++)
     {
          scanf("%d",&arr[ind]);
     }
     max=INT_MIN;
     maxsum=0;
     for(int ind=0;ind<N;ind++)
     {
          maxsum=maxsum+arr[ind];
          if(max<maxsum)
          {
               max=maxsum;
          }
          if(maxsum<0)
          {
               maxsum=0;
          }
     }
     printf("%d",max);
     return 0;
}