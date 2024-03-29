#include <stdio.h>
#include <math.h>
#include "read.h"

/*
 * Calculates the squared difference between two numbers. In statistics it's used to calculate the distance between
 * a set of numbers and the mean.
 */
double squaredDistance(int number, double mean){
    double delta = mean - number;
    return delta * delta;
}

/*
 * Calculates the deviation of a given set and mean. The deviation is the square root of the sum of the squared
 * distances between all the elements of the set and the mean
 */
double deviation(int ar_size, const int * arr, double mean){
    double dev = 0;

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
    char size_str[32], numbers_str[2048];
    int size = readInt(size_str, sizeof(size_str));
    int * numbers = readArray(numbers_str, 2048);
    double mean = calculateMean(size, numbers);
    double dev = deviation(size, numbers, mean);

    printf("\n%.1f", dev);
    return 0;

}

