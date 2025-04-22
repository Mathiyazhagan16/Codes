import java.util.*;
public class Keypad 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String str = input.next();
        int[] count = {0,0,3,3,3,3,3,4,3,4};
        int len = str.length();
        int[] ref = new int[len+1];
        ref[0] = 1;
        for(int ind = 1 ; ind <= len ; ind++)
        {
            ref[ind] = ref[ind-1];
            int pos = (count[str.charAt(ind-1) - '0'])-1;
            for(int itr = ind-1 ; itr> 0 && str.charAt(itr) == str.charAt(itr-1) && pos != 0 ; itr--)
            {
                ref[ind] = (ref[ind] + ref[itr-1]) % 1000000007;
                pos--;
            }
        }
        System.out.print(ref[len]);
        input.close();
    }
}

