import java.util.*;
public abstract class SumOfEven 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int start = input.nextInt();
        int end   = input.nextInt();
        int sum=0;
        while(start<=end)
        {                      
            if(((start%10) + ((start%100)/10))%2==1)
            {
                sum+=start;
            }
            start++;
        }
        System.out.print(sum);
        input.close();
    }
}
