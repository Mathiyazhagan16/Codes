#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node* add;
}Node;
int main()
{
    Node * head = NULL,* tail = NULL;
    int num;
    while(1)
    {
        scanf("%d",&num);
        if(num == -1) break;
        Node * newnode = (Node*)calloc(1,sizeof(Node));
        newnode->data = num;
        (head == NULL)?(tail = head = newnode):(tail = tail->add = newnode);
    } 
    for(Node* tptr = head ; tptr != NULL ; tptr = tptr->add)
        printf("%d ",tptr->data);
}