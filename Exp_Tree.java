import java.util.*;
public class Exp_Tree 
{
    static class Node
    {
        char ch;
        Node right;
        Node left;
        Node(char ch)
        {
            this.ch = ch;
            this.right = null;
            this.left = null;
        }
    }
    static int prec(char ch)
    {
        switch(ch)
        {
            case '+':case '-': return 1;
            case '*':case '/':case '%': return 2;
            case '^': return 3;
        }
        return 0;
    }
    static void Create_Tree(char[] str)
    {
        Node root = null;
        Node[] stack = new Node[str.length];
        int top = -1;
        for(int ind = 0 ; str[ind] != '\0' ;ind++)
        {
            char ch = str[ind];
            Node newnode = new Node(ch);
            if(ch>='0' && ch<='9')
            {
                stack[++top] = newnode;
            }
            else 
            {
                newnode.right = stack[top--];
                newnode.left = stack[top--];
                stack[++top] = newnode;
            }
        }
        root = stack[top--];
        System.out.println(eval(root));
    }
    static int evaluation(int num1,int num2,char ch)
    {
        int res = 0;
        switch(ch)
        {
            case '+': res = num1+num2;break;
            case '-': res = num1-num2;break;
            case '*': res = num1*num2;break;
            case '/': res = num1/num2;break;
            case '%': res = num1%num2;break;
            case '^': res = (int)(Math.pow(num1,num2));break;
        }
        return res;
    }
    static int eval(Node root)
    {
        if(root.ch>= '0' && root.ch<='9')
        {
            return root.ch-'0';
        }
        else
        {
            int val1 = eval(root.left);
            int val2 = eval(root.right);
            return evaluation(val1,val2,root.ch);
        }
    }
    static void postfix_Conv(String infix)
    {
        int len = infix.length();
        char[] post = new char[len+1];
        char[] stack = new char[len];
        int pos = 0;
        int top = -1;
        for(int ind = 0 ; ind < len ; ind++ )
        {
            char ch = infix.charAt(ind);
            if(ch>='0' && ch<='9')
            {
                post[pos++] = ch;
            }
            else if(ch == '(')
            {
                stack[++top] = ch;
            }
            else if(ch == ')')
            {
                while(top != -1 && stack[top] != '(')
                {
                    post[pos++] = stack[top--];
                }
                top--;
            }
            else 
            {
                while(top != -1 && (prec(ch))<=(prec(stack[top])))
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
        post[pos]='\0';
        Create_Tree(post);
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String infix = input.nextLine();
        postfix_Conv(infix);
        input.close();
    }
}

//2+3-5^7/(1*4)
