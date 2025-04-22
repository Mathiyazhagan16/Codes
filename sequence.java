import java.util.*;
public class sequence 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int res =0 ;
        int pv = 1;
        while(N != 0)
        {
            res = res + pv * ((N%2 == 0)?(4):(3));
            N = (N%2==1)?(N/2):((N-1)/2);
            pv*=10;
        }
        System.out.println(res);
        input.close();
    }
}
