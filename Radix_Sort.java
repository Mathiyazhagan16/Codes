import java.util.*;
class Node 
{
    int data;
    Node next;
    Node(int num)
    {
        this.data = num;
        this.next = null;
    }
}
public class Radix_Sort 
{
    public static int maxdig(int[] arr)
    {
        int max = arr[0];
        for(int ind = 0 ; ind<arr.length ; ind++)
        {
            if(max < arr[ind]) max = arr[ind];
        }
        return (int)Math.log10(max)+1;
    }
    public static void main(String[] args) 
    {
        int[] arr = new int[]{808,108,12,348762,6198,36,619,911,786,969,27};
        int len = arr.length;
        int pos = 1;
        int cnt = maxdig(arr);
        while(cnt-- != 0)
        {
            Node[] head = new Node[10];
            Node[] tail = new Node[10];
            for(int ind = len-1 ; ind >= 0 ; ind--)
            {
                int dig = arr[ind] / pos % 10;
                Node newnode = new Node(arr[ind]);
                if(head[dig] == null)
                {
                    head[dig] = newnode;
                    tail[dig] = newnode;
                }
                else 
                {
                    tail[dig].next = newnode;
                    tail[dig] = newnode;
                }
            }
            int ind = len-1;
            for(int  list = 9 ;list >= 0; list--)
            {
                Node tptr = head[list];
                while(tptr != null)
                {
                    arr[ind--] = tptr.data;
                    tptr=tptr.next;
                }
            }
            pos*=10;
        }
        for(int i =0;i<len;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
}