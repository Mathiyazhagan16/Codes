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
public class Radix 
{
    public static int maxdig(int[] arr)
    {
        int max = arr[0];
        for(int ind = 0 ; ind < arr.length ; ind++)
        {
            if(max < arr[ind])
                max = arr[ind];
        }
        return (int)(Math.log(max))+1;
    }
    public static void main(String[] args) 
    {
        int[] arr = new int[]{354,1243,57,123,58,78,3451,5375,789,24,153,7568,7,980,2,144,3465,89,345,4712435,124,645,7568,678,9};
        int len = arr.length;
        int pow = 1;
        int count = maxdig(arr);
        while(count-- != 0)
        {
            Node[] start = new Node[10];
            Node[] end = new Node[10];
            for(int ind = len-1 ; ind>=0 ; ind--)
            {
                int dig = (arr[ind] / pow) % 10;
                Node newnode = new Node(arr[ind]);
                if(start[dig] == null)
                {
                    start[dig] = newnode;
                    end[dig] = newnode;
                }
                else 
                {
                    end[dig].next = newnode;
                    end[dig] = newnode;
                }
            }
            int ind = len-1;
            for(int ptr = 9 ; ptr>=0 ; ptr--)
            {
                Node tptr = start[ptr];
                while(tptr != null)
                {
                    arr[ind--] = tptr.data;
                    tptr = tptr.next;
                }
            }
            pow*=10;
        }
        for(int ind=0;ind<len;ind++)
        {
            System.out.print(arr[ind]+" ");
        }
    }
}