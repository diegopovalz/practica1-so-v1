#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "pq.h"

#define MAX_NODES 20

void dijkstra(int graph[MAX_NODES][MAX_NODES], int num_nodes, int start_node) {
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
    printf("Vertex\tDistance\tParent\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d\t%f\t%d\n", i, distance[i], parent[i]);
    }
}

int main() {
	int num_nodes = 6;
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 2, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 3, 0, 0},
        {0, 0, 0, 0, 2, 4},
        {0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0}
    };
    int start_node = 0;

    dijkstra(graph, num_nodes, start_node);

    return 0;
}