import java.util.*;
public class DM1 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String str1 = input.nextLine();
        String str2 = input.next();
        int len1 = str1.length();
        int len2 = str2.length();
        int count = 0;
        for(int ind = 0 ; ind < len1-len2 ; ind++)
        {
            if(str2.equals(str1.substring(ind, ind+len2)))
            {
                count++;
            }
        }
        System.out.println(count);
        input.close();
    }
}


//A Scanner breaks its input into tokens using a delimiter pattern,
//which by default matches whitespace. The resulting tokens may 
//then be converted into values of different types using the various next methods.


// it