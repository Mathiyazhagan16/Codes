#include<stdio.h>
#include<stdlib.h>
int rows,cols,pos=0;
char word[11]="ALLIZZWELL";
int x[8]={0,-1,-1,-1,0,1,1,1};
int y[8]={-1,-1,0,1,1,1,0,-1};
void solve(char **matrix,int row,int col)
{
    if(word[pos]=='\0')
        printf("YES");
    else
    {
        for(int i=0;i<8;i++)
        {
            
        }
    }
}
int main()
{
    scanf("%d%d",&rows,&cols);
    char **matrix=(char**)calloc(rows+1,sizeof(char*));
    for(int ind=0;ind<cols;ind++)
    {
        matrix[ind]=(char*)calloc(cols+1,sizeof(char));
        scanf(" %s",matrix[ind]);
    }
    //for(int ind=0;ind<rows;ind++)
    //    printf("%s ",matrix[ind]);
    solve(matrix,0,0);
}
































/*


Mr.ESP used to tell “ALL IZZ WELL” whenever he gets into any trouble. So his friends and the people around him used to laugh at him. But Mr.ESP is very strong in his belief. He believes that the term “ALL IZZ WELL” will make everything fine. Now your task is to ignore the story above and find whether there is a path in the given matrix which makes the sentence “ALL IZZ WELL”

There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.

Input Specification:

The first line consists of an integer t representing the number of test cases.

The first line of each test case consists of two integers R and C representing the number of rows and number of columns in the matrix. The description of the matrix follows.

Output Specification:

For each test case print “YES” if there is a path which makes the sentence “ALLIZZWELL”. Else print “NO”.

Note: Take care of 4th test case

There is a new line after every test case in the input.

Input constraints:

t <= 1000
R <= 100
C <= 100

Sample Input:

5
3 6
AWE.QX
LLL.EO
IZZWLL

1 10
ALLIZZWELL

2 9
A.L.Z.E..
.L.I.W.L.

3 3
AEL
LWZ
LIZ

1 10
LLEWZZILLA
Sample Output:
YES
YES
NO
NO
YES

*/