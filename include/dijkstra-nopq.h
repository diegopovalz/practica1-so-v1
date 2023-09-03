#ifndef DIJKSTRA_NOPQ_H
#define DIJKSTRA_NOPQ_H

# define MAX_NODES 20

void dijkstraNoPQ(int graph[MAX_NODES][MAX_NODES], int num_nodes, int start_node);
int minDistance(double dist[], bool sptSet[], int num_nodes);

#endif //DIJKSTRA_NOPQ_H