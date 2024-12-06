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
    else if((*root)->data>data){
        if((*root)->left==NULL){ (*root)->left=n; return;}
        else insert(&(*root)->left,data);
    }
    else if((*root)->data<data){
        if((*root)->right==NULL){ (*root)->right=n; return;}
        else insert(&(*root)->right,data);
    }
    else{
        printf("Invalid input: Can't have 2 equal nodes in a B.S.T");
        exit(0);
    }
}
void findSmallest(struct node*root){
    if(root==NULL){printf("Tree is empty\n");return;}
    while(root->left){
        root = root->left;
    }
    printf("The node with smallest value is %d\n",root->data);
}
int findHeight(struct node*root){
    if(root==NULL)return 0;
    int ltree=findHeight(root->left);
    int rtree=findHeight(root->right);
    return ((ltree>rtree?ltree:rtree) +1);
}
void display(struct node*root){
    if(root==NULL) return;
    display(root->left);
    printf("%d ",root->data);
    display(root->right);
}
int countNodes(struct node*root){
    if(root==NULL) return 0;
    return (countNodes(root->left)+countNodes(root->right)+1);
}
int main() {
    struct node* tree = NULL;
    int choice, data;
    
    while(1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Find the smallest node\n");
        printf("3. Find the height of the tree\n");
        printf("4. Display tree (Inorder Traversal)\n");
        printf("5. Count the number of nodes\n");
        printf("6. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insert(&tree, data);
                break;
                
            case 2:
                findSmallest(tree);
                break;
                
            case 3:
                printf("The height of the tree is: %d\n", findHeight(tree));
                break;
                
            case 4:
                printf("Inorder Traversal: ");
                display(tree);
                printf("\n");
                break;
                
            case 5:
                printf("Number of nodes from right hand side of root in the tree: %d\n", countNodes(tree->right));
                break;
                
            case 6:
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}