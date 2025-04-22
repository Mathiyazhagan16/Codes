#include<stdio.h>
#include<string.h>
typedef struct roman
{
    int   val;
    char strVal[3];
} ROMAN;
ROMAN combi[]={{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
int mystrLen(char gs[]);
int main()
{
    int base, position, len;
    char outputStr[100]="", outputStrInd, largeChar;
    int combiInd, combiSize;
    long long int res =0,power, romVal = 236;
    combiSize = sizeof(combi) / sizeof(ROMAN);
    do
    {
        outputStr[0]='\0';
        res=0;
            for(combiInd = 0; combiInd < combiSize; combiInd++)
            {
                if(romVal < combi[combiInd].val) continue;
                while(romVal>=combi[combiInd].val)
                {
                    strcat(outputStr, combi[combiInd].strVal);
                    romVal -= combi[combiInd].val;
                }
            }
        printf("%s\n", outputStr);
        for(largeChar = outputStr[0], outputStrInd = 1;outputStr[outputStrInd] != '\0'; outputStrInd++)
            if(outputStr[outputStrInd] > largeChar)
                largeChar = outputStr[outputStrInd];
        base = (largeChar - 'A')+10 + 1;
        len = mystrLen(outputStr);
        for(outputStrInd = len -1, power = 1 ; outputStrInd >=0; outputStrInd--, power*=base)
        {
            position = outputStr[outputStrInd] - 65 + 10;
            res=res + (position * power);
        }
        romVal=res;
    }while(romVal <= 3999);
    printf("%lld", romVal);
    return 0;
}
int mystrLen(char gs[])
{
    int len;
    for(len = 0; gs[len];len++);
    return len;
}
