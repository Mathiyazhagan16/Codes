//Alternate merge
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
    (*start==NULL)?(*start=*end=newnode):(*end=(*end)->address=newnode);
}
void Alternate_merge(NODE ** start1,NODE ** start2)
{
    NODE *list1_curr=*start1,*list2_curr=*start2;
    NODE *list1_next,*list2_next;
    while(list1_curr && list2_curr)
    {
        list1_next=list1_curr->address;
        list2_next=list2_curr->address;
        list2_curr->address=list1_next;
        list1_curr->address=list2_curr;
        list1_curr=list1_next;
        list2_curr=list2_next;
    }
    *start2=list2_curr;
}
int main()
{
    NODE* start1=NULL,*start2=NULL,*end1=NULL,*end2=NULL;
    int num;
    while(1)
    {
       scanf("%d",&num);
       if(num==-1) break;
       sll(num,&start1,&end1);
    }
    while(1)
    {
       scanf("%d",&num);
       if(num==-1) break;
       sll(num,&start2,&end2);
    }
    Alternate_merge(&start1,&start2);
    for(NODE *tptr=start1;tptr;printf("%d ",tptr->data),tptr=tptr->address);
}