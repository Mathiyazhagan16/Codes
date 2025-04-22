import java.util.Scanner;
public class PalStr 
{
    static String findPalindromicString(String str) 
    {
        int len = str.length();
        int freq[] = new int[26];
        countFreq(str, freq, len);
        if(!canMakePalindrome(freq, len)) 
        {
            return "No Palindromic String";
        }
        String oddStr = findOddAndRemoveItsFreq(freq);
        StringBuilder frontStr = new StringBuilder();
        StringBuilder rearStr = new StringBuilder();
        for (int i = 0; i < 26; i++) 
        {
            StringBuilder temp = new StringBuilder();
            if (freq[i] != 0) 
            {
                char ch = (char) (i + 'a');
                for (int j = 1; j <= freq[i] / 2; j++) 
                {
                    temp.append(ch);
                }
                frontStr.append(temp);
                rearStr.insert(0, temp);
            }
        }
        return frontStr.toString() + oddStr + rearStr.toString();
    }
    static void countFreq(String str, int freq[], int len) 
    {
        for (int i = 0; i < len; i++) 
        {
            freq[str.charAt(i) - 'a']++;
        }
    }
    static boolean canMakePalindrome(int freq[], int len) 
    {
        int countOdd = 0;
        for (int i = 0; i < 26; i++) 
        {
            if (freq[i] % 2 != 0) 
            {
                countOdd++;
            }
        }
        if (len % 2 == 0) 
        {
            return countOdd == 0;
        }
        return countOdd == 1;
    }
    static String findOddAndRemoveItsFreq(int freq[]) 
    {
        StringBuilder oddStr = new StringBuilder();
        for (int i = 0; i < 26; i++) 
        {
            if (freq[i] % 2 != 0) 
            {
                freq[i]--;
                oddStr.append((char) (i + 'a'));
                return oddStr.toString();
            }
        }
        return oddStr.toString();
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        String result = findPalindromicString(str);
        System.out.println(result);
        input.close();
    }
}