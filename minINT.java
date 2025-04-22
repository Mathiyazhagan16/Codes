import java.util.*;
public class minINT 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int res = 0;
        int pv = 1;
        if(N < 10)
        {
            res = N + 10;
        }
        else
        {
            for(int fac = 9 ; fac >= 2 ; fac--)
            {
                while(N % fac == 0)
                {
                    res = res + fac * pv;
                    N/=fac;
                    pv*=10;
                }
            }
            if(N != 1)
            {
                System.out.print("Not Possible");
                return;
            }
        }
        System.out.print(res);
    }
}
