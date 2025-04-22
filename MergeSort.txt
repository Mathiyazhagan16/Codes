import java.util.Scanner;
public class MergeSort 
{
    static void merge(int[] arr,int start,int mid,int end)
    {
        int len1 = mid - start + 1;
        int len2 = end - mid;
        int[] left = new int[len1];
        int[] right = new int[len2];
        for(int ind = 0; ind < len1 ; ind++)
        {
            left[ind] = arr[start+ind];
        }
        for(int ind = 0 ; ind < len2 ; ind++)
        {
            right[ind] = arr[mid+1+ind];
        }
        int left_ind = 0;
        int right_ind = 0;
        int ori_ind = start;
        while(left_ind < len1 && right_ind < len2)
        {
            if(left[left_ind] < right[right_ind])
            {
                arr[ori_ind] = left[left_ind];
                ori_ind++;
                left_ind++;
            }
            else 
            {
                arr[ori_ind] = right[right_ind];
                right_ind++;
                ori_ind++;
            }
        }
        while(left_ind < len1)
        {
            arr[ori_ind] = left[left_ind];
            ori_ind++;
            left_ind++;
        }
        while(right_ind < len2)
        {
            arr[ori_ind] = right[right_ind];
            right_ind++;
            ori_ind++;
        }
    }
    static void mergeSort(int[] arr,int start,int end)
    {
        if(start < end)
        {
            int mid = (start+end)/2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr,start,mid,end);
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
        mergeSort(arr,0,N-1);
        for(int ind = 0 ; ind < N ; ind++)
        {
            System.out.print(arr[ind]+" ");
        }
        input.close();
    }  
}
