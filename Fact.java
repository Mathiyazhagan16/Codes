import java.util.*;
public class Fact 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        char[] res = new char[250];
        res[0]='1';
        int size=1;
        int carry=0;
        for(int mul=2;mul<=N;mul++)
        {
            for(int ind=0;ind<size;ind++)
            {
                int pro = ((res[ind]-'0') * mul) + carry;
                res[ind] = (char)((pro%10)+'0');
                carry = pro/10;
            }
            while(carry!=0)
            {
                res[size++] = (char)((carry%10)+'0');
                carry/=10;
            }
        }
        for(int ind=size-1;ind>=0;ind--)
        {
            System.out.print(res[ind]);
        }
        input.close();
    }
}
