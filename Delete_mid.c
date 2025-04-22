//Delete the middle of a given linked list
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
void Delete_mid(NODE * start)
{
    NODE *temp; 
    NODE *s_ptr=start;
    NODE *d_ptr=start;
    while(d_ptr && d_ptr->address)
    {
        temp=s_ptr;
        s_ptr=s_ptr->address;
        d_ptr=d_ptr->address->address;
    }
    temp->address=s_ptr->address;
    free(s_ptr);
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
    Delete_mid(start);
    for(NODE *tptr=start;tptr;printf("%d ",tptr->data),tptr=tptr->address);
}