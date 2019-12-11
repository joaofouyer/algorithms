#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * * split_string(char * , char * , int *);

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
    char * * data = split_string(string, " ", &size);
    char* ar_item_endptr;
    char* ar_item_str = data[0];
    int number = (int)strtol(ar_item_str, &ar_item_endptr, 10);
    if(ar_item_endptr == ar_item_str || *ar_item_endptr != '\0') exit(EXIT_FAILURE);
    return number;
}

int * readArray(char * string, int size) {
    if(fgets(string, size, stdin) != NULL) {
        int lastChar = strlen(string) - 1;
        if(string[lastChar] == '\n') string[lastChar] = '\0';
    }

    char * * data = split_string(string, " ", &size);

    int * arr = malloc(size * sizeof(int));

    for (int ar_itr = 0; ar_itr < size; ar_itr++){
        char* ar_item_endptr;
        char* ar_item_str = data[ar_itr];
        int ar_item = (int)strtol(ar_item_str, &ar_item_endptr, 10);
        if(ar_item_endptr == ar_item_str || *ar_item_endptr != '\0') exit(EXIT_FAILURE);
        arr[ar_itr] = ar_item;
    }
    return arr;
}


double squaredDistance(int number, double mean){
    double delta = mean - number;
    return delta * delta;
}

double deviation(int ar_size, const int * arr, double mean){
    double dev;
    dev = 0;

    for(int i = 0; i < ar_size; i++){
        dev = dev + squaredDistance(arr[i], mean);
    }

    return sqrt((dev / ar_size));
}

double calculateMean(int arr_size, const int * arr) {
    int index;
    double sum = 0;
    for (index = 0; index < arr_size; index++){
        sum = sum + (double) arr[index];
    }
    return sum / (double) arr_size;
}

int main() {
    char size_str[32], numbers_str[1024];
    int size = readInt(size_str, sizeof(size_str));
    int * numbers = readArray(numbers_str, size * (int) sizeof(int));
    double mean = calculateMean(size, numbers);
    double dev = deviation(size, numbers, mean);

    printf("%.1f", dev);
    return 0;

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

