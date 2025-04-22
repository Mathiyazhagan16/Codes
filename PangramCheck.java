import java.util.*;
public class PangramCheck 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        int len = str.length();
        int pos = 0;
        int ref = 0;
        for(int ind = 0 ; ind < len ; ind++)
        {
            char ch = str.charAt(ind);
            if(ch == ' ') continue;
            if(ch>='A' && ch<='Z')
            {
                pos = (int)(ch - 'A');
            }
            if(ch>='a' && ch<='z')
            {
                pos = (int)(ch - 'a');
            }
            ref = (ref | (1<<pos));
        }
        for(pos = 0 ; pos < 26 ; pos++)
        {
            if((ref & (1<<pos)) == 0)
            {
                System.out.print("Not a Pangram");
                return;
            }
        }
        System.out.print("Pangram");
        input.close();
    }
}
