import java.util.*;
public class StringEncode 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String str = input.next();
        int count=1;
        int ind;
        for(ind=1;ind<str.length();ind++)
        {
            if(str.charAt(ind) == str.charAt(ind-1))
            {
                count++;
            }
            else
            {
                System.out.print(str.charAt(ind-1)+""+count);
                count=1;
            }
        }
        System.out.print(str.charAt(ind-1)+""+count);
        input.close();    
    }
}
