import java.util.*;
public class TravelFare 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int[] Dist = new int[]{800, 600, 750, 900, 1400, 1200, 1100, 1500};
        String[] Place = {"TH", "GA", "IC", "HA", "TE", "LU", "NI","CA" };
        int len = Dist.length;
        String start = input.next();
        String end = input.next();
        int ind = 0;
        int s_pos = 0;
        int e_pos = 0;
        while(ind < len)
        {
            if(Place[ind].charAt(0) == start.charAt(0) && Place[ind].charAt(1) == start.charAt(1))
            {
                s_pos = ind;
            }            
            else if(Place[ind].charAt(0) == end.charAt(0) && Place[ind].charAt(1) == end.charAt(1))
            {
                e_pos = ind;
            }
            ind++;
        }
        while(s_pos != e_pos)
        {
            s_pos = s_pos % len;
            
            s_pos++;
        }
        input.close();
    }
}
