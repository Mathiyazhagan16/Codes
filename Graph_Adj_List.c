#include<stdio.h>
#include<stdlib.h> 
struct AdjListNode
{
    int data; 
    struct AdjListNode *next; 
}; 
struct AdjList 
{
   struct AdjListNode *head;
}; 
struct Graph 
{
    int v; 
    struct AdjList* arr; 
}; 
struct Graph* CreateGraph(int vertex)
{
    struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph)); 
    graph->v=vertex; 
    graph->arr=(struct AdjList*)malloc(sizeof(struct AdjList)*vertex); 
    int i; 
    for(i=0;i<graph->v;i++)
    {
        graph->arr[i].head=NULL;
    }
    return graph;
}
void AddEdges(struct Graph *graph,int src,int dest)
{
    struct AdjListNode *newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode)); 
    newNode->data=dest;  
    newNode->next=graph->arr[src].head;
    graph->arr[src].head=newNode; 
    newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode)); 
    newNode->data=src;  
    newNode->next=graph->arr[dest].head;
    graph->arr[dest].head=newNode; 
}
void PrintGraph(struct Graph *graph)
{
    int i; 
    for(i=0;i<graph->v;i++)
    {
        struct AdjListNode *temp=graph->arr[i].head;  
        printf("%d -> ",i);
        while(temp!=NULL)
        {
            printf("%d ",temp->data); 
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int vertex,edges,src,dest; 
    scanf("%d %d",&vertex,&edges); 
    struct Graph *graph=CreateGraph(vertex);     
    int i; 
    for(i=1;i<=edges;i++)
    {
        scanf("%d %d",&src,&dest); 
        AddEdges(graph,src,dest); 
    }
    PrintGraph(graph); 
}