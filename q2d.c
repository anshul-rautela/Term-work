#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int empid;
    char empname[100];
    struct node*next;
}node;

struct node*create(int data,char s[]){
    struct node*n = (struct node*)malloc(sizeof(struct node));
    n->empid=data;
    int i =0;
    while(s[i]!='\0'){
        n->empname[i]=s[i];
        i++;
    }
    n->empname[i]='\0';
    n->next=NULL;
    return n;
}
void insertEnd(node**ll,int data,char s[]){
     node*temp = create(data,s);
    if(*ll==NULL){
        *ll=temp;
        return;
    }
     node*iter=*ll;//iterator
    while(iter->next){
        iter = iter->next;
    }
    iter->next=temp;
}
void display(struct node*ll){
    if(!ll) printf("list is empty\n");
    struct node*iter=ll;//iterator
    while(iter){
        printf("%d,",iter->empid);
        printf("%s -> ",iter->empname);
        iter = iter->next;
    }
    printf("NULL\n");
}
int exists(node*head,int data){
    while(head){
        if(head->empid==data) return 1;
        head = head->next;
    }
    return 0;
}
void unionl(node*list1,node*list2){
    node*temp1=list1;
    node*temp2=list2;
    node*unionlist=NULL;
    while(list1){
        if(!exists(unionlist,list1->empid)){
            insertEnd(&unionlist,list1->empid,list1->empname);
        }list1=list1->next;
    }while(list2){
        if(!exists(unionlist,list2->empid)){
            insertEnd(&unionlist,list2->empid,list2->empname);
        }list2=list2->next;
    }
    display(unionlist);    
}int main() {
    node* l1 = NULL;
    node* l2 = NULL;
    int choice, id;
    char name[100];

void menu() {
    printf("Menu:\n");
    printf("1. Insert into List 1\n");
    printf("2. Insert into List 2\n");
    printf("3. Display List 1\n");
    printf("4. Display List 2\n");
    printf("5. Union of List 1 and List 2\n");
    printf("6. Exit\n");
}
    while (1) {
        printf("Enter your choice: ");
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter empid for List 1: ");
                scanf("%d", &id);
                printf("Enter empname for List 1: ");
                scanf(" %[^\n]", name);  // to read the entire line with spaces
                insertEnd(&l1, id, name);
                break;

            case 2:
                printf("Enter empid for List 2: ");
                scanf("%d", &id);
                printf("Enter empname for List 2: ");
                scanf(" %[^\n]", name);  // to read the entire line with spaces
                insertEnd(&l2, id, name);
                break;

            case 3:
                printf("Displaying List 1:\n");
                display(l1);
                break;

            case 4:
                printf("Displaying List 2:\n");
                display(l2);
                break;

            case 5:
                printf("Union of List 1 and List 2:\n");
                unionl(l1, l2);
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}