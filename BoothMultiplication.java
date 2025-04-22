import java.util.*;
public class BoothMultiplication 
{   
    public static int multiplication(int num1,int num2)
    {
        int val = num1;
        int mul = num2;
        int res = 0;
        int count = Integer.SIZE;  
        while (count-- > 0) 
        {
            if((mul&1)==1)
                res+=val;
            val<<=1;
            mul>>=1;
        }
        return res;
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int num1 = input.nextInt();
        int num2 = input.nextInt();
        System.out.print(multiplication(num1,num2));
        input.close();
    }
}


