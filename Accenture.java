import java.util.*;
public class Accenture 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[] arr = new int[N];
        for(int ind = 0 ; ind < N ; ind++)
        {
            arr[ind] = input.nextInt();
        }
        int max = arr[0];
        int max_so_far = arr[0];
        for(int ind = 1 ; ind < N ; ind++)
        {
            max_so_far = max_so_far + arr[ind];
            if(max_so_far > max)
            {
                max = max_so_far;
            }
            if(max_so_far < 0)
            {
                max_so_far = 0;
            }
        }
        System.out.println(max);
        input.close();
    }
}