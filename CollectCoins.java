import java.util.*;
public class CollectCoins 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int K = input.nextInt();
        input.nextLine();
        int[] room = new int[N];
        for(int ind=0;ind<N;ind++)
        {
            room[ind]=input.nextInt();
        }
        int coin=0;
        int start=0;
        int end=0;
        int ref1=0;
        int ref2=0;
        while(end<N)
        {
            if(K == coin)
            {
                ref1 = start+1; 
                ref2 = end;
                coin = room[end] + coin;
                end++;
            }
            else if(K > coin)
            {
                coin = room[end] + coin;
                end++;
            }
            else
            {
                coin-=room[start];
                start++;
            }
        }
        System.out.print(ref1+" "+ref2);
    }
}
