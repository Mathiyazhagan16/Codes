import java.util.*;
import java.math.BigInteger;
public class probprime 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String str = input.next();
        BigInteger val = new BigInteger(str);
        if(val.isProbablePrime(10) == true)
        {
            System.err.println("Yes");
        }    
        else
        {
            System.err.println("NO");
        }
        input.close();
    }
}
