#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "../include/dijkstra.h"
#include "../include/dijkstra-nopq.h"
#include "../include/utils.h"
#include "../include/user_interaction.h"
#include "../include/map.h"

int main(int argc, char** argv) {
    if (argc != 3){
        printf("La cantidad de argumentos necesarios es incorrecta.\n");
        printf("El modo de uso es el siguiente:\n");
        printf("\t./build/first_practice <dir> <no_queue>\n");
        printf("donde <dir> es un directorio y <no_queue> es '0' o '1'.\n");
        return -1;
    }

    char node_str[MAX_FILE_SIZE];
    char* relations[MAX_NODES*(MAX_NODES-1)/2];
    Map* node_name = map_create();
    int num_relations = 0;
    int graph[MAX_NODES][MAX_NODES] = {0};
    int directed;

    read_file(argv[1], node_str);
    string_splitting(node_str, relations, &num_relations, &directed);
    create_map_and_node(node_name, graph, relations, num_relations, directed);
    loop(atoi(argv[2]), graph, map_size(node_name));

    free(node_name);
    return 0;
}
