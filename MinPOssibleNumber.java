import java.util.*;
public class MinPOssibleNumber 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int res = 0;
        int pv=1;
        if(N < 10)
        {
            res = N + 10;
        }
        else
        {
            for(int fac = 9 ; fac >= 2 ; fac--)
            {
                while(N%fac == 0)
                {
                    res = fac * pv + res;
                    pv*=10;
                    N/=fac;
                }
            }
            if(N > 1)
            {
                System.out.print("Not possible");
                return;
            }
        }
        System.out.print(res);
        input.close();
    }
}


