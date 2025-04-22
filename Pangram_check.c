// Pangram Checking

// Given a string check if it is Pangram or not. A pangram is a sentence containing every 
// letter in the English Alphabet.
// Examples : The quick brown fox jumps over the lazy dog ” is a Pangram [Contains all the 
// characters from „a‟ to „z‟]
// “The quick brown fox jumps over the dog” is not a Pangram [Doesn‟t contains all the 
// characters from „a‟ to „z‟, as „l‟, „z‟, „y‟ are missing]
// We create a mark[] array of Boolean type. We iterate through all the characters of our 
// string and whenever we see a character we mark it. Lowercase and Uppercase are 
// considered the same. So „A‟ and „a‟ are marked in index 0 and similarly „Z‟ and „z‟ are 
// marked in index 25.
// After iterating through all the characters we check whether all the characters are marked 
// or not. If not then return false as this is not a pangram else return true.


#include<stdio.h>
int main()
{
    int ind;
    int position;
    int pangram_ref;
    char pangram_str[10000];
    pangram_ref = 0;
    scanf("%[^\n]",pangram_str);
    for(ind = 0 ; pangram_str[ind] != '\0' ; ind++) //loop to access all the char from the string
    {
        char temp_ch = pangram_str[ind]; // copy the char in temp variable(optional)
        if(temp_ch == ' ') //if char is equal to space do nothing and skip the step
            continue;
        if(temp_ch >= 'a' && temp_ch <= 'z') // if char is lowercase find the equalent position to copy referance
            position = temp_ch - 97;
        if(temp_ch >= 'A' && temp_ch <= 'Z') // if char is uppercase find the equalent position to copy referance
            position = temp_ch - 65;
        pangram_ref = pangram_ref | (1<<position); // take referance in a proper position of pangram ref variable
    }
    printf("%s",(pangram_ref == (1<<26)-1)?"Pangram":"Not a pangram"); // referance must be eual to '11111111111111111111111111' to be a pangram
}
