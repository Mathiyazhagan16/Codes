#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *add;
};
struct node *start,*end;
void sll(int num)
{
   struct node *newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=num;
   newnode->add=NULL;
   //insertion at the ending


   
   if(start==NULL)
   {
      start=newnode;
      end=newnode;
   }
   else
   {
      end->add=newnode;
      end=newnode;
   }
   //insertion at the begining
   //(start==NULL)?(end=start=newnode):(newnode->add=start,start=newnode);
}
void display()
{
   struct node* tptr=start;
   while(tptr!=NULL)
   {
      printf("%d ",tptr->data);
      tptr=tptr->add;
   }
}
void delete_at_begin()
{
   struct node* tofree=start;
   start=start->add;
   free(tofree);
}
void delete_at_mid(struct node* tptr,struct node* prev)
{
   prev->add=tptr->add;
   free(tptr);
}
void delete_val(int num)
{
   struct node* tptr,*prev=NULL;
   for(tptr=start;tptr && tptr->data!=num;prev=tptr,tptr=tptr->add);
   if(tptr==start)
   {
      delete_at_begin();
   }
   else if(tptr==NULL)
   {
      printf("Not found\n");
   }
   else
   {
      delete_at_mid(tptr,prev);
   }
}
int main()
{
   char ch;
   int num;
   do
   {
      scanf("%d%c",&num,&ch);
      sll(num);
   }while(ch!='\n');
   scanf("%d",&num);
   delete_val(num);
   display();
   return 0;
}