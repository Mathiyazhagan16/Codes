import java.util.*;
public class BinaryPaindrome 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int temp = N;
        int res = 0;
        while(temp != 0)
        {
            res <<= 1;
            int bit = (temp & 1);
            res = res | bit;
            temp >>= 1;
        }
        System.out.printf("%s",(N == res)?"Palindrome":"Not a Palindrome");
        input.close();
    }
}
