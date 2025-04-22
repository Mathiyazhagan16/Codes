import java.util.Arrays;
class Roman {
    int val;
    String strVal;
    Roman(int val, String strVal) 
    {
        this.val = val;
        this.strVal = strVal;
    }
}
public class Roman_Conv 
{
    public static void main(String[] args) {
        Roman[] combi = {
            new Roman(1000, "M"),
            new Roman(900, "CM"),
            new Roman(500, "D"),
            new Roman(400, "CD"),
            new Roman(100, "C"),
            new Roman(90, "XC"),
            new Roman(50, "L"),
            new Roman(40, "XL"),
            new Roman(10, "X"),
            new Roman(9, "IX"),
            new Roman(5, "V"),
            new Roman(4, "IV"),
            new Roman(1, "I")
        };

        int combiSize = combi.length;
        long res = 0;
        long power = 0;
        long romVal = 23; // Initialize romVal to 10 as per the original code
        
        do {
            StringBuilder outputStr = new StringBuilder();
            res = 0;
            
            // Convert romVal to Roman numeral
            for (int combiInd = 0; combiInd < combiSize; combiInd++) {
                if (romVal < combi[combiInd].val) continue;
                while (romVal >= combi[combiInd].val) {
                    outputStr.append(combi[combiInd].strVal);
                    romVal -= combi[combiInd].val;
                }
            }
            
            System.out.println(outputStr.toString());

            // Determine the largest character in the output string
            char largeChar = outputStr.charAt(0);
            for (int outputStrInd = 1; outputStrInd < outputStr.length(); outputStrInd++) {
                if (outputStr.charAt(outputStrInd) > largeChar) {
                    largeChar = outputStr.charAt(outputStrInd);
                }
            }
            
            // Calculate the base
            int base = (largeChar - 'A') + 10 + 1;
            
            // Convert the Roman numeral string to a number using base
            int len = outputStr.length();
            for (int outputStrInd = len - 1; outputStrInd >= 0; outputStrInd--, power *= base) {
                int position = outputStr.charAt(outputStrInd) - 65 + 10;
                res = res + (position * power);
            }

            romVal = res;
            
        } while (romVal <= 3999);
        
        System.out.println(res);
    }
}
