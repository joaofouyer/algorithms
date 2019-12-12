#include "read.h"

void compareArrays(const int array1[], const int array2[], int size, int result[]){
    result[0] = 0;
    result[1] = 0;
    for (int i = 0; i < size; i++){
        if (array1[i] > array2[i])
            result[0]++;
        else if (array2[i] > array1[i])
            result[1]++;
    }
}

int main(){
    int * alice = readline();
    int * bob = readline();

    int result[2];

    compareArrays(alice, bob, 3, result);
    printf("%d %d", result[0], result[1]);

    return 0;
}