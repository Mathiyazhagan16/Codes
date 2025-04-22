import java.util.*;
public class FlipCount 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int num1 = input.nextInt();
        int num2 = input.nextInt();
        int res = num1^num2;
        int count=0;
        while(res != 0)
        {
            if((res&1) == 1) count++;
            res >>= 1;
        }
        System.out.print(count);
        input.close();
    }
}




