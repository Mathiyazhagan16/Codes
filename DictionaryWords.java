import java.util.*;
public class DictionaryWords 
{
    static int isSubstring(String word, String str, int start,int end)
    {
        int i=0;
        while(i < word.length() && (i+start)<end)
        {
            if(word.charAt(i) != str.charAt(i+start))
            {
                return 0;
            }
            i++;
        }
        if(i == word.length()) return 0;
        return 1;
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        String[] words = new String[N];
        for(int ind = 0 ; ind < N ; ind++)
        {
            words[ind] = input.next();
        }
        String str = input.next();
        int len = str.length();
        for(int ind = 0 ; ind < len ; ind++)
        {
            for(int i=0;i<N;i++)
            {
                for(int itr = len-1 ; itr>=ind ; itr--)
                {
                    if((isSubstring(words[i],str,ind,itr)) == 1)
                    {
                        System.out.println(words[i]);
                        ind = itr+1;
                        break;
                    }
                }
            }
        }
        input.close();
    }
}


//5 i like ice cream icecream ilikeicecream