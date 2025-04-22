import java.util.*;
public class Nambiar_Number 
{
    public static void main(String[] args) 
    {
        Scanner input  = new Scanner(System.in);
        long num = input.nextLong();
        //long pv = (long)Math.pow(10,(long)Math.log10(num));
        long pv = 1000000000;
        int sum = 0;
        int flag = 1;
        if(num%10 == 0) flag = 0;
        while(pv != 0)
        {
            int dig = (int)(num/pv);
            if(dig%2 == 0)
            {
                sum = sum + dig;
            }
            else 
            {
                if(sum != 0)
                {
                    sum = sum + dig;
                    System.out.print(sum);
                    sum = 0;
                }
                else 
                {
                    sum = sum + dig;
                }
            }
            num%=pv;
            pv/=10;
        }
        if(sum!=0)
            System.out.print(sum);
        if(flag == 0)
            System.out.print(flag);
        input.close();
    }
}