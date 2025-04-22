#include<stdio.h>
#include<stdlib.h>
typedef struct node{int data;struct node* left,*right;}NODE;
NODE* create_node(int num,NODE** root)
{
    NODE* newnode = (NODE*)calloc(1,sizeof(NODE));
    newnode->data=num;
    if(*root==NULL)
    {
        *root=newnode;
    }
    else
    {
        NODE* tptr=*root;
        NODE* temp;
        while(tptr!=NULL)
        {
            temp=tptr;
            if(tptr->data > num)
            {
                tptr=tptr->left;
            }
            else 
            {
                tptr=tptr->right;
            }
        }
        if(temp->data < num)
        {
            temp->right = newnode;
        }
        else 
        {
            temp->right = newnode;
        }
    }
}
void inorder(NODE* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main()
{
    int num;
    NODE* root=NULL;
    do
    {
        scanf("%d",&num);
        if(num==-1) break;
        create_node(num,&root);
    }while(num!=-1);
    inorder(root);
}
