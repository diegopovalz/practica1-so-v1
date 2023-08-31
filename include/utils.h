#ifndef UTILS_H
#define UTILS_H

#define MAX_FILE_SIZE 1024 // macro which restrics max file size.
#include "../include/dijkstra.h"
#include "../include/map.h"

/*
Reads a file from a given URL and copies its content in another varible.

Input:
    char* dir: a string with the direction of the file.
    char* content: string that is going to save the read content.
 */
void read_file(char* dir, char *res);

/*
Splits a string in substrings, the initial string must be a sequence of tuples
delimited by ';'. For example: (a,c);(a,b,n,t);(12,665,76)
    
Its has no output, parameters are by reference though.

Input:
    char* init_str: string to be splitted.
    char* string_list[]: string that is going to save substrings.
    int* substr_amount: resulting amount of substrings.
 */
void string_splitting(char* init_str, char* string_list[MAX_NODES*(MAX_NODES-1)/2], int* substr_amount);

/*
Receives a list of relations as strings, make a map of the elements
and build a adj matrix to represent the node.
Each string in the list must have the next format: (Origin,Destination,weight).

It hasn't output, but parameters are by reference.

Input:
    Map* map: struct Map wich saves original names and relates each one to a number.
    int graph[][]: adj matrix which will save graph relations.
    char* connections[]: string which saves all the connections.
    int num_rel: amount of relations.
 */
void create_map_and_node(Map* map, int graph[MAX_NODES][MAX_NODES], char* connections[MAX_NODES*(MAX_NODES-1)/2], int num_rel);

void graph_print(int graph[MAX_NODES][MAX_NODES], int size);

#endif//UTILS_H
