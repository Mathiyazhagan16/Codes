import java.util.*;
public class SpecialReverse 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        char[] charr = str.toCharArray();
        int front = 0;
        int rear = str.length()-1;
        while(front < rear)
        {
            if(!((charr[front] >= 'a' && charr[front] <= 'z') || (charr[front] >= 'A' && charr[front] <= 'Z')))
            {
                front++;
                continue;
            }
            if(!((charr[rear] >= 'a' && charr[rear] <= 'z') || (charr[rear] >= 'A' && charr[rear] <= 'Z')))
            {
                rear--;
                continue;
            }
            char temp = charr[front];
            charr[front] = charr[rear];
            charr[rear] = temp;
            front++;
            rear--;
        }
        System.out.print(charr);
        input.close();
    }
}
