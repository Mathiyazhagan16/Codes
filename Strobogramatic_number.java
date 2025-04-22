import java.util.*;
public class Strobogrammatic_number 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String num = input.next();
        for(int front=0,rear=num.length()-1;front<=rear;front++,rear--)
        {
            if(num.charAt(front)==num.charAt(rear))
            {
                if((num.charAt(front)!='1') && (num.charAt(front)!='0') && (num.charAt(front)!='8'))
                {
                    System.out.println("Not a strobogramatic");
                    return;
                }
            }
            else 
            {
                if(!((num.charAt(front)=='6' && num.charAt(rear)=='9') || (num.charAt(front)=='9' && num.charAt(rear)=='6')))
                {
                    System.out.println("Not a strobogramatic");
                    return;
                }
            }
        }
        System.out.print("Strobogramatic");
        input.close();
    }
}