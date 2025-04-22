import java.util.*;
public class Unique_Num 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int start = input.nextInt();
        int end = input.nextInt();
        int count = 0 ;
        while(start <= end)
        {
            int temp = start;
            short ref = 0;
            while(temp != 0)
            {
                int dig = temp%10;
                if((ref & (1<<dig))==0)
                {
                    ref = (short)(ref | (1<<dig));
                }
                else 
                {
                    break;
                }
                temp/=10;
            }
            if(temp == 0) count++;
            start++;
        }
        System.out.print(count);
        input.close();
    }
}
