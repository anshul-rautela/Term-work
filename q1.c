/*
Alerady sort it in the doubly linked list while inserting 
then perform the needed operaitons
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

void insert(node**n,int data,int ident_no){   //o(n) time
    node*temp = createPriorityNode(data,ident_no);
    if((*n) == NULL){ *n = temp; return;}
    if(temp->identity_no < (*n)->identity_no){
        temp->next= *n;
        (*n)->prev=temp;
        (*n=temp);        
        return ;
    }
    node*it = *n; //iteratror

    while(it && it->identity_no <= ident_no){
        it = it->next;
    }
    if(!it){
        node* nodeNext = it->next;
        temp->next=nodeNext;
        nodeNext->prev=temp;
        temp->prev=it;
        it->next=temp;
    }
    
}
