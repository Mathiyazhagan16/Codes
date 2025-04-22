#include<stdio.h>
#include<stdlib.h>
#define V 5
int cnt=1;
void display(int path[])
{
	printf ("\nSolution no : %d\n",cnt++);
	for (int i = 0; i < V; i++)
		printf(" %d ", path[i]);
	printf(" %d ", path[0]);
	printf("\n");
}
int issafe(int v, int graph[V][V], int path[], int pos)
{
	for (int i = 0; i < pos; i++)
		if (path[i] == v || graph[path[pos-1]][v]==0)
		return 0;
	return 1;
}
void hamCycle(int graph[V][V],int path[V],int i)
{
	if(V==i)
	{
		if ( graph[ path[i-1] ][ path[0] ] == 1 )
			display(path);
		return;
	}
	for(int ind=1;ind<V;ind++)
	{
		if(issafe(ind, graph, path, i))
		{
			path[i]=ind;
			hamCycle(graph,path,i+1);
			path[i]=-1;
		}
	}
}
int main()
{
	int  graph[V][V] = {{0, 1, 0, 1, 1},
						{1, 0, 1, 1, 1},
						{0, 1, 0, 0, 1},
						{1, 1, 0, 0, 1},
						{1, 1, 1, 1, 0}};
	int *path = (int*)malloc(V*sizeof(int));
	//for (int i = 0; i < V; path[i++] = -1);
	path[0] = 0;
	hamCycle(graph,path,1);
	return 0;
}