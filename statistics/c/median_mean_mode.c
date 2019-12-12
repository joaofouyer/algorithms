#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"
#include "sorting.h"


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


