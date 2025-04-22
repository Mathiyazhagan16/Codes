//Remove duplicate from unsorted linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* address;
}NODE;
void sll(long long int num,NODE **start,NODE **end)
{
    NODE * newnode,*temp,*tptr;
    newnode=(NODE*)calloc(1,sizeof(NODE));
    newnode->data=num;
    (*start==NULL)?(*start=*end=newnode):(*end=(*end)->address=newnode);
}
void unsortedlist_rem_dup(NODE ** start)
{
    NODE * ptr,*tptr,*temp;
    for(ptr=*start;ptr && ptr->address;ptr=ptr->address)
    {
        tptr=ptr;
        while(tptr->address)
        {
            if(ptr->data==tptr->address->data)
            {
                temp=tptr->address;
                tptr->address=tptr->address->address;
                free(temp);
            }
            else tptr=tptr->address;
        }
    }
}
int main()
{
    NODE* start=NULL,*end=NULL;
    long long int num;
    while(1)
    {
       scanf("%lld",&num);
       if(num==-1) break;
       sll(num,&start,&end);
    }
    unsortedlist_rem_dup(&start);
    for(NODE *tptr=start;tptr;printf("%lld ",tptr->data),tptr=tptr->address);
}