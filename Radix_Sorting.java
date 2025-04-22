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
public class Radix_Sorting 
{
    static int max(int[] arr)
    {
        int maxval=arr[0];
        for(int ind = 0 ; ind<arr.length ; ind++)
        {
            maxval = Math.max(maxval,arr[ind]);
        }
        return (int)(Math.log10(maxval))+1;
    }
    public static void main(String[] args) 
    {
        int[] arr = new int[]{2345,435,4,15,41,89,7,89,4,56,12,441,42,464,58,768,568,67,8357,8764352,56,8,76,9,8,57,3,5,2,3,5125};
        int len = arr.length;
        int pos = 1;
        int maxcnt = max(arr);
        while(maxcnt--  != 0)
        {
            Node[] head = new Node[10];
            Node[] tail = new Node[10];
            for(int ind = len-1 ; ind>=0 ; ind--)
            {
                int dig = arr[ind]/pos % 10;
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
            int i = len-1;
            for(int ind = 9 ; ind>=0 ; ind--)
            {
                Node tptr = head[ind];
                while(tptr != null)
                {
                    arr[i--] = tptr.data;
                    tptr = tptr.next;
                }
            }
            pos=pos*10;
        }
        for(int ind = 0 ; ind<arr.length ; ind++)
        {
            System.out.print(arr[ind]+" ");
        }
    }
}
