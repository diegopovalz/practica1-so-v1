#include "../include/user_interaction.h"
#include <stdio.h>
#include <stdlib.h>

int get_node(int node_capacity){
    int node = -1;
    do{
        
        printf("Elige un nodo para analizar [0-%i]\n\t-> ", node_capacity - 1);
        scanf("%d", &node);
    }while(!(node >= 0));
    return node;
}

void loop(int option, int graph[MAX_NODES][MAX_NODES], int node_num){
    graph_print(graph, node_num);
    int looping = 1;
    int start_node = 0;
    while (looping){
        switch (option) {
            case 0:
                printf("Dijkstra con Priority queues: \n");
                start_node = get_node(node_num);
                if(start_node >= node_num) return;
                dijkstra(graph, node_num, start_node);
                break;
            case 1:
                printf("\n\nDijkstra sin Priority queues: \n");
                start_node = get_node(node_num);
                if(start_node >= node_num) return;
                dijkstraNoPQ(graph, node_num, start_node);
                getchar();
                break;
            default:
                printf("Opción incorrecta\n");
                looping = 0;
                break;
        }
    }
}
