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

int calculateMedian(int size, int m, const int* numbers){
    int median = 0;
    if (size % 2) median = (int) numbers[m];
    else median = (int)(numbers[m-1] + numbers[m]) /  2;
    return median;
}

void calculateQuartiles(int ar_size,  const int* numbers, int quartiles[]){
    int m;
    int m1 = ar_size / 2;
    m = m1;
    quartiles[1] = calculateMedian(ar_size, m, numbers);

    if (ar_size % 2){
        ar_size = ar_size - m1 - 1;
        m = m1 + ar_size / 2 + 1;
    }
    else {
        ar_size = ar_size - m1;
        m = m1 + ar_size / 2;

    }
    quartiles[2] = calculateMedian(ar_size, m, numbers);

    m = ar_size / 2;
    quartiles[0] = calculateMedian(ar_size, m, numbers);

}

int main() {
    int size = readline()[0];
    int * numbers = readline();
    int quartiles[3];
    quickSort(numbers, 0, size-1);
    calculateQuartiles(size, numbers, quartiles);
    printf("%d\n%d\n%d", quartiles[0], quartiles[1], quartiles[2]);
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

