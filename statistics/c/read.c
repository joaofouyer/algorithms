#include "read.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * readline();
char * * split_string(char * , char * , int *);

int main() {
    int ar_count = readline()[0];
    int * ar = readline();
    printf("%d \n", ar_count);
    for (int i = 0; i < ar_count; i++){
        printf("%d", ar[i]);
    }
    return 0;
}

int * readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data_str = malloc(alloc_length);
    char** data;
    int size = 0;
    while(1){
        char* cursor = data_str + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) break;
        data_length += strlen(cursor);
        if (data_length <  alloc_length -1 || data_str[data_length - 1] == '\n') break;
        size_t new_length = alloc_length << 1u;
        data_str = realloc(data_str, new_length);
        if (!data_str) break;
        alloc_length = new_length;
    }
    if (data_str[data_length - 1] == '\n') data_str[data_length - 1] = '\0';
    data_str = realloc(data_str, data_length);

    data = split_string(data_str, " ", &size);

    int * data_array = malloc(size * sizeof(int));

    for (int ar_itr = 0; ar_itr < size; ar_itr++){
        char* ar_item_endptr;
        char* ar_item_str = data[ar_itr];
        int ar_item = (int)strtol(ar_item_str, &ar_item_endptr, 10);
        if(ar_item_endptr == ar_item_str || *ar_item_endptr != '\0') exit(EXIT_FAILURE);
        data_array[ar_itr] = ar_item;
    }
    return data_array;
}

char** split_string(char* str, char* delim, int *spaces){
    char** splits = NULL;
    char* token = strtok(str, delim);
    *spaces = 0;
    while(token){
        splits = realloc(splits, sizeof(char*) * ++*spaces);
        if (!splits) return splits;
        splits[*spaces - 1] = token;
        token = strtok(NULL, delim);
    }
    return splits;
}
