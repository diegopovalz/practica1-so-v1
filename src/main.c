#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "../include/dijkstra.h"
#include "../include/utils.h"

int main(int argc, char** argv) {
	int num_nodes = 6;
    char node_str[MAX_FILE_SIZE];
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

    read_file(argv[1], node_str);

    string_to_map(node_str);

    return 0;
}
