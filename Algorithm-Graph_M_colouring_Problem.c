#include<stdio.h>
#define V 5
void display(int color[V])
{
    for(int ind=0;ind<V;ind++)
    {
        printf("%d ",color[ind]);
    }
    printf("\n");
}
int issafe(int graph[V][V],int color[V])
{
    for(int row=0;row<V;row++)
        for(int col=0;col<V;col++)
            if(graph[row][col] && color[row]==color[col])
                return 0;
    return 1;
}
int solve(int graph[V][V],int color[V],int m,int ind)
{
    static int solution=0;
    if(ind==V)
    {
        if(issafe(graph,color))
        {
            display(color);
            solution=1;
        }
        return solution;
    }
    for(int clr=1;clr<=m;clr++)
    {
        color[ind]=clr;
        solve(graph,color,m,ind+1);
        color[ind]=-1;
    }
    return solution;
}
int main()
{
    int Graph[V][V]={{0,1,0,1,1},
                     {1,0,1,1,0},
                     {0,1,0,1,0},
                     {1,1,1,0,1},
                     {1,0,0,1,0}};
    int m=3;
    int color[V];
    color[0]=0;
    if(!solve(Graph,color,m,0)) printf("Not Possible");
    return 0;

}
