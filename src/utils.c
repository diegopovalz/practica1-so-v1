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
    printf("\n%s\n", dir);
    FILE * file_ptr = fopen(dir, "r");

    // Exits if there is no file
    if (file_ptr == NULL){
        printf("There's not a file to open.\n");
        exit(EXIT_FAILURE);
        return;
    }
    while(fgets(buffer, chunk, file_ptr)){
        strlcat(result, buffer, MAX_FILE_SIZE);
    }
    fclose(file_ptr);
    strlcpy(res, result, MAX_FILE_SIZE);
}

void string_to_map(char* map_str){
    int connections = 0;
    char *token;
    token = strtok(map_str, ";");
    while(token != NULL){
        printf("%s -> %d\n", token, connections);
        token = strtok(NULL, ";");
        connections++;
    }
    printf("%s SIZE %d\n", token, connections);
}
