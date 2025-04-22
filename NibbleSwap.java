import java.util.*;
public class NibbleSwap 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        N = ((N & 0xFF00)) | (((N & 0xF) << 4 ) | ((N & 0xF0) >> 4));
        System.out.println(N);
        input.close();
    }
}