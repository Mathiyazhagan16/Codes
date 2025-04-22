import java.util.*;
public class uniqueChar 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String str1 = input.next();
        String str2 = input.next();
        int len2 = str2.length();
        int len1 = str1.length();
        int ref = 0;
        for(int ind = 0 ; ind < len2 ; ind++)
        {
            ref = ref|(1<<(int)(str2.charAt(ind) - 'a'));
        } 
        for(int ind = 0 ; ind < len1 ; ind++)
        {
            if((ref&(1<<(int)(str1.charAt(ind) - 'a')))==0)
                System.out.print(str1.charAt(ind));
        } 
        input.close();
    }
}
