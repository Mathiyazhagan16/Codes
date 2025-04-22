import java.util.*;
public class MaxProSubarray 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[] arr = new int[N];
        for(int ind=0 ; ind<N ; ind++)
        {
            arr[ind] = input.nextInt();
        }
        int max = arr[0];
        int maxpro = arr[0];
        int minpro = arr[0];
        for(int ind=1 ; ind<N ; ind++)
        {
            int temp = Math.max((Math.max(arr[ind] , maxpro*arr[ind])) , minpro*arr[ind]);
            minpro = Math.min((Math.min(arr[ind] , maxpro*arr[ind])) , minpro*arr[ind]);
            maxpro = temp;
            max = Math.max(max , maxpro);
        }
        System.out.print(max);
        input.close();
    }
}

