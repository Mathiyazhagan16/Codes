import java.util.*;
public class MaxEqiSum 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int sum = 0;
        int arr[] = new int[N];
        for(int ind = 0 ; ind <N ; ind++)
        {
            arr[ind] = input.nextInt();
        }
        for( int ind = 0 ; ind<N ; ind++)
        {
            sum+=arr[ind];
        }
        int tempsum = 0;
        for( int ind = 0 ; ind < N ; ind++)
        {
            tempsum+=arr[ind];
            if(tempsum-arr[ind] == sum-tempsum)
            {
                System.out.print(ind);
                return;
            }
        }
        System.out.print("-1");
        input.close();
    }
}
