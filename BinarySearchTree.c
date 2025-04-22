#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    int data;
    struct node* Left;
    struct node* Right;
}NODE;
void Create_Node(int num,NODE** root)
{
    NODE * newnode = (NODE* )calloc(1,sizeof(NODE));
    newnode->data = num;
    if(*root==NULL)
    {
        *root = newnode;
    }
    else 
    {
        NODE* tptr = *root;
        NODE * temp;
        // for(tptr=*root;tptr;temp=tptr,tptr=((tptr->data > num)?(tptr->Left):(tptr->Right)));
        // (temp->data > num)?(temp->Left = newnode):(temp->Right=newnode);
        while(tptr!=NULL)
        {
            temp=tptr;
            if(tptr->data > num)
                tptr=tptr->Left;
            else 
                tptr=tptr->Right;
        }
        if(temp->data > num)
            temp->Left = newnode;
        else 
            temp->Right = newnode;
    }
}
void Inorder(NODE* root)
{
    if(root!=NULL)
    {
        Inorder(root->Left);
        printf("%d ",root->data);
        Inorder(root->Right);
    }
}
void Preorder(NODE* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        Preorder(root->Left);
        Preorder(root->Right);
    }
}
void Postorder(NODE* root)
{
    if(root!=NULL)
    {
        Postorder(root->Left);
        Postorder(root->Right);
        printf("%d ",root->data);
    }
}
int main()
{
    NODE* root=NULL;
    int num;
    do 
    {
        scanf("%d",&num);
        if(num==-1) break;
        Create_Node(num,&root);
    }while(num!=-1);
    printf("Inorder : ");
    Inorder(root);
    printf("\n");
    printf("Preorder : ");
    Preorder(root);
    printf("\n");
    printf("Postorder : ");
    Postorder(root);
    return 0;
}