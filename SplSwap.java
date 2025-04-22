import java.util.*;
public class SplSwap 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String in_str = input.next();
        char[] str = in_str.toCharArray();
        int front = 0;
        int rear = in_str.length()-1;
        while(front < rear)
        {
            if(!((str[front] >= 'A' && str[front] <= 'Z') || (str[front] >= 'a' && str[front] <= 'z')))
            {
                front++;
                continue;
            }
            if(!((str[rear] >= 'A' && str[rear] <= 'Z') || (str[rear] >= 'a' && str[rear] <= 'z')))
            {
                rear--;
                continue;
            }
            char temp = str[front];
            str[front] = str[rear];
            str[rear] = temp;
            front++;
            rear--;
        }
        System.out.print(str);
        input.close();
    }
}
