import java.util.*;
class Node 
{
    char data;
    Node right;
    Node left;
    Node(char data)
    {
        this.data = data;
        this.right = null;
        this.left = null;
    }
}
public class ExpressionEval 
{
    static Node root = null;
    public static int prec(char ch)
    {
        switch(ch)
        {
            case '+':case '-': return 1;
            case '*':case '/':case '%': return 2;
            case '^': return 3;
        }
        return 0;
    }
    // static void display(Node root)
    // {
    //     if(root != null)
    //     {
    //         display(root.left);
    //         display(root.right);
    //         System.out.print(root.data+" ");
    //     }
    // }
    static int eval(int num1,int num2,char opeartor)
    {
        switch(opeartor)
        {
            case '+': return num1+num2;
            case '-': return num1-num2;
            case '*': return num1*num2;
            case '/': return num1/num2;
            case '%': return num1%num2;
            case '^': return (int)Math.pow(num1,num2);
        }
        return 0;
    }
    static int evaluate(Node root)
    {
        if(root.data>= '0' && root.data<='9')
        {
            return (root.data - '0');
        }
        else
        {
            int val1 = evaluate(root.left);
            int val2 = evaluate(root.right);
            return eval(val1,val2,root.data);
        }
    }
    public static void createTree(char[] str,int len)
    {
        Node[] stack = new Node[len];
        int top = -1;
        for(int ind = 0 ; ind < len ; ind++)
        {
            if(str[ind] >= '0' && str[ind] <= '9')
            {
                Node newnode = new Node(str[ind]);
                stack[++top] = newnode;
            }
            else 
            {
                Node newnode = new Node(str[ind]);
                newnode.right = stack[top--];
                newnode.left = stack[top];
                stack[top] = newnode;
            }
        }
        root = stack[top];
        System.out.print(evaluate(root));
    }
    public static void postfix(String str)
    {
        int len = str.length();
        char[] post = new char[len+1];
        char[] stack = new char[len];
        int top = -1;
        int pos = 0;
        for(int ind = 0 ; ind < len ; ind++)
        {
            char ch = str.charAt(ind);
            if(ch >= '0' && ch<='9')
                post[pos++] = ch;
            else if(ch == '(')
                stack[++top] = '(';
            else if(ch == ')')
            {
                while(top != -1 && stack[top] != '(')
                    post[pos++] = stack[top--];
                top--;
            }
            else
            {
                while(top != -1 && (prec(ch) <= prec(stack[top])))
                {
                    post[pos++] = stack[top--];
                }
                stack[++top] = ch;
            }
        }
        while(top != -1)
        {
            post[pos++] = stack[top--];
        }
        post[pos] = '\0';
        createTree(post,pos);
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String exp = input.nextLine();
        postfix(exp);
        input.close();    
    }
}
//5+3*(9/3^2)*1-1
