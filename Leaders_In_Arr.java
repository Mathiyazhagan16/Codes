import java.util.*;
public class Leaders_In_Arr 
{
    static void Solve(int[] arr , int N, int max)
    {
        int flag = 0;
        if(N >= 0)
        {
            if(arr[N] > max)
            {
                max = arr[N];
                flag++;
            }
            Solve(arr,N-1,max);
            if(flag == 1) System.out.print(max+" ");
        }
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[] arr = new int[N];
        for(int ind = 0 ; ind < N ; ind++)
        {
            arr[ind] = input.nextInt();
        }
        Solve(arr,N-1,arr[N-1]);
        System.out.print(arr[N-1]);
        // int max = arr[N-1];
        // System.out.print(max+" ");
        // for(int ind = N-2 ; ind>=0 ; ind--)
        // {
        //     if(arr[ind] > max)
        //     {
        //         max = arr[ind];
        //         System.out.print(max+" ");
        //     }
        // }
        input.close();
    }    
}


//16 17 4 3 5 6 9 1 8 2