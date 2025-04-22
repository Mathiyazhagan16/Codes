import java.util.*;
public class Auction 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int dist = input.nextInt();
        char sc = input.next().charAt(0);
        char ec = input.next().charAt(0);
        int sn = input.nextInt();
        int en = input.nextInt();
        int n_r = en - sn + 1;
        int c_r = ec - sc + 1;
        int nonspl = (n_r * n_r * n_r * n_r) - (n_r) - (n_r*(n_r-1)*4);
        System.out.print(dist*nonspl*(c_r*c_r));
        input.close();
    }
}
