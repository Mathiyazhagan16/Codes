import java.util.*;
public class Strobogrammatic_Numbers 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String str = input.next();
        for(int front=0,rear=str.length()-1;front<=rear;front++,rear--)
        {
            if(str.charAt(front) == str.charAt(rear))
            {
                if(!(str.charAt(front)=='0' || str.charAt(front)=='1' || str.charAt(front)=='8'))
                {
                    System.out.print("Not a Strobogrammatic number");
                    return;
                }
            }
            else if(!((str.charAt(front)=='6' && str.charAt(rear)=='9') || (str.charAt(front)=='9' && str.charAt(rear)=='6')))
            {
                System.out.print("Not a Strobogrammatic number");
                return;
            }
        }
        System.out.print("Strobogrammatic number");
        input.close();
    }
}
