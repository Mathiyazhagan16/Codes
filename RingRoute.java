import java.util.*;
public class RingRoute 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int[] path = {800, 600, 750, 900, 1400, 1200, 1100, 1500};
        String[] BusStops = {"TH", "GA", "IC", "HA", "TE", "LU", "NI", "CA"};
        String start = input.next();
        String end = input.next();
        int len = path.length;
        int s_pos = 0;
        int e_pos = 0;
        for(int ind = 0 ; ind < len ; ind++)
        {
            if(BusStops[ind].charAt(0) == start.charAt(0) && BusStops[ind].charAt(1) == start.charAt(1))
            {
                s_pos = ind;
            }
            else if(BusStops[ind].charAt(0) == end.charAt(0) && BusStops[ind].charAt(1) == end.charAt(1))
            {
                e_pos = ind;
            }
        }
        s_pos++;
        e_pos++;
        int sum = 0;
        while(s_pos != e_pos)
        {
            s_pos = s_pos%len;
            sum+=path[s_pos];
            s_pos++;
        }
        System.out.print(Math.ceil((sum/1000.0)*5)+" INR");
    }
}
