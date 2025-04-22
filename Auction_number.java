import java.util.*;
public class Auction_number 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int dist = input.nextInt();
        char sc = input.next().charAt(0);
        char ec = input.next().charAt(0);
        int sn = input.nextInt();
        int en = input.nextInt();
        // System.out.print(dist+" "+sc+" "+ec+" "+sn+" "+en);
        int nr = en - sn + 1;
        int cr = ec - sc + 1;
        int res = (nr*nr*nr*nr) - nr - (nr*(nr-1)*4);
        System.out.println(dist*(cr*cr)*res);
        input.close();
    }
}


