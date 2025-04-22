import java.util.*;
public class STR_PERM 
{
    static String swap(String str,int i,int j)
    {
        char[] t_str = str.toCharArray();
        char temp = t_str[i];
        t_str[i] = t_str[j];
        t_str[j] = temp;
        return String.valueOf(t_str);
    }
    static void Solve(String str,int start,int end)
    {
        if(start == end)
        {
            System.out.println(str);
        }
        else
        {
            for(int ind = start ; ind <= end ; ind++)
            {
                str = swap(str,start,ind);
                Solve(str, start+1, end);
                str = swap(str,start,ind);
            }
        }
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        int len = str.length()-1;
        Solve(str,0,len);
        input.close();
    }
}
