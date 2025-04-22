import java.util.*;
public class SegmentedSieve 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int start = input.nextInt();
        int end = input.nextInt();
        int[] primes = new int[end-start+1];
        for(int fac=2 ; fac * fac<=end ; fac++)
        {
            int F_mul = (start/fac)*fac;
            if(F_mul < start)
            {
                F_mul+=fac;
            }
            for(int ind=F_mul-start;ind<=(end-start);ind+=fac)
            {
                if(primes[ind]==1) continue;
                primes[ind]=1;
            }
        }
        for(int ind=0;ind<=(end-start);ind++)
        {
            if(primes[ind]==0)
            {
                System.out.print(ind+start+" ");
            }
        }
        input.close();
    }
}