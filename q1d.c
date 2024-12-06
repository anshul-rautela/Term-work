/*
Alerady sort it in the doubly linked list while inserting 
then perform the needed operaitons
smaller identity no. have greater priority
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node //doubly linked list
{
    int data;
    int identity_no;
    struct node*next,*prev;
} node;

node* createPriorityNode(int data,int ident_no){
    node* p = (node*)malloc(sizeof(node));
    p->next=NULL;
    p->data=data;
    p->identity_no=ident_no;
    p->prev=NULL;
    return p;
}
void display(struct node*n){
    while(n){
        printf("%d-> ",n->data);
        n = n->next;
    }
    printf("NULL\n");
}
void delete(struct node**n){
    struct node*temp = *n;
    *n =(*n)->next;
    free(temp);
}
void insert(node**n,int data,int ident_no){   //o(n) time
    node*temp = createPriorityNode(data,ident_no);
    if((*n) == NULL){ *n = temp; return;}
    if(temp->identity_no < (*n)->identity_no){
        temp->next= *n;
        (*n)->prev=temp;
        (*n=temp);
        display(*n);        
        return ;
    }
    node*it = *n; //iteratror
    while(it->next && it->next->identity_no <= ident_no){
        it = it->next;
    }
        node* nodeNext = it->next;
        temp->next=nodeNext;
        if(nodeNext)  nodeNext->prev=temp;
        temp->prev=it;
        it->next=temp;
}
int main() {
    struct node* n = NULL;  // Initialize the list as empty
    int choice, data, ident_no;
    
    do {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Delete the first node\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the data and identity number (priority): ");
                scanf("%d %d", &data, &ident_no);
                insert(&n, data, ident_no);
                break;
            case 2:
                delete(&n);
                break;
            case 3:
                display(n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}