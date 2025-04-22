#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*add;
};
void sll(int num1,struct node ** start,struct node** end)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num1;
    newnode->add=NULL;
    (*start==NULL)?(*start=*end=newnode):(*end=(*end)->add=newnode);
}
int main()
{
    struct node* start1=NULL,*end1=NULL,*start2=NULL,*end2=NULL,*tptr,*tptr2;
    int num1,num2,i;
    for(i=1;i<=5;i++)
    {
        scanf("%d",&num1);
        sll(num1,&start1,&end1);
    }
    for(i=1;i<=5;i++)
    {
        scanf("%d",&num2);
        sll(num2,&start2,&end2);
    }
    end1->add=start2;
    for(tptr=start1;tptr;printf("%d ",tptr->data),tptr=tptr->add);
}