import java.util.*;
public class StrobogrammaticNumber 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String str = input.next();
        int front=0;
        int rear=str.length()-1;
        for(;front<=rear;front++,rear--)
        {
            if(str.charAt(front) == str.charAt(rear))
            {
                if(!(str.charAt(front)=='0' || str.charAt(front)=='1' ||str.charAt(front)=='8'))
                {
                    System.out.print("Not");
                    return;
                }
            }
            else if(!((str.charAt(front)=='6' && str.charAt(rear)=='9') || (str.charAt(front)=='9' && str.charAt(rear)=='6')))
            {
                System.out.print("Not");
                    return;
            }
        }
        System.out.println("Strobogrammatic");
        input.close();
    }
}
