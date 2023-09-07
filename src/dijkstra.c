#include "../include/dijkstra.h"
#include "../include/pq.h"
#include <float.h>
#include <stdio.h>

void dijkstra(int graph[MAX_NODES][MAX_NODES], int num_nodes, int start_node){
    double distance[MAX_NODES];
    int parent[MAX_NODES];
    PQ* pq = pq_create(num_nodes, 1); // Min heap

    for (int i = 0; i < num_nodes; i++) {
        distance[i] = DBL_MAX;
        parent[i] = -1;
        pq_insert(pq, i, distance[i]);
    }

    distance[start_node] = 0;
    pq_change_priority(pq, start_node, distance[start_node]);

    while (pq_size(pq) > 0) {
        int u, id;
        double dist;
        pq_delete_top(pq, &id, &dist);
        u = id;

        for (int v = 0; v < num_nodes; v++) {
            if (graph[u][v] > 0) {
                double alt = distance[u] + graph[u][v];
                if (alt < distance[v]) {
                    distance[v] = alt;
                    parent[v] = u;
                    pq_change_priority(pq, v, distance[v]);
                }
            }
        }
    }

    pq_free(pq);

    // Print results
    printf("Nodo\tDistancia\tAnterior\n");
    for (int i = 0; i < num_nodes; i++) {
        if(parent[i] < 0 && i != start_node) printf("%d\tinfinito\t%d\n", i, parent[i]);
        else printf("%d\t%f\t%d\n", i, distance[i], parent[i]);
    }
}
