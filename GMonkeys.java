import java.util.*;
public class GMonkeys 
{
    public static int gcd(int num1,int num2)
    {
        int fac = 1;
        int HCF = 0;
        while(fac <= num1 && fac <= num2)
        {
            if(num1%fac == 0 && num2%fac == 0)
            {
                HCF = fac;
            }
            fac++;
        }
        return HCF;
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[] monkeys = new int[N+1];
        int lcm = 1;
        for(int ind = 1 ; ind<=N ; ind++)
        {
            monkeys[ind] = input.nextInt();
        }
        for(int ind = 1 ; ind <= N ; ind++)
        {
            int ori = ind;
            int cur = ind;
            int count = 0;
            do 
            {
                count++;
                cur = monkeys[cur];
            }while(ori != cur);
            lcm = (lcm*count)/gcd(lcm,count);
        }
        System.out.println(lcm);
        input.close();
    }
}







