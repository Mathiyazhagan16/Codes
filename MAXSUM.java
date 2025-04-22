import java.util.*;
public class MAXSUM 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[] arr = new int[N];
        for(int ind=0;ind<N;ind++)
        {
            arr[ind] = input.nextInt();
        }
        int maxsum=arr[0];
        int max=arr[0];
        for(int ind=1;ind<N;ind++)
        {
            maxsum = maxsum + arr[ind];
            if(max < maxsum)
            {
                max=maxsum;
            }
            if(maxsum < 0)
            {
                maxsum=0;
            }
        }
        System.out.print(max);
    }
}
