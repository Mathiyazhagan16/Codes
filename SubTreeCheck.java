import java.util.*;
class Node 
{
    int data;
    Node right;
    Node left;
    Node(int data)
    {
        this.data = data;
        this.right = null;
        this.left = null;
    }
}
class BST 
{
    Node root = null;
    void create(int num)
    {
        Node newnode = new Node(num);
        Node tptr = null;
        Node temp = null;
        if(root == null)
        {
            root = newnode;
        }
        else 
        {
            for(tptr = root ; tptr != null ; temp = tptr , tptr = (num > tptr.data)?(tptr.right):(tptr.left));
            if(temp.data > num) temp.left = newnode;
            else temp.right = newnode;
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
    void Display()
    {
        inorder(root);
    }
    boolean Subtree(Node root1,Node root2)
    {
        if(root1 == null && root2 == null)
            return true;
        if(root1 == null || root2 == null)
            return false;
        if(root1.data != root2.data)
            return false;
        return ((Subtree(root1.left, root2.left)) && (Subtree(root1.right,root2.right)));
    }
    void check(BST tree2)
    {
        Node root2 = tree2.getroot();
        Node tptr = null;
        for(tptr = root; tptr != null && tptr.data!=root2.data;tptr = (root2.data > tptr.data)?(tptr.right):(tptr.left));
        if(tptr == null) 
        {
            System.out.println("Not a Subtree");
            return;
        }
        else
        {
            if(Subtree(tptr,root2)==true)
            {
                System.out.print("Subtree");
            }
            else 
            {
                System.out.print("Not a Subtree");
            }
        }
    }
    Node getroot()
    {
        return root;
    }
}
public class SubTreeCheck 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        BST tree1 = new BST();
        BST tree2 = new BST();
        while(true)
        {
            int num = input.nextInt();
            if(num == -1) break;
            tree1.create(num);
        }
        while(true)
        {
            int num = input.nextInt();
            if(num == -1) break;
            tree2.create(num);
        }
        tree1.check(tree2);
        input.close();
    }
}

