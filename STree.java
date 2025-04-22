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
class Tree 
{
    Node root = null;
    void CreateTree(int num)
    {
        Node newnode = new Node(num);
        Node tptr = null;
        Node temp=null;
        if(root == null)
        {
            root = newnode;
        }
        else 
        {
            for(tptr = root ; tptr != null ; temp = tptr, tptr = (num < tptr.data)?(tptr.left):(tptr.right));
            if(temp.data > num) 
                temp.left = newnode;                
            else 
                temp.right = newnode;                
        }
    }
    void inorder(Node tptr)
    {
        if(tptr != null)
        {
            inorder(tptr.left);
            System.out.print(tptr.data+" ");
            inorder(tptr.right);
        }
    }
    void postorder(Node tptr)
    {
        if(tptr != null)
        {
            postorder(tptr.left);
            postorder(tptr.right);
            System.out.print(tptr.data+" ");
        }
    }
    void preorder(Node tptr)
    {
        if(tptr != null)
        {
            System.out.print(tptr.data+" ");
            preorder(tptr.left);
            preorder(tptr.right);
        }
    }
    void LevelOrder(Node root,int level)
    {
        if(root == null)
            return;
        if(level == 1)
        {
            System.out.print(root.data+" ");
        }
        else 
        {
            LevelOrder(root.left, level-1);
            LevelOrder(root.right, level-1);
        }
    }
    void Display()
    {
        inorder(root);
        System.out.println();
        preorder(root);
        System.out.println();
        postorder(root);
        System.out.println();
        int H = HeightHelper(root);
        for(int level = 1; level<= H ; level++)
            LevelOrder(root,level);
    }
    int HeightHelper(Node tptr)
    {
        if(tptr == null)
        {
            return 0;
        }
        else 
        {
            int LH = HeightHelper(tptr.left);
            int RH = HeightHelper(tptr.right);
            if(LH > RH) return LH+1;
            else return RH+1;
        }
    }
}
public class STree 
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        Tree tree1 = new Tree();
        int num;
        while(true)
        {
            num = input.nextInt();
            if(num == -1) break;
            tree1.CreateTree(num);
        }
        tree1.Display();
        input.close();
    }    
}
