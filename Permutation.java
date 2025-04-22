import java.util.*;
public class Permutation 
{
    public static void swap(char[] str,int ind1,int ind2)
    {
        char temp = str[ind1];
        str[ind1] = str[ind2];
        str[ind2] = temp;
    }
    public static void rearrange(char[] str,int start,int end)
    {
        if(start == end)
            System.out.println(str);
        else 
            for(int ind = start ; ind <= end ; ind++)
            {
                swap(str,start,ind);
                rearrange(str, start+1, end);
                swap(str,start,ind);
            }            
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String in = input.next();
        char[] str = in.toCharArray();
        int len = in.length();
        rearrange(str,0,len-1);
        input.close();
    }
}
