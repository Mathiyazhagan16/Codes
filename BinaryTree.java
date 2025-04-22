import java.util.*;
class Node
{
    int data;
    Node right;
    Node left;
    Node(int num)
    {
        this.data = num;
        this.right = null;
        this.left = null;
    }
}
class BT
{
    int N;
    Node root = null;
    Node[] queue;
    int front = 0;
    int rear = -1;
    void passSize(int N)
    {
        this.N = N;
        queue = new Node[N];
    }
    void Create(int num)
    {
        Node newnode = new Node(num);
        if(root == null)
        {
            root = newnode;
            queue[++rear] = newnode;
        }
        else 
        {
            if(queue[front].left == null)
            {
                queue[front].left = newnode;
                queue[++rear] = newnode;
                return;
            }
            else 
            {
                queue[front].right = newnode;
                queue[++rear] = newnode;
                front++;
                return;
            }
        }
    }
    void inorder(Node root)
    {
        if(root != null)
        {
            inorder(root.left);
            System.out.print(root.data+" ");
            inorder(root.right);
        }
    }
    void display()
    {
        inorder(root);
    }
}
public class BinaryTree 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        BT tree = new BT();
        int N = input.nextInt();
        tree.passSize(N);
        while(N-- != 0)
        {
            int num = input.nextInt();
            tree.Create(num);
        }
        tree.display();
        input.close();
    }
}






// root							
//                              1							
                      
                      
                      
//             2								3			
                      
//     4				5				6				7	
                      
// 8		9		10		11		12		13		14		15
                      
