#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*create(int data){
    struct node*n = (struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->next=NULL;
}
void insertEnd(struct node**ll,int data){
    struct node*temp = create(data);
    if(*ll==NULL){
        *ll=temp;
        return;
    }
    struct node*iter=*ll;//iterator
    while(iter->next){
        iter = iter->next;
    }
    iter->next=temp;
}
void display(struct node*ll){
    if(!ll) printf("list is empty\n");
    struct node*iter=ll;//iterator
    while(iter){
        printf("%d->",iter->data);
        iter = iter->next;
    }
    printf("NULL\n");
}
void split(struct node*ll){
    if(ll==NULL){ printf("list is empty"); return;}
    int pos =1;
    struct node*oddTail;
    struct node*evenTail;
    struct node*oddHead=NULL;
    struct node*evenHead=NULL;
    while(ll){
        if(pos%2!=0){
            if(pos==1){
                oddTail=create(ll->data);
                oddHead=oddTail;                
            }
            else{
                oddTail->next = create(ll->data);
                oddTail=oddTail->next;
            }
            }
        else{
            if(pos==2){
                evenTail=create(ll->data);
                evenHead=evenTail;                
            }
            else{
                evenTail->next = create(ll->data);
                evenTail=evenTail->next;
            }
        }
        pos++;
        ll = ll->next;
    }
    printf("Odd positions Linked list:\n");
    display(oddHead);
    printf("Even positions Linked list:\n");
    display(evenHead);
}
int main(){
    struct node*ll=NULL;
    int choice;
do {
    printf("Enter:\n1. Insert into linked list\n2. Split linked list\n3. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the linked list, -1 to end\n");
            while (1) {
                int value;
                scanf("%d", &value);
                if (value == -1) break;
                insertEnd(&ll, value);
            }
            break;
        case 2:
            split(ll);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid input.\n");
    }
} while (choice != 3);

}
// traverse a linked list with pos variable (which calculates the position of node) keep incrementing the pos as we traverse the Linked list if pos is odd then add the courent node's data to oddList else add to Evenlist