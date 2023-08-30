#ifndef UTILS_H
#define UTILS_H

#define MAX_FILE_SIZE 1024 // macro which restrics max file size.

/*
Reads a file from a given URL and copies its content in another varible.

Input:
    char* dir: a string with the direction of the file.
    char* content: string that is going to save the read content.
 */
void file_reader(char* dir, char *res);

void string_to_map(char* map_str);

#endif//UTILS_H
