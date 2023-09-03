#include <stdbool.h>
#include <float.h>
#include <stdio.h>
#include "../include/dijkstra-nopq.h"

int minDistance(double dist[], bool sptSet[], int num_nodes) {
  double min = DBL_MAX;
  int min_index;

  for (int v = 0; v < num_nodes; v++) {
      if (!sptSet[v] && dist[v] < min) {
          min = dist[v];
          min_index = v;
      }
  }

  return min_index;
}

void dijkstraNoPQ(int graph[MAX_NODES][MAX_NODES], int num_nodes, int start_node) {
  double dist[MAX_NODES]; // Array to store the shortest distances
  bool sptSet[MAX_NODES]; // Set to keep track of visited nodes
  int parent[MAX_NODES]; // Array to store parent nodes for constructing the path

  // Initialize distance, sptSet, and parent arrays
  for (int i = 0; i < num_nodes; i++) {
      dist[i] = DBL_MAX;
      sptSet[i] = false;
      parent[i] = -1;
  }

  // Distance from the start node to itself is always 0
  dist[start_node] = 0;

  // Find shortest path for all nodes
  for (int count = 0; count < num_nodes - 1; count++) {
      int u = minDistance(dist, sptSet, num_nodes);
      sptSet[u] = true;

      // Update dist[] values for adjacent vertices
      for (int v = 0; v < num_nodes; v++) {
          if (!sptSet[v] && graph[u][v] && dist[u] != DBL_MAX && dist[u] + graph[u][v] < dist[v]) {
              dist[v] = dist[u] + graph[u][v];
              parent[v] = u;
          }
      }
  }

  printf("Nodo\tDistancia\tAnterior\n");
  for (int i = 0; i < num_nodes; i++) {
    if(parent[i] < 0 && i != start_node) printf("%d\tinfinito\t%d\n", i, parent[i]);
    else printf("%d\t%f\t%d\n", i, dist[i], parent[i]);
  }
}