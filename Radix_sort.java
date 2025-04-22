import java.util.*;
class Node 
{
    int data;
    Node next;
    Node(int data)
    {
        this.data = data;
        this.next = null;
    }
}
//Radix Sort
public class Radix_Sort 
{
    public static int find_count(int N,int [] arr)
    {
        int max = arr[0];
        for(int ind = 1 ; ind < N ; ind++)
        {
            if(max < arr[ind]) max = arr[ind];
        }
        return (int)Math.log10(max) + 1;
    }
    public static void main(String[] args) 
    {
        int[] arr = {563,5,54,345,123,87354222,34576,2390,352,2387,3457,54};
        int size = arr.length;
        int pv = 1;
        int count = find_count(size,arr);
        while(count != 0)
        {
            Node[] Head = new Node[10];
            Node[] Tail = new Node[10];
            for(int ind = 0 ; ind < size ; ind++)
            {
                int digit = (arr[ind] / pv) % 10;
                Node newnode = new Node(arr[ind]);
                if(Head[digit] == null)
                {
                    Tail[digit] = Head[digit] = newnode;
                }
                else 
                {
                    Tail[digit] = Tail[digit].next = newnode;
                }
            }
            int ind = 0;
            int pos = 0;
            while(ind < 10)
            {
                Node tptr = Head[ind];
                while(tptr != null)
                {
                    arr[pos++] = tptr.data; 
                    tptr = tptr.next;
                }
                ind++;
            }
            pv*=10;
            count--;  
        }  
        for(int itr = 0 ; itr < size ; itr++)
        {
            System.out.print(arr[itr]+" ");
        }
    }
}