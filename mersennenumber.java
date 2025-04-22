import java.util.*;
public class mersennenumber 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[] arr = new int[N];
        int sum = 0;
        int power = 0 ;
        for(int ind = 0 ; ind < N; ind++)
        {
            arr[ind] = input.nextInt();
        }
        for(int ind = 0 ; ind < N ; ind++)
        {
           if((arr[ind] & arr[ind]+1) == 0)
           {
                sum+=arr[ind];
           }
        }
        System.out.print(sum);
        input.close();    
    }
}
