#ifndef MAP_H
#define MAP_H

#define MAX_SIZE 32
#define MAX_WORD_SIZE 64

typedef struct Map Map;

/*
 * Creates, initializes and returns a map.
 *
 * Output:
 *  Map* map: a pointer to the created map.
 */
Map* map_create();

/*
 * Appends a key in the given map.
 *
 * Inputs:
 *  Map* map: pointer to the map.
 *  char* key: string which represent the key.
 */
void map_append(Map* map, char* key);

/*
 * Gets the value of the map.
 *
 * Inputs:
 *  Map* map: pointer to the map.
 *  char* key: string which represent the key.
 *
 * Output:
 *  int value: integer of the value.
 *
 */
int map_get(Map* map, char* key);

/*
 * get the key of a given value.
 *
 * Inputs:
 *  Map* map: pointer to the map.
 *  char* key: string which represent the key.
 *
 * Output:
 *  char* key: key linked to the value.
 *
 */
char* map_get_by_val(Map* map, int val);

/*
 * Prints the values of the map.
 *
 * Inputs:
 *  Map* map: pointer to the map.
 *
 */
void map_print(Map* map);

/*
 * Returns the size of the map.
 *
 * Inputs:
 *  Map* map: pointer to the map.
 *
 * Output:
 *  int size: size of the map.
 *
 */
int map_size(Map* map);

#endif//MAP_H
