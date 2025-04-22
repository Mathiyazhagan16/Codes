
// Lucky Person

// Given that N person (numbered 1 to N) standing as to form a circle. They all have the gun in their hand which is pointed to their leftmost Partner. 

// Every one shoots such that 1 shoot 2, 3 shoots 4, 5 shoots 6 …. (N-1)the shoot N (if N is even otherwise N shoots 1). 
// Again on the second iteration, they shoot the rest of remains as above mentioned logic (now for n as even, 1 will shoot to 3, 5 will shoot to 7 and so on). 

// The task is to find which person is the luckiest(didn’t die)?









import java.util.*;
class Node 
{
    int data;
    Node add;
    Node(int num)
    {
        data = num;
        add = null;
    }
}
public class Lucky_Person 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        Node head = null;
        Node tptr = null;
        for(int val = 1 ; val <= N ; val++)
        {
            Node newnode = new Node(val);
            if(head == null)
            {
                head = newnode;
                newnode.add = head;
            }
            else 
            {
                tptr = head;
                while(tptr.add != head)
                    tptr = tptr.add;
                tptr.add = newnode;
                newnode.add = head;
            }
        }
        // tptr.add = head;
        Node prev = head;
        Node curr = head.add;
        while(curr != curr.add)
        {
            prev.add = curr.add;
            prev = prev.add;
            curr = curr.add.add;
        }
        System.err.print(curr.data);
        input.close();
    }
}






// import java.util.*;
// public class NANDHA 
// {
//     public static void main(String[] args) 
//     {
//         Scanner input = new Scanner(System.in);
//         int N = input.nextInt();
//         int power = (1 << (int)(Math.log10(N)/Math.log10(2)));
//         System.out.print((N-power)*2+1);
//         input.close();
//     }
// }

