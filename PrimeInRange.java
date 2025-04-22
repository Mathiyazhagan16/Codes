import java.util.*;
public class PrimeInRange 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[] ref= new int[N+1];
        for(int val=2;val<=Math.sqrt(N);val++)
        {
            if(ref[val]==1) continue;
            for(int ind=val*val;ind<=N;ind+=val)
            {
                ref[ind]=1;
            }
        }
        for(int ind=2;ind<=N;ind++)
        {
            if(ref[ind]==0)
            {
                System.out.print(ind+" ");
            }
        }
        input.close();
    }
}




// import java.util.*;
// public class PrimeInRange 
// {
//     public static void main(String[] args) 
//     {
//         Scanner input = new Scanner(System.in);
//         int N = input.nextInt();
//         for(int val=2;val<=N;val++)
//         {
//             int fac;
//             for(fac=2;fac<=val/2;fac++)
//             {
//                 if(val%fac==0)
//                 {
//                     break;
//                 }
//             }
//             if(fac > (val/2)) 
//             {
//                 System.err.print(val+" ");
//             }
//         }
//         input.close();
//     }
// }