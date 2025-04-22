import java.util.Scanner;
public class InsertionSort 
{    
    static void insertionSort(int[] arr)
    {
        int N = arr.length;
        for(int pos = 1 ; pos < N ;pos++)
        {
            int ele = arr[pos];
            int index = pos - 1;
            while(index >= 0 && arr[index] > ele)
            {
                arr[index + 1] = arr[index];
                index--;
            }
            arr[index + 1] = ele;
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
        insertionSort(arr);
        for(int ind = 0 ; ind < N ; ind++)
        {
            System.out.print(arr[ind]+" ");
        }
        input.close();
    }
}
