//Print the middle of a given linked list
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
NODE* Display_mid(NODE * start)
{
    NODE *s_ptr=start;
    NODE *d_ptr=start;
    while(d_ptr && d_ptr->address)
    {
        s_ptr=s_ptr->address;
        d_ptr=d_ptr->address->address;
    }
    return s_ptr;
}
int main()
{
    NODE* start=NULL,*end=NULL;
    int num;
    char ch;
    do
    {
       scanf("%d%c",&num,&ch);
       sll(num,&start,&end);
    } while (ch!=10);
    printf("%d ",Display_mid(start)->data);
    //for(NODE *tptr=start;tptr;printf("%d ",tptr->data),tptr=tptr->address);
}