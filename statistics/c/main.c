#include "sorting.h"

int main(){
    int array[5];
    array[0] = 5;
    array[1] = 4;
    array[2] = 3;
    array[3] = 2;
    array[4] = 1;
    for (int i = 0; i < 5; i++){
        printf("%d ", array[i]);
    }

    shellSort(array, 5);
    printf("\n");
    for (int i = 0; i < 5; i++){
        printf("%d ", array[i]);
    }
    return 0;
}