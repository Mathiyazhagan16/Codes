import java.util.*;
public class DSA 
{
    public static void PrintCommonValues(int[] arr1 , int[] arr2 , int[] arr3)
    {
        int arr1_ind = 0;
        int arr2_ind = 0;
        int arr3_ind = 0;
        int size1 = arr1.length;
        int size2 = arr2.length;
        int size3 = arr3.length;
        while(arr1_ind < size1 && arr2_ind < size2 && arr3_ind < size3)
        {
            if(arr1[arr1_ind] == arr2[arr2_ind] && arr2[arr2_ind] == arr3[arr3_ind])
            {
                System.out.print(arr1[arr1_ind]+" ");
                arr1_ind++;
                arr2_ind++;
                arr3_ind++;
                while(arr1_ind < size1 && arr1[arr1_ind] == arr1[arr1_ind-1])
                {
                    arr1_ind++;
                }
                while(arr2_ind < size2 && arr2[arr2_ind] == arr2[arr2_ind-1])
                {
                    arr2_ind++;
                }
                while(arr3_ind < size3 && arr3[arr3_ind] == arr3[arr3_ind-1])
                {
                    arr3_ind++;
                }
            }
            else if(arr1[arr1_ind] < arr2[arr2_ind])
            {
                arr1_ind++;
            }
            else if(arr2[arr2_ind] < arr3[arr3_ind])
            {
                arr2_ind++;
            }
            else 
            {
                arr3_ind++;
            }
        }
    }
    public static void main(String[] args) 
    {
        int[] arr1 = {1,5,5,10,15,20};
        int[] arr2 = {5,5,13,15,20};
        int[] arr3 = {5,5,20};
        PrintCommonValues(arr1,arr2,arr3);
    }
}

