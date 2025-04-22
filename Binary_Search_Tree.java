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
class BST 
{
    Node root = null;
    void CreateTree(int num)
    {
        Node newnode = new Node(num);
        Node tptr = root;
        Node temp = null;
        if(root == null)
        {
            root = newnode;
        }
        else 
        {
            for(tptr = root ; tptr != null ; temp = tptr, tptr = ((tptr.data > num)?(tptr.left):(tptr.right)));
            if(temp.data < num)
                temp.right = newnode;
            else 
                temp.left = newnode;
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
    void preorder(Node root)
    {
        if(root != null)
        {
            System.out.print(root.data+" ");
            preorder(root.left);
            preorder(root.right);
        }
    }
    void postorder(Node root)
    {
        if(root != null)
        {
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.data+" ");
        }
    }
    int Helper_Height(Node root)
    {
        if(root == null)
        {
            return 0;
        }
        else 
        {
            return Math.max(Helper_Height(root.left),Helper_Height(root.right)) + 1;
        }
    }
    void levelorder(Node root, int level)
    {
        if(root == null)
        {
            return;
        }
        if(level == 1)
        {
            System.out.print(root.data+" ");
        }
        else 
        {
            levelorder(root.left, level-1);
            levelorder(root.right, level-1);
        }
    }
    void Display()
    {
        inorder(root);
        System.out.println();
        preorder(root);
        System.out.println();
        postorder(root);
        int height = Helper_Height(root);
        System.out.println();
        for(int level = 1; level<=height ; level++)
        {
            levelorder(root,level);
        }
        return;
    }
    
}
public class Binary_Search_Tree 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        BST tree = new BST();
        BST tree2 = new BST();
        int num;
        while(true)
        {
            num = input.nextInt();
            if(num == -1) break;
            tree.CreateTree(num);
        }
        while(true)
        {
            num = input.nextInt();
            if(num == -1) break;
            tree2.CreateTree(num);
        }
        tree.Display();
        System.out.println();
        tree2.Display();

        input.close();
    }
}