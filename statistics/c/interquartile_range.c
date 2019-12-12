#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sorting.h"
#include "read.h"

float calculateMedian(int size, int m, const int* numbers){
    float median = 0;
    if (size % 2) median = (float) numbers[m];
    else median = (float)(numbers[m-1] + numbers[m]) / (float) 2.0;
    return median;
}

void calculateQuartiles(int ar_size,  const int* numbers, float quartiles[]){
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

int arraySize(int size, int * arr){
    int size_arr = 0;

    for (int i = 0; i< size; i++){
        size_arr = size_arr + arr[i];
    }

    return size_arr;
}

void frequencyArray(int size, const int * numbers, const int * frequencies, int S[]){
    int index = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < frequencies[i]; j++){
            S[index] = numbers[i];
            index++;
        }
    }
}

int main() {
    int size = readline()[0];
    int * numbers = readline();
    int * frequencies = readline();
    float quartiles[3], interquartile_range;
    int size_s = arraySize(size, frequencies);
    int S[size_s];

    frequencyArray(size, numbers, frequencies, S);

    quickSort(S, 0, size_s -1);

    calculateQuartiles(size_s, S, quartiles);

    interquartile_range = quartiles[2] - quartiles[0];

    printf("%.1f", interquartile_range);
    return 0;

}

