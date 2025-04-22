import java.util.*;
public class CellCompete 
{
    public static void cellcompete(int days,int[] cell)
    {
        int[] temp = new int[8];
        while(days-- != 0)
        {
            temp[0] = cell[1];
            temp[7] = cell[6];
            for(int ind = 1 ; ind <= 6 ; ind++)
            {
                temp[ind] = (cell[ind-1] ^ cell[ind+1]);
            }
            for(int ind = 0 ; ind <= 7 ; ind++)
            {
                cell[ind] = temp[ind];
            }
        }
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int[] cell = new int[8];
        for(int ind = 0 ; ind < 8 ; ind++)
        {
            cell[ind] = input.nextInt();
        }
        int days = input.nextInt();
        cellcompete(days,cell);
        for(int ind = 0 ; ind < 8 ; ind++)
        {
            System.out.print(cell[ind]+" ");
        }
        input.close();
    }
}
