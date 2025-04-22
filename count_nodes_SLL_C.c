#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *add;
}NODE;
void Create_node(int num,NODE** start,NODE** end)
{
    NODE* newnode = (NODE*)calloc(1,sizeof(NODE));
    newnode->data=num;
    if(*start==NULL)
    {
        *start=newnode;
        *end=newnode;
    }
    else 
    {
        (*end)->add=newnode;
        *end=newnode;
    }
}
int count(NODE* start)
{
    int count;
    NODE* tptr=start;
    while(tptr)
    {
        count++;
        tptr=tptr->add;
    }
    return count;
}
int main()
{
    NODE * start=NULL,* end=NULL;
    int num;
    do
    {
        scanf("%d",&num);
        if(num==-1) break;
        Create_node(num,&start,&end);
    }while(num!=-1);
    printf("%d",count(start));
    return 0;
}