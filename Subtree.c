#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * right;
    struct node * left;
}NODE;
void BST(int data,NODE** root)
{
    NODE * newnode = (NODE*) calloc(1,sizeof(NODE));
    NODE* tptr,*temp;
    newnode->data = data;
    if(*root == NULL)
        *root = newnode;
    else 
    {
        for(tptr = *root ; tptr ; temp = tptr , tptr = (data < tptr->data)?(tptr->left):(tptr->right));
        (temp->data > data)?(temp->left = newnode):(temp->right = newnode);
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
int Check_Sub_Tree(NODE* root1,NODE* root2)
{
    if(root1 == NULL && root2==NULL)
        return 1;
    if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
        return 0;
    if(root1->data != root2->data)
        return 0;
    return Check_Sub_Tree(root1->left,root2->left) && Check_Sub_Tree(root1->right,root2->right);
}
void search(NODE* root1, NODE * root2)
{
    NODE * tptr;
    for(tptr = root1 ; tptr && tptr->data != root2->data;tptr = (root2->data < tptr->data)?(tptr->left):(tptr->right));
    printf("%d %d",tptr->data , root2->data);
    printf("%s",(Check_Sub_Tree(tptr,root2))?"Yes":"No");
}
int main()
{
    int num;
    NODE * root1=NULL,* root2=NULL;
    do 
    {
        scanf("%d",&num);
        if(num==-1) break;
        BST(num,&root1);
    }while(num!=-1);
    do 
    {
        scanf("%d",&num);
        if(num==-1) break;
        BST(num,&root2);
    }while(num!=-1);
    inorder( root1 );
    printf("\n");
    inorder( root2 );
    printf("\n");
    search(root1,root2);
    return 0;
}