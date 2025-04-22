import java.util.*;
public class SumofDiv 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int Div = input.nextInt();
        int quo = num/Div;
        int rem = num%Div;
        int res = (quo * ((Div * (Div-1)) / 2)) + (rem*(rem+1)/2);
        System.out.print(res);
        input.close();
    }
}
