import java.util.*;
public class Spiral 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int pos=1;
        for(int row=1;row<N*2;row++)
        {
            int val=N;
            for(int dec=1;dec<pos;dec++)
            {
                System.out.print((val--)+" ");
            }
            for(int rep=1;rep<=(N*2)-(pos*2)+1;rep++)
            {
                System.out.print(val+" ");
            }
            for(int inc=1;inc<pos;inc++)
            {
                System.out.print((++val)+" ");
            }
            System.out.println();
            if(row < N) pos++;
            else pos--;
        }

    }    
}



/*                                                                                    N*2 - 
		1	2	3	4	5	6	7				1	2	3	4	5	6	7	
	1	4	4	4	4	4	4	4			1	r	r	r	r	r	r	r	          4*2-1
	2	4	3	3	3	3	3	4		2	d		r	r	r	r	r		i         4*2-1+(pos*2)
	3	4	3	2	2	2	3	4		3	d	d		r	r	r		i	i         4*2-1+(pos*2)
	4	4	3	2	1	2	3	4		4	d	d	d		r		i	i	i         4*2-7
	5	4	3	2	2	2	3	4		5	d	d		r	r	r		i	i         4*2-5
	6	4	3	3	3	3	3	4		6	d		r	r	r	r	r		i         4*2-3
	7	4	4	4	4	4	4	4			7	r	r	r	r	r	r	r	          4*2-1

 */