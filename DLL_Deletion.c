#include<stdio.h>
#include<stdlib.h>
struct node{int data;struct node *pre,*next;};
struct node* newnode,*start,*end,*temp;
void dll(int num)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->pre=NULL;
    newnode->next=NULL;
    if(start==NULL)
        start=end=newnode;
    else
    {
        for(end=start;end && end->data<num;temp=end,end=end->next);
        if(start==end)
        {
            newnode->next=start;
            start->pre=newnode;
            start=newnode;
        }
        else if(end==NULL)
        {
            newnode->pre=temp;
            temp->next=newnode;
            newnode=end;
        }
        else
        {
            newnode->pre=temp;
            newnode->next=end;
            end->pre=newnode;
            temp->next=newnode;
        }
    }
}
void del(int num)
{
        for(end=start;end && end->data!=num;temp=end,end=end->next);
        if(start==end)
        {
            start=start->next;
        }
        else
        {
            temp->next=end->next;
            end->next->pre=temp;
        }
        free(end);
}
void display(struct node* temp)
{
    if(temp)
    {
        printf("%d ",temp->data);
        display(temp->next);
        printf("%d ",temp->data);
    }
}
int main()
{
    int num,itr;
    for(itr=1;itr<=10;itr++)
    {
        scanf("%d",&num);
        dll(num);
    }
    display(start);
    del(5);
    printf("\n");
    display(start);
}