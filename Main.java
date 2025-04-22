import java.util.*;
class Node 
{
    int data;
    Node right;
    Node left;
    Node(int data)
    {
        this.data = data;
    }
}
class Tree
{
    Node root = null;
    void create(int num)
    {
        Node newnode = new Node(num);
        if(root==null)
            root = newnode;
        else 
        {
            Node temp = null;
            for(Node tptr = root ; tptr != null ; temp = tptr , tptr = (tptr.data > num)?tptr.left:tptr.right);
            if(temp.data>num)
                temp.left = newnode;
            else 
                temp.right = newnode;
        }
    }
}
public class Main 
{
    public static void main(String[] args) 
    {
        Tree tree = new Tree();
        Scanner input = new Scanner(System.in);
        while(true)
        {
            int num = input.nextInt();
            if(num == -1) break;
            tree.create(num);
        }
        input.close();
    }
}
