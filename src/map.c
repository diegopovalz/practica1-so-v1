#include "../include/map.h"
#include <stdlib.h>
#include <bsd/string.h>
#include <stdio.h>
#include <string.h>

struct Map {
    int size;
    char keys[MAX_SIZE][MAX_WORD_SIZE];
};

int map_or_key_are_null(Map* map, char* key){
    if (map == NULL) printf("Given map is a NULL value");
    else if (key == NULL) printf("Given string is a NULL value %s", key);
    else return 0;
    return 1;
}

Map* map_create(){
    struct Map* map = (Map *) malloc(sizeof(struct Map));
    map->size = 0;
    return map;
}

void map_append(Map* map, char* key){
    if(map_or_key_are_null(map, key)) return;
    if(map_get(map, key) == -1){
        strlcpy(map->keys[map->size], key, MAX_WORD_SIZE);
        map->size++;
    }
}

int map_get(Map * map, char* key){
    if(map_or_key_are_null(map, key)) return -1;
    for(int i = 0; i < map->size; i++)
        if(strcmp(map->keys[i], key) == 0) return i;
    return -1;
}

char* map_get_by_val(Map* map, int val){
    return map->keys[val];
}

void map_print(Map* map){
    if (map == NULL){
        printf("Given map is a NULL value");
        return;
    }
    char* del = ", ";
    printf("(");
    for(int i = 0; i < map->size; i++){
        printf("%s: %d%s", map->keys[i], i, del);
        if(i == map->size - 2) del = "";
    }
    printf(")\n");
}

int map_size(Map* map){
    return map->size;
}
