#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "../include/dijkstra.h"
#include "../include/utils.h"
#include "../include/map.h"

int main(int argc, char** argv) {
    // Original
    int start_node = 0;
	int num_nodes = 6;
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 2, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 3, 0, 0},
        {0, 0, 0, 0, 2, 4},
        {0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0}
    };
    dijkstra(graph, num_nodes, start_node);
    printf("\n\n");


    // try of read the file.
    char node_str[MAX_FILE_SIZE];
    char* relations[MAX_NODES*(MAX_NODES-1)/2];
    Map* node_name = map_create();
    int num_relations = 0;
    int graph2[MAX_NODES][MAX_NODES] = {0};


    read_file(argv[1], node_str);
    string_splitting(node_str, relations, &num_relations);
    create_map_and_node(node_name, graph2, relations, num_relations);
    graph_print(graph2, map_size(node_name));

    dijkstra(graph2, map_size(node_name), start_node);

    free(node_name);
    return 0;
}
