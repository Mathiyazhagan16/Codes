//Remove duplicate from sorted linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* address;
}NODE;
void sll(int num,NODE **start,NODE **end)
{
    NODE * newnode,*temp,*tptr;
    newnode=(NODE*)calloc(1,sizeof(NODE));
    newnode->data=num;
    if(*start==NULL)
    {
        *start=*end=newnode;
    }
    else
    {
        for(tptr=*start;tptr && tptr->data<num;temp=tptr,tptr=tptr->address);
        if(*start==tptr)
        {
            newnode->address=(*start);
            *start=newnode;
        }
        else if(tptr==NULL)
        {
            temp->address=newnode;
            *end=newnode;
        }
        else
        {
            temp->address=newnode;
            newnode->address=tptr;
        }
    }
}
void sortedlist_rem_dup(NODE ** start,NODE ** end)
{
    NODE * ptr=*start,*tptr;
    while(ptr)
    {
        tptr=ptr;
        while(tptr->address && tptr->data==tptr->address->data)
        {
            NODE* temp=tptr->address;
            tptr->address=tptr->address->address;
            free(temp);
        }
        ptr=ptr->address;
    }
}
int main()
{
    NODE* start=NULL,*end=NULL;
    int num;
    char ch;
    while(1)
    {
        scanf("%d",&num);
        if(num==-1) break;
        sll(num,&start,&end);
    }
    sortedlist_rem_dup(&start,&end);
    for(NODE *tptr=start;tptr;printf("%d ",tptr->data),tptr=tptr->address);
}