//Print Nth Node from the end of a given linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* address;
}NODE;
void sll(int num,NODE **start,NODE **end)
{
    NODE * newnode=(NODE*)calloc(1,sizeof(NODE));
    newnode->data=num;
    (*start==NULL)?(*start=*end=newnode):(*end=(*end)->address=newnode);
}
int Nth_node_from_end(NODE * start,int n)
{
    static int cnt=0;
    if(start)
    {
        Nth_node_from_end(start->address,n);
        if(n==++cnt)
            printf("%d ",start->data);
    }   
}
int main()
{
    NODE* start=NULL,*end=NULL;
    int num,N;
    char ch;
    while(1)
    {
        scanf("%d",&num);
        if(num==-1) break;
        sll(num,&start,&end);
    }
    scanf("%d",&N);
    Nth_node_from_end(start,N);
    //for(NODE *tptr=start;tptr;printf("%d ",tptr->data),tptr=tptr->address);
}
