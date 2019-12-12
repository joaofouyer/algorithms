#include "sorting.h"


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


void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void quickSort(int ar[], int cursor, int last){
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


void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void selectionSort(int arr[], int n){
    int i, j, min_idx;
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}


void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}


void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


void shellSort(int arr[], int n){
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i += 1){
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}


//void partition(int a[], int l, int r, int * i, int * j){
//    *i = l-1;
//    *j = r;
//    int p = l-1, q = r;
//    int v = a[r];
//
//    while (1){
//        while (a[++*i] < v);
//        while (v < a[--*j])
//            if (j == l)
//                break;
//        if (i >= j) break;
//        swap(&a[*i], &a[*j]);
//        if (a[*i] == v){
//            p++;
//            swap(&a[p], &a[*i]);
//        }
//        if (a[*j] == v){
//            q--;
//            swap(&a[*j], &a[q]);
//        }
//    }
//    swap(&a[*i], &a[r]);
//
//    *j = *i-1;
//    for (int k = l; k < p; k++, j--)
//        swap(&a[k], &a[*j]);
//    i = i+1;
//    for (int k = r-1; k > q; k--, i++)
//        swap(&a[*i], &a[k]);
//}
//
//
//void quick3Sort(int a[], int l, int r){
//    if (r <= l) return;
//    int i, j;
//    partition(a, l, r, &i, &j);
//    quick3Sort(a, l, j);
//    quick3Sort(a, i, r);
//}