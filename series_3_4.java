import java.util.*;
public class series_3_4
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int pv = 1;
        int res = 0;
        while(N != 0)
        {
            res = res + pv * ((N%2==0)?(4):(3));
            if(N%2==0) N--;
            pv*=10;
            N/=2;
        }
        System.out.println(res);
        input.close();   
    }
}
