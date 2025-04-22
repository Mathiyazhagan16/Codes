import java.util.*;
public class UniqueCombination
{
    public static void main(String[] args) 
    {
        int first;
        int second;
        int third;
        long combined;
        for( first = 100; first <= 999; first += 1)
        {
            for( second = 100; second <= 999; second +=1)
            {
                third = first + second;
                if ( third > 1000)
                {
                    combined = ( ( (first * 1000L ) + second) * 10000 ) + third;
                    short ref = 0;
                    while(combined != 0)
                    {
                        if(( ref & (1<<(combined%10))) == 0)
                        {
                            ref = (short)(ref | (1<<(combined%10)));
                        }
                        else
                        {
                            break;
                        }
                        combined /= 10;
                    }
                    if (combined == 0 && first < second)
                    System.out.printf("%d + %d = %d\n", first, second, third);
                }
            }
        }
    }
}
