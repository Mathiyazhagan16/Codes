#include<stdio.h>
#include<stdlib.h>
typedef struct node{int data;struct node *right,*left;}Node;
void display(Node * root)
{
    if(root != NULL)
        printf("%d ",root->data),
        display(root->left),
        display(root->right);
}
int main()
{
    Node *root=NULL;
    Node * queue[100] = {NULL};
    int num,front = 0, rear = -1;
    while(1)
    {
        scanf("%d",&num);
        if(num == -1) break;
        Node * newnode = (Node*)calloc(1,sizeof(Node));
        newnode->data = num;
        if(queue[0] == NULL)
            root = newnode;
        else if(queue[front]->left == NULL)
            queue[front]->left = newnode;
        else 
            queue[front++]->right = newnode;
        queue[++rear] = newnode;  
    }
    display(root);
    return 0;
}