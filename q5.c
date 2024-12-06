#include<stdio.h>
#include<stdlib.h>
typedef struct ds{       //disjoint set
    int size;
    int*parent;
    int*rank;
}ds;

ds*create(int size){       //creating disjoint set;
    ds*n=(ds*)malloc(sizeof(ds));
    n->size=size;
    n->parent=(int*)malloc(sizeof(int)*size);
    n->rank=(int*)malloc(sizeof(int)*size);
    for(int i =0;i<size;i++){
        n->parent[i]=i;
        n->rank[i]=0;
    }
    return n;
}

int find_p(ds*n,int i){        //find parent in disjoint set
    if(n->parent[i]==i)return i;
    return (find_p(n,n->parent[i]));
}

void unionl(ds*n,int u,int v){
    if(find_p(n,u)==find_p(n,v)){
        return;
    }
    if(n->rank[u]>n->rank[v]){
        n->parent[v]=find_p(n,u);
        n->rank[v]++;
    }
    else{
        n->parent[u]=find_p(n,v);
        n->rank[u]++;
    }
}
void kruskal(ds*g){
    
}

int main(){

}