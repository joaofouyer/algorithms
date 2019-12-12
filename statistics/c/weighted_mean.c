#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"


float weightedMean(int ar_size, const int* numbers, const int* weights) {
    int index;
    float sum = 0;
    int total = 0;
    for (index = 0; index < ar_size; index++){
        sum = sum + (float) (numbers[index] * weights[index]);
        total = total + weights[index];
    }

    return sum / (float) total;
}

int main() {
    int size = readline()[0];
    int * numbers = readline();
    int * weights = readline();

    float weighted_mean =  weightedMean(size, numbers, weights);

    printf("%.1f\n", weighted_mean);
    return 0;

}

