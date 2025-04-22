import java.util.*;
public class Bot 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int page1 = input.nextInt();
        int line1 = input.nextInt();
        int page2 = input.nextInt();
        int line2 = input.nextInt();
        int read = input.nextInt();
        int write = input.nextInt();
        int sec = input.nextInt();
        int read_t = page1 * line1 / read;
        if(read_t < sec)
        {
            System.out.print("Write "+((sec-read_t)*write)/line2);
            if(((sec-read_t)*write%line2)==0)
            {
                System.out.print(" "+line2);
            }
            else
            {
                System.out.print(" "+(sec-read_t)*write%line2);
            }
        }
        else
        {
            System.out.print("Read "+(sec*read)/line1);
            if(((sec*read)%line1)==0)
            {
                System.out.print(" "+line1);
            }
            else
            {
                System.out.print(" "+(sec*read)%line1);
            }
        }
        input.close();
    }
}