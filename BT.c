#include<stdio.h>
#include<stdlib.h>
typedef struct node{int data;struct node* left,*right;}NODE;
NODE* create_node(int num)
{
    NODE* newnode = (NODE*)calloc(1,sizeof(NODE));
    newnode->data=num;
    return newnode;
}
void create_tree(int N,NODE** root)
{
    int num,left,right;
    int ind=0;
    int add_new=1;
    scanf("%d",&num);
    NODE* Queue[N];
    *root = create_node(num);
    Queue[ind]=*root;
    N--;
    while(N>0)
    {
        if(N<=0) break;
        scanf("%d",&left);
        Queue[ind]->left = create_node(left);
        Queue[add_new++]=Queue[ind]->left;
        N--;
        if(N<=0) break;
        scanf("%d",&right);
        Queue[ind]->right = create_node(right);
        Queue[add_new++]=Queue[ind]->right;
        ind++;
        N--;
    }
}
void inorder(NODE* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    NODE * root=NULL;
    create_tree(N,&root);
    inorder(root);
}
