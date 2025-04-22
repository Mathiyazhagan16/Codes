import java.util.*;
public class Duplicate 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        short ref=0;
        while(N!=0)
        {
            if((ref&(1<<(N%10)))==0)
            {
                ref=(short)(ref | (1<<(N%10)));
            }
            else 
            {
                break;
            }
            N/=10;
        }
        System.out.printf("%s",(N==0)?"No Duplicates":"Have a Duplicates");
        input.close();
    }
}
