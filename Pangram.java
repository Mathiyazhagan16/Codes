import java.util.*;
public class Pangram 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        int ref= 0;
        for(int ind  = 0 ; ind<str.length() ; ind++)
        {
            char ch = str.charAt(ind);
            if(ch != ' ')
            {
                ref = ref | (int)(ch-'a');
            }
        }
        for(int pos = 0 ; pos<26; pos++)
        {
            if((ref&(1<<pos)) == 0)
            {
                System.out.print("Not a pangram");
                return;
            }
        }
        System.out.print("Pangram");
        input.close();    
    }
}
