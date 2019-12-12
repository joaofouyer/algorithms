#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"
#include "sorting.h"


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


