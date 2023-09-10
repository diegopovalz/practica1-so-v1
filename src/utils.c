#include "../include/utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <string.h>

void read_file(char* dir, char* res){
    int chunk = 16;
    char buffer[chunk];
    char result[MAX_FILE_SIZE];
    FILE * file_ptr = fopen(dir, "r");

    // Exits if there is no file
    if (file_ptr == NULL){
        printf("There's not a file to open.\n");
        exit(EXIT_FAILURE);
        return;
    }
    while(fgets(buffer, chunk, file_ptr))
        strlcat(result, buffer, MAX_FILE_SIZE);
    fclose(file_ptr);
    strlcpy(res, result, MAX_FILE_SIZE);
}

void string_splitting(char* init_str, char* string_list[MAX_NODES*(MAX_NODES-1)/2], int* substr_amount, int* directed) {
    char* token;    // Substring from the splitted initial string
    char* aux;      // Aux variable
    int amount;     // How many sub strings there are
    int size;       // Used as counter and limit

    char is_directed[5];
    char *newline = strchr(init_str, '\n');
    if (newline != NULL) {
        int length = newline - init_str;
        strlcpy(is_directed, init_str, length + 1);
        is_directed[length] = '\0';
        *directed = (strcmp(is_directed, "false") == 0) ? 0 : 1;
        length = strlen(init_str);
        strlcpy(init_str, newline + 1, length + 1); // Skip first line
    }

    /*
     * This portion of code can improve, but idk how to do it at the moment
     */
    size = 0;
    while(1){
        if(init_str[size] == '\n'){
            init_str[size] = '\0';
            break;
        }
        size++;
    }
    token = strtok(init_str, ";");
    amount = 0;
    while(token != NULL){ // Splitting the string and saving splits in the list
        size = strlen(token);
        if(size < 0) return;
        string_list[amount] = (char*) malloc(size);
        strlcpy(string_list[amount], token, size);
        token = strtok(NULL, ";");
        amount++;
    }
    for(int i = 0; i < amount; i++){ // removing the initial parenthesis
        if(string_list[i][1] == '(') aux = string_list[i] + 2;
        else aux = string_list[i] + 1;
        string_list[i] = aux;
    }
    *substr_amount = amount;
}

void create_map_and_node(Map* map, int graph[MAX_NODES][MAX_NODES], char* connections[MAX_NODES*(MAX_NODES-1)/2], int num_rel, int directed) {
    char* token;    // Substring from the relation
    char aux[MAX_WORD_SIZE];      // Aux variable
    int weight;     // Aux variable
    int value[2];

    for (int i = 0; i < num_rel; i++){
        strlcpy(aux, connections[i], MAX_WORD_SIZE);
        token = strtok(aux, ",");
        for(int i = 0; i < 2; i++){
            map_append(map, token);
            value[i] = map_get(map, token);
            token = strtok(NULL, ",");
        }
        weight = atoi(token);
        graph[value[0]][value[1]] = weight;
        if (!directed) graph[value[1]][value[0]] = weight;
    }
    map_print(map);
}

void graph_print(int graph[MAX_NODES][MAX_NODES], int size){
    printf("Adjacency matrix:\n  ");
    for(int i = 0; i < size;i++) printf("\t%i", i);
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%i ", i);
        for(int j = 0; j < size; j++) printf("\t%i ", graph[i][j]);
        printf("\n");
    }
    printf("\n");
}
