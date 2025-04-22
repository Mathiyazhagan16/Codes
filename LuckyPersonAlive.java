// Given that N person (numbered 1 to N) standing to form a circle. They all have the gun in their hand which is pointed to their leftmost Partner. 

// Everyone shoots such that 1 shoots 2, 3 shoots 4, 5 shoots 6 …. (N-1)the shoot N (if N is even otherwise N shoots 1). 
// Again on the second iteration, they shoot the rest of the remains as above mentioned logic (now for n as even, 1 will shoot to 3, 5 will shoot to 7, and so on). 

// The task is to find which person is the luckiest(didn’t die).

// Examples: 


// Input: N = 3 
// Output: 3 
// As N = 3 then 1 will shoot 2, 3 will shoot 1 hence 3 is the luckiest person.


// Input: N = 8 
// Output: 1 
// Here as N = 8, 1 will shoot 2, 3 will shoot 4, 5 will shoot 6, 7 will shoot 8, Again 1 will shoot 3, 5 will shoot 7, Again 1 will shoot 5 and hence 1 is the luckiest person.





import java.util.*;
public class LuckyPersonAlive
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int power = 0;
        for(power = 1 ; power <= N ; power = power * 2);
        System.out.println((N - power/2) * 2 + 1);
        input.close();
    }
}

