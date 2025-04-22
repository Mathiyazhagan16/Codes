import java.util.Scanner;
public class QuickSort
{
    static int Sort(int[] arr,int start,int end)
    {
        int ind = 0;
        int front_ind = start;
        for(ind = start ; ind < end ; ind++)
        {
            if(arr[ind] < arr[end])
            {
                arr[front_ind] = (arr[front_ind] + arr[ind]) - (arr[ind] = arr[front_ind]);
                front_ind++;
            }
        }
        arr[front_ind] = (arr[front_ind] + arr[ind]) - (arr[ind] = arr[front_ind]);
        return front_ind;
    }
    static void quickSort(int[] arr,int start,int end)
    {
        if(start < end)
        {
            int pivot = Sort(arr,start,end);
            quickSort(arr,start,pivot-1);
            quickSort(arr,pivot+1,end);
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
        quickSort(arr,0,N-1);
        for(int ind = 0 ; ind < N ; ind++)
        {
            System.out.print(arr[ind]+" ");
        }
        input.close();
    }
}
