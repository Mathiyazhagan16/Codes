import java.util.*;
public class Euler 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int fac=2;
        int res=N;
        while(fac*fac<=N)
        {
            if(N%fac==0)
            {
                res = res - (res/fac);
            }
            while (N%fac==0) N/=fac;
            fac++;
        }
        if(N>1) res = res - (res/fac);
        System.out.print(res);
        input.close();
    }
}
