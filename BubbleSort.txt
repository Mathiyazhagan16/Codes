import java.util.Scanner;
public class BubbleSort
{
    static void bubbleSort(int[] arr)
    {
        int N = arr.length;
        for(int cle = 1 ; cle < N ; cle++)
        {
            for(int ind = 0 ; ind < N - cle ; ind++)
            {
                if(arr[ind] > arr[ind+1])
                {
                    arr[ind] = (arr[ind]+arr[ind+1]) - (arr[ind+1] = arr[ind]);
                }
            }
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
        bubbleSort(arr);
        for(int ind = 0 ; ind < N ; ind++)
        {
            System.out.print(arr[ind]+" ");
        }
        input.close();
    }
}