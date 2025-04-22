import java.util.*;
public class CountDoors 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N =  input.nextInt();
        System.out.print((int)Math.sqrt(N));
        // int[] doors = new int[N];
        // for(int cle = 1 ; cle <= N ; cle++)
        // {
        //     for(int ind = cle-1 ; ind < N ; ind+=cle)
        //     {
        //         if(doors[ind] == 1)
        //         {
        //             doors[ind] = 0;
        //         }
        //         else 
        //         {
        //             doors[ind] = 1;
        //         }
        //     }
        // }
        // int count = 0;
        // for(int ind = 0 ; ind < N ; ind++)
        // {
        //     if(doors[ind] == 1) 
        //     {
        //         count++;
        //     }
        // }
        // System.out.print(count);
        input.close();
    }
}