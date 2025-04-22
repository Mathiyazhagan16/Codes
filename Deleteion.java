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
    Node root;
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
            for(tptr = root ; tptr!= null ;temp = tptr , tptr = ((tptr.data < num)?(tptr.right):(tptr.left)));
            if(temp.data < num)
                temp.right=newnode;
            else 
                temp.left = newnode;
        }
    }
    Node delete_node(Node root,int val)
    {
        if(root == null)
        {
            return null;
        }
        if(root.data > val)
        {
            root.left = delete_node(root.left, val);
        }
        else if(root.data < val)
        {
            root.right = delete_node(root.right, val);
        }
        else 
        {
            if(root.right == null)
            {
                return root.left;
            }
            if(root.left == null)
            {
                return root.right;
            }
            else 
            {
                Node tptr = root.right;
                while(tptr.left != null)
                {
                    tptr = tptr.left;
                }
                root.data = tptr.data;
            }
            root.right = delete_node(root.right, root.data);
        }
        return root;
    }
    void delete(int val)
    {
        this.root = delete_node(root,val);
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
public class Deleteion 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        BST tree = new BST();
        while(true)
        {
            int num = input.nextInt();
            if(num == -1) break;
            tree.create(num);
        }
        int val = input.nextInt();
        tree.delete(val);
        tree.display();
        input.close();
    }
}



//50 25 83 14 35 62 97 19 30 73 94 105 72