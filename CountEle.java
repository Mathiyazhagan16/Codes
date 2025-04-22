import java.util.*;
public class CountEle 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[] arr = new int[N];
        for(int ind=0;ind<N;ind++)
        {
            arr[ind] = input.nextInt();
        }
        int num = input.nextInt();
        int count=0;
        for(int ind=0;ind<N;ind++)
        {
            if(arr[ind] > (num+num))
            {
                count++;
            }
        }
        System.out.print(count);
        input.close();
    }    
}
