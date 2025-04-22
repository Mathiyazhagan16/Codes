import java.util.*;
public class SmallestInt 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int pv=1;
        int res=0;
        if(N<10)
        {
            System.out.print(N+10);
        }
        else 
        {
            for(int fac=9;fac>1;fac--)
            {
                while(N%fac==0)
                {
                    res = res + (pv*fac);
                    pv=pv*10;
                    N=N/fac;
                }
            }
            if(N>1) 
            {
                System.out.println("Not possible");
            }
            else
            {
                System.out.print(res);
            }
        }
        input.close();
    }
}

