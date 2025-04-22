import java.util.*;
// class Node
// {
//     int data;
//     Node next;
//     Node(int data)
//     {
//         this.data = data;
//         this.next = null;
//     }
// }
public class AlivePerson 
{
    // static Node head = null;
    // static Node tail = null;
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int power = (1<<(int)(Math.log10(N)/Math.log10(2)));
        System.out.print((N-power)*2+1);
        //System.out.print((N<<1) ^ ((power<<1)|1));
        // ( 20 - 16 ) * 2 + 1
        // ( 40 ) ^ ( 32 ) | 1
        // int num = 1;
        // while(num<=N)
        // {
        //     Node newnode = new Node(num);
        //     if(head == null)
        //     {
        //         tail = head = newnode;
        //     }
        //     else 
        //     {
        //         tail.next = newnode;
        //         tail = newnode;
        //     }
        //     num++;
        // }
        // tail.next = head;
        // Node prev = head;
        // Node curr = head.next;
        // while(curr != curr.next)
        // {
        //     prev.next = curr.next;
        //     prev = prev.next;
        //     curr = curr.next.next;
        // }
        // System.out.print(curr.data);
        input.close();
    }
}



// 10 -> 1 0 1 0
//             32168 4 2 1
// 0 0 0 0 0 0 0 1 0 1 0 0 << 1 -> 10 * 2^1
// 0 0 0 0 0 0 1 0 1 0 0 0 << 2 -> 10 * 2^3

// 10
// 20
// 40
// 80
// 160
// 320
// 640


// 1<<6 = 1 * 2^6
// 67 -> 6.8374583765

// 1 -> 1
// 2 -> 1
// 3 -> 3
// 4 -> 1
// 5 -> 3
// 6 -> 5
// 7 -> 7
// 8 -> 1
// 9 -> 3
// 10-> 5
// 11-> 7
// 12-> 9
// 13-> 11
// 14-> 13
// 15-> 15
// 16-> 1
// 17-> 1 + 2
// 18-> 1 + 2 + 2
// 19-> 1 + 2 + 2 + 2
// 20-> 1 + 2 + 2 + 2 + 2
// 21
// 22
// 23
// 24
// 25
// 26
// 27
// 28
// 29
// 30
// 31
// 32
// 33






/*
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 

1 2 4 8 16 32 63 128 256 512 1024 2048
(20 - 16) * 2 + 1
(input - nearby 2 power)=(diff)
(diff) * 2 + 1;

 int power = (1<<(int)(Math.log10(N)/Math.log10(2)));
        System.out.print((N-power)*2+1);



38















 */