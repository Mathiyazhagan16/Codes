import java.util.*;
public class UniqueDecCombination 
{
    public static void main(String[] args) 
    {
        int first;
        int second;
        for(first = 100 ; first<=999 ; first++)
        {
            for(second = 100 ; second <= 999 ; second++)
            {
                int third = first + second;
                if(third > 999)
                {
                    long val = ((((first * 1000L)+second)*10000)+third);
                    short ref = 0;
                    while(val != 0)
                    {
                        ref = (short)(ref | (1<<(val%10)));
                        val/=10;
                    }
                    if(ref == 1023 && first < second)
                    {
                        System.out.printf("%d + %d = %d\n",first,second,third);
                    }
                }
            }
        }
    }
}
