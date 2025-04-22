import java.util.*;
public class Luckiest_Person 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int power = (1<<(int)(Math.log10(N)/Math.log10(2)));
        //System.out.print((N - power)*2+1);
        System.out.print((N<<1)^((power<<1)|1));
        input.close();
    }
}