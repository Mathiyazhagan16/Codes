import java.util.*;
public class MaxComb 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int res = 0;
        if(N%3 == 1)
        {
            res = (int)(Math.pow(3,(N/3-1))) * 4;
        }
        else if(N%3 == 2)
        {
            res = (int)(Math.pow(3,(N/3)))*2;
        }
        else 
        {
            res = (int)(Math.pow(3,N/3));
        }
        System.out.print(res);
        input.close();
    }
}
