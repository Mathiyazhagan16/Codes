import java.util.Scanner;
public class SelectionSort
{
    static void selectionSort(int[] arr)
    {
        int N = arr.length;
        for(int pos = 0 ; pos < N - 1 ; pos++)
        {
            int min_pos = pos;
            for(int ind = pos + 1 ; ind < N ; ind++)
            {
                if(arr[min_pos] > arr[ind])
                {
                    min_pos = ind;
                }
            }
            arr[pos] = (arr[pos]+arr[min_pos]) - (arr[min_pos] = arr[pos]);
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
        selectionSort(arr);
        for(int ind = 0 ; ind < N ; ind++)
        {
            System.out.print(arr[ind]+" ");
        }
        input.close();
    }
}