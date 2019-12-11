#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * readline();
char * * split_string(char * , char * , int *);

int split(int ar[], int p, int r) {
    int cursor = ar[r];
    int t, j = p;
    for (int k = p;k < r; ++k)
        if (ar[k] <= cursor) {
            t = ar[j], ar[j] = ar[k], ar[k] = t;
            ++j;
        }
    t = ar[j];
    ar[j] = ar[r];
    ar[r] = t;
    return j;
}

void quickSort (int ar[], int cursor, int last){
    while (cursor < last) {
        int j = split(ar, cursor, last);
        if (j - cursor < last - j) {
            quickSort (ar, cursor, j-1);
            cursor = j + 1;
        } else {
            quickSort (ar, j+1, last);
            last = j - 1;
        }
    }
}

int modeArray(int ar_size, const int* ar){
    int mode = 0, max_incidences = 0, cursor = 0;
    while(cursor < (ar_size - max_incidences)){
        int i = cursor;
        int incidences = 0;
        while (ar[cursor] == ar[i]) {
            incidences++;
            i++;
        }
        if (incidences > max_incidences){
            max_incidences = incidences;
            mode = ar[cursor];
        }
        cursor++;
    }
    return mode;
}

float medianArray(int ar_size, const int* ar){
    float median = 0;
    int m = ar_size / 2;
    if (ar_size % 2) median = (float) ar[m];
    else {
        median =(float)(ar[m-1] + ar[m]);
        median = median / 2;
    }
    return median;
}

float meanArray(int ar_size, const int* ar) {
    int index;
    float sum = 0;
    for (index = 0; index < ar_size; index++){
        sum = sum + (float) ar[index];
    }
    return sum / (float) ar_size;
}

int main() {
    int ar_count = readline()[0];
    int * ar = readline();

    quickSort(ar, 0, ar_count-1);
    float mean =  meanArray(ar_count, ar);
    float median = medianArray(ar_count, ar);
    int mode = modeArray(ar_count, ar);
    printf("%.1f\n%.1f\n%d", mean, median, mode);
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

