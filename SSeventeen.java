import java.util.*;
public class SSeventeen 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        int len = str.length();
        int pv = 1;
        int val = 0;
        int sum = 0;
        for(int ind = len-1 ; ind >= 0 ; ind--)
        {
            char ch = str.charAt(ind);
            if(ch >= '0' && ch <= '9')
            {
                val = (int)(ch - 48);
            }
            if(ch >= 'A' && ch <= 'Z')
            {
                val = (int) (ch - 55);
            }
            if(ch >= 'a' && ch <= 'z')
            {
                val = (int)(ch - 87); 
            }
            sum += (pv*val);
            pv = pv*17;
        }
        System.err.println(sum);
        input.close();
    }
}
