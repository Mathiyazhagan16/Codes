import java.util.*;
public class Subnumber_sum
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        long num = input.nextLong();
        input.close();
        long base = 10;
        long sub_num;
        long sum = 0;
        while(num/(base/10) != 0)
        {
            long pv = 1;
            while(num / (pv*base/10) != 0)
            {
                sub_num = (long)(num / pv ) % base;
                sum = sum + sub_num;
                pv = pv * 10;
            }
            base = base * 10;
        }
        System.out.print(sum);
        return ;
    }
}

/*
 * 
 * 7654
 * 
 * single digits
 * dig = (num / pv ) % 10 ; pv = pv * 10
 * 4 = (7654 / 1   ) % 10 ; 10 = 1 * 10
 * 5 = (7654 / 10  ) % 10 ; 100 = 10 * 10
 * 6 = (7654 / 100 ) % 10 ; 1000 = 100 * 10
 * 7 = (7654 / 1000) % 10 ; 10000 = 1000 * 10
 * num / pv == 0 (stop)
 * 
 * 7654
 * 1000*10
 * 
 * 
 * 7654
 * 100 * 100
 * 
 * 
 * 
 * 
 * two digits
 * dig= (num / pv   ) % 100 ;pv = pv * 10
 * 54 = (7654 / 1   ) % 100 ;10 = 1 * 10
 * 65 = (7654 / 10  ) % 100 ;100 = 10 * 10
 * 76 = (7654 / 100 ) % 100 ;1000 = 100 * 10 
 * num / (pv/10)
 * 
 * 
 * 3 digits
 * 
 * 
 * 4 digits
 * 
 * 
 * sum = sub_num + sum ; 
 * 7  = 7 + 0
 * 13 = 6 + 7
 * 18 = 5 + 13
 * 22 = 4 + 18
 * 
 * 
 * 
 * 
 */
