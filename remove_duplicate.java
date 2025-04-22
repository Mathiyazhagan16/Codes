import java.util.*;
public class remove_duplicate 
{
    static class Node
    {
        int data;
        Node next;
        Node(int num)
        {
            this.data = num;
            this.next = null;
        }
    }
    static Node start = null;
    static Node Last = null;
    static void MakeList()
    {
        final int[] arr = new int[]{1,2,3,3,3,4,5,5,6,7,8,9,9};
        int ind;
        for(ind = 0 ; ind<arr.length ; ind++)
        {
            Node newnode = new Node(arr[ind]);
            if(start == null)
            {
                Last = start = newnode;
            }
            else 
            {
                Last = Last.next = newnode;
            }
        }
    }
    static void PrintList()
    {
        Node tptr = start;
        while(tptr!=null)
        {
            System.out.print(tptr.data+" ");
            tptr = tptr.next;
        }
    }
    static void Dup_Deletion()
    {
        Node curr = start;
        Node adj = start.next;
        while(adj != null)
        {
            if(curr.data == adj.data)
            {
                curr.next = adj.next;
                adj = adj.next;
            }
            else 
            {
                curr = curr.next;
                adj = adj.next;
            }
        }
    }
    public static void main(String[] args) 
    {
        MakeList();
        PrintList();
        Dup_Deletion();
        System.out.println();
        PrintList();
    }
}