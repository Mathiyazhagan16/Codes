#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
}NODE;
void Create_node(int num,NODE** root)
{
    NODE* newnode=(NODE*)calloc(1,sizeof(NODE));
    NODE* temp;
    NODE* tptr;
    newnode->data = num;
    if(*root==NULL)
    {
        *root = newnode;
    }
    else 
    {
        for(tptr=*root;tptr!=NULL;temp=tptr,tptr=(tptr->data < num)?(tptr->right):(tptr->left));
        if(temp->data > num)
        {
            temp->left = newnode;
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
void preorder(NODE* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left); 
        preorder(root->right);
    }
}
void postorder(NODE* root)
{
    if(root!=NULL)
    {
        postorder(root->left); 
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int Height(NODE* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else 
    {
        int Left_Height = Height(root->left);
        int Right_Height = Height(root->right);
        if(Left_Height < Right_Height)
        {
            return Right_Height+1;
        }
        else 
        {
            return Left_Height+1;
        }
    }
}
void LevelOrder(NODE* root,int level)
{
    if(root == NULL)
    {
        return;
    }
    if(level == 1) 
    {
        printf("%d ",root->data);
    }
    else
    {
        LevelOrder(root->left,level-1);
        LevelOrder(root->right,level-1);
    }
}
int main()
{
    int num;
    NODE* root=NULL;
    do{
        scanf("%d",&num);
        if(num==-1) break;
        Create_node(num,&root);
    }while(num!=-1);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    int h=Height(root);
    for(int itr=1;itr<=h;itr++)
    {
        LevelOrder(root,itr);
    }
}

/* 
        
                     root
                      4
                    /   \ 
                  2       6
                 / \     /  \
                1   3   5    7
                     \        \
                      4         8

input = 4 6 5 7 8 2 3 1 4 -1
inorder = 1 2 3 4 4 5 6 7 8
preorder =4 2 1 3 4 6 5 7 8
postorder = 1 4 3 2 5 8 7 6 4
Level order = 4 2 6 1 3 5 7 4 8


*/
