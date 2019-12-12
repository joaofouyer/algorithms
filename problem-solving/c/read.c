#include "read.h"

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

char** split_string(char* str, char* delim, int *tokens){
    char** splits = NULL;
    char* token = strtok(str, delim);
    *tokens = 0;
    while(token){
        splits = realloc(splits, sizeof(char*) * ++*tokens);
        if (!splits) return splits;
        splits[*tokens - 1] = token;
        token = strtok(NULL, delim);
    }
    return splits;
}

char* readStdin(char* string, int size) {
    if(fgets(string, size, stdin) != NULL) {
        int lastChar = strlen(string) - 1;
        if(string[lastChar] == '\n') string[lastChar] = '\0';
        return string;
    }
    return NULL;
}

int readInt(char * string, int size) {
    if(fgets(string, size, stdin) != NULL) {
        int lastChar = strlen(string) - 1;
        if(string[lastChar] == '\n') string[lastChar] = '\0';
    }

    return atoi(string);
}

long readLong(char * string, int size) {
    if(fgets(string, size, stdin) != NULL) {
        int lastChar = strlen(string) - 1;
        if(string[lastChar] == '\n') string[lastChar] = '\0';
    }

    return atol(string);
}

int * readArray(char * string, int size) {
    if(fgets(string, size, stdin) != NULL) {
        int lastChar = strlen(string) - 1;
        if(string[lastChar] == '\n') string[lastChar] = '\0';
    }

    char * * data = split_string(string, " ", &size);
    int * arr = malloc(size * sizeof(int));

    for (int ar_itr = 0; ar_itr < size; ar_itr++){
        int ar_item = atoi(data[ar_itr]);
        arr[ar_itr] = ar_item;
    }
    return arr;
}

long * readArrayLong(char * string, int size) {
    if(fgets(string, size, stdin) != NULL) {
        int lastChar = strlen(string) - 1;
        if(string[lastChar] == '\n') string[lastChar] = '\0';
    }

    char * * data = split_string(string, " ", &size);
    long * arr = malloc(size * sizeof(int));

    for (int ar_itr = 0; ar_itr < size; ar_itr++){
        int ar_item = atol(data[ar_itr]);
        arr[ar_itr] = ar_item;
    }
    return arr;
}