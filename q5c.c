#include<stdio.h>
#include<stdlib.h>

typedef struct ds {
    int size;
    int* parent;
    int* rank;
} ds;

typedef struct edge {
    int u, v, weight;
} edge;

typedef struct graph {
    int V, E;
    edge* edges;
} graph;

ds* create(int size) {
    ds* n = (ds*)malloc(sizeof(ds));
    n->size = size;
    n->parent = (int*)malloc(sizeof(int) * size);
    n->rank = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        n->parent[i] = i;
        n->rank[i] = 0;
    }
    return n;
}

int find_p(ds* n, int i) {
    if (n->parent[i] != i) 
        n->parent[i] = find_p(n, n->parent[i]);
    return n->parent[i];
}

void unionl(ds* n, int u, int v) {
    int pu = find_p(n, u);
    int pv = find_p(n, v);
    if (pu != pv) {
        if (n->rank[pu] > n->rank[pv]) 
            n->parent[pv] = pu;
        else if (n->rank[pu] < n->rank[pv]) 
            n->parent[pu] = pv;
        else {
            n->parent[pv] = pu;
            n->rank[pu]++;
        }
    }
}

int compare(const void* a, const void* b) {
    return ((edge*)a)->weight - ((edge*)b)->weight;
}

void kruskal(graph* g) {
    qsort(g->edges, g->E, sizeof(edge), compare);
    ds* d = create(g->V);
    int mstWeight = 0;
    printf("Edges in MST:\n");
    for (int i = 0; i < g->E; i++) {
        int u = g->edges[i].u;
        int v = g->edges[i].v;
        if (find_p(d, u) != find_p(d, v)) {
            printf("%d -- %d == %d\n", u, v, g->edges[i].weight);
            mstWeight += g->edges[i].weight;
            unionl(d, u, v);
        }
    }
    printf("Total weight of MST: %d\n", mstWeight);
    free(d->parent);
    free(d->rank);
    free(d);
}

int main() {
    graph* g = NULL;
    int choice, V, E;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Graph\n");
        printf("2. Run Kruskal's Algorithm\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (g) {
                    free(g->edges);
                    free(g);
                }
                printf("Enter number of vertices: ");
                scanf("%d", &V);
                printf("Enter number of edges: ");
                scanf("%d", &E);

                g = (graph*)malloc(sizeof(graph));
                g->V = V;
                g->E = E;
                g->edges = (edge*)malloc(E * sizeof(edge));

                for (int i = 0; i < E; i++) {
                    printf("Enter edge %d (u v weight): ", i + 1);
                    scanf("%d %d %d", &g->edges[i].u, &g->edges[i].v, &g->edges[i].weight);
                }
                break;

            case 2:
                if (g) {
                    kruskal(g);
                } else {
                    printf("Graph not created yet!\n");
                }
                break;

            case 3:
                if (g) {
                    free(g->edges);
                    free(g);
                }
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
