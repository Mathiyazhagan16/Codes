#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *add;
};
void creation(int num,struct node** start,struct node**end)
{
    struct node* tptr,*prev;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->add=NULL;
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
    (*end)->add=*start;
}
void solve(struct node* start)
{
    struct node* tptr=start;
    while(tptr->add!=tptr)
    {
        struct node* tofree = tptr->add;
        tptr->add=tofree->add;
        free(tofree);
        tptr=tptr->add;
    }
    printf("%d",tptr->data);
}
int main()
{
    struct node * list1=NULL,*end1=NULL;
    int num,itr=1;
    scanf("%d",&num);
    while(itr<=num)
    {
        creation(itr++,&list1,&end1);
    }
    solve(list1);
    return 0;
}