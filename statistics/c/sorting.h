#ifndef ALGORITHMS_SORTING_H
#define ALGORITHMS_SORTING_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int split(int[], int, int);
void swap(int *, int *);
void heapify(int [], int, int);

void merge(int [], int, int, int);
void quickSort (int[], int, int);
void mergeSort(int[], int, int);
void heapSort(int[], int);
void shellSort(int[], int);

void insertionSort(int[], int);
void selectionSort(int[], int);
void bubbleSort(int[], int);

void quick3Sort (int[], int, int);

#endif //ALGORITHMS_SORTING_H
