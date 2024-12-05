#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left,*right;
};

struct node*create(int data){
    struct node*n = (struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
}
void insert(struct node**root,int data){
    struct node*n = create(data);
    if(*root==NULL){
        *root = n;
        return;
    } 
    if((*root)->data>data){
        if((*root)->left==NULL){ (*root)->left=n; return;}
        else insert(root,data);
    }
    else if((*root)->data<data){
        if((*root)->right==NULL){ (*root)->right=n; return;}
        else insert(root,data);
    }
    else{
        printf("Invalid input: Can't have 2 equal nodes in a B.S.T");
        exit(0);
    }
}
void display(struct node*root){
    if(root==NULL) return;
    display(root->left);
    printf("%d ",root->data);
    display(root->right);
}
int main(){
    struct node*tree = create(1);
    insert(&tree,2);
    insert(&tree,2);
    
    display(tree);
}