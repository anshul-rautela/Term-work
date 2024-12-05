#include<stdio.h>
#include<stdlib.h>
typedef struct ll{    //Linked-List;
    int data;
    int weight;
    struct ll*next;
}ll;

typedef struct graph{
    struct  ll**arr;    //array for stroing graph nodes
    int size;  //size of array
}graph;

ll*createLLNode(int data,int wt){
   ll*l = (ll*)malloc(sizeof(ll));
   l->data=data;
   l->next=NULL;
   l->weight=wt;
   return l;
}
graph*createGraph(int size){
    graph*g = (graph*)malloc(sizeof(graph));
    g->arr=(ll**)malloc(sizeof(ll*) *size);
    for (int i = 0; i < size; i++) {
        g->arr[i] = NULL;
    }
    g->size=size;
    return g;
}
void addEdge(graph*g, int u,int v,int wt){
    if(u>=g->size||v>=g->size){
       printf("Cannot add edge greater than or equal to size of graph %d in a 0-based indexing graph\n",g->size);
       return;
    }
    ll*temp=g->arr[u];
    g->arr[u]=createLLNode(v,wt);
    g->arr[u]->next=temp;
    
    temp=g->arr[v];
    g->arr[v]=createLLNode(u,wt);
    g->arr[v]->next=temp;
}
void showGraph(graph*g){
    printf("Edge1: (Edge1,Weight),(Edge2,Weight), and so on...");
    for(int i =0;i<g->size;i++){
        printf("%d: ",i);
        ll*temp = g->arr[i];
        while(temp){
            printf("(%d,%d), ",temp->data,temp->weight);
            temp= temp->next;
        }
        printf("\n");
    }
}

int main(){
    int size;
    printf("Enter the size of the graph\n");
    scanf("%d",&size);
    graph*g = createGraph(size);
    int choise=9;
    do{
        printf("Enter:\n1. To add edge in graph\n2. To Show graph\n3.To Exit\n");
        scanf("%d",&choise);
        switch (choise)
        {   case 1:
                printf("Enter the 2 connected vertices\n");
                int u,v,wt;
                scanf("%d%d",&u,&v);
                printf("Enter the weight of the edge\n");
                scanf("%d",&wt);
                addEdge(g,u,v,wt);
                break;
            case 2:
                showGraph(g);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }while(1);
}
