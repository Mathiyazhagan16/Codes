import java.util.*;
public class postfix_eval 
{
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
    public static int Evaluation(int val1,int val2,char op)
    {
        switch(op)
        {
            case '+': return val1+val2;
            case '-': return val1-val2;
            case '*': return val1*val2;
            case '/': return val1/val2;
            case '%': return val1%val2;
            case '^': return (int)(Math.pow(val1,val2));
        }
        return 0;
    }
    public static int Eval(char[] str,int size)
    {
        int[] stack = new int[20];
        int top = -1;
        for(int ind=0;ind < size;ind++)
        {
            if(str[ind] >= '0' && str[ind] <= '9')
            {
                stack[++top] = (int)(str[ind]-'0');
            }
            else 
            {
                int val2 = stack[top--];
                int val1 = stack[top--];
                stack[++top] = Evaluation(val1,val2,str[ind]);
            }
        }
        return stack[top];
    }
    public static int postfix(String exp)
    {
        int size = exp.length();
        char[] res = new char[size+1];
        char[] stack = new char[size+1];
        int pos = 0;
        int top = -1;
        for(int ind=0;ind<size;ind++)
        {
            if(exp.charAt(ind) >= '0' && exp.charAt(ind) <= '9')
            {
                res[pos++] = exp.charAt(ind);
            }
            else if(exp.charAt(ind) == '(')
            {
                stack[++top] = exp.charAt(ind);
            }
            else if(exp.charAt(ind) == ')')
            {
                while(top != -1 && stack[top] != '(')
                    res[pos++] = stack[top--];
                top--;
            }
            else
            {
                while(top != -1 && (prec(exp.charAt(ind)) <= prec(stack[top])))
                {
                    res[pos++] = stack[top--];
                }
                stack[++top] = exp.charAt(ind);
            }
        }
        while(top != -1)
        {
            res[pos++] = stack[top--];
        }
        res[pos]='\0';
        return Eval(res,pos);
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String exp = input.nextLine();
        System.out.print(postfix(exp));
        input.close();
    }
}
