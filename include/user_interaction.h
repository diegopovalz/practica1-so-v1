#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

#include "./map.h"
#include "./dijkstra.h"
#include "./dijkstra-nopq.h"
#include "../include/utils.h"

int get_node(int node_capacity);
void loop(int option, int graph[MAX_NODES][MAX_NODES], int node_num);

#endif //USER_INTERACTION_H
