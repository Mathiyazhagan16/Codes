import java.util.*;
public class SS
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int Num = input.nextInt();
        int power;
        int copy;
        int sub_Num;
        int sum;
        sum = 0;
        power = 10;
        while(Num>=(power/10))
        {
            copy = Num;
            while(copy >= (power/10))
            {
                sub_Num = copy%power;
                sum = sum + sub_Num;
                copy = copy / 10;
            }
            power = power * 10;
        }
        System.out.println(sum);
        input.close();
    }
}

/*
 * 
 * 
 * 456
 * 
 * sub_Num = Num % 10 ; Num = Num / 10
 * 6       = 456 % 10 ; 45  = 456 / 10
 * 5       = 45  % 10 ; 5   = 456 / 10
 * 4       = 5   % 10 ; 0   = 456 / 10
 * Num == 0 && power == 10 -> Num < (power/10) - stop
 * 
 * power = power * 10
 * 
 * sub_Num = Num % 100; Num = Num / 10
 * 56      = 456 % 100; 45  = 456 / 10
 * 45      = 45  % 100; 5   = 456 / 10
 * Num == 5 && power == 100 -> Num < (power/10) - stop
 * 
 * power = power * 10
 * 
 * sub_Num = Num % 1000; Num = Num / 10
 * 456     = 456 % 1000; 45  = 456 / 10
 * Num == 45 && power == 1000 -> Num < (power/10) - stop
 * 
 * 
 * sum = sum + sub_Num
 */