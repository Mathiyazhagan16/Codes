import java.util.*;
public class Num_to_Words 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        String[] ones = {"zero","one","two","three","four","five","six","seven","eight","nine","","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
        String[] tens = {"","ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
        if(N>99)
        {
            System.out.print(ones[N/100]+" hundred ");
            N = N%100;
            if(N == 0) System.out.print("only");
            else 
            {
                System.out.print("and ");
                if(N <= 19)
                    System.out.print(ones[N]);
                else
                {
                    System.out.print(tens[N/10]+" ");
                    if(N%10 != 0)
                        System.out.print(ones[N%10]);
                }
            }
        }
        else 
        {
            if(N <= 19)
            {
                System.out.print(ones[N]);
            }
            else
            {
                System.out.print(tens[N/10]+" ");
                if(N%10 != 0)
                {
                    System.out.print(ones[N%10]);
                }
            }
        }
        input.close();
    }
}
