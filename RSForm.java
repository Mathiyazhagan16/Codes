import java.util.*;
public class RSForm 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int res = 0;
        int pv = 1;
        while(true)
        {
            pv = 1;
            res = 0;
            while(N > 9)
            {
                int dig = Math.abs((N % 10) - (N/10%10));
                res = res + pv * dig;
                pv = pv * 10;
                N/=10;
            }
            if(res>99)
            {
                N = res;
            }
            else 
            {
                break;
            }
        }
        System.out.printf("%02d",res);
        input.close();
    }
}
