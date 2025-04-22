import java.util.*;
public class Unique_Combi 
{
    public static void main(String[] args) 
    {
        int first;
        int second;
        int third;
        long val;
        for(first = 100 ; first <= 999 ; first++)
        {
            for( second = 100 ; second <= 999 ; second++ )
            {
                third = first + second;
                short ref = 0;
                if((third / 1000) == 0) continue;
                val = ((first*10000000L) + (second*10000) + third);
                while(val != 0)
                {
                    int dig = (int)(val%10);
                    if(((ref & (1<<dig)))==0)
                        ref = (short)(ref | (1<<dig));
                    else 
                        break;
                    val/=10;
                }
                if(val==0)
                {
                    System.out.println(first+" + "+second+" = "+third);
                    break;
                }
            }
        }
    }
}
