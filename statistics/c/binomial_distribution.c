#include <stdio.h>
#include "read.h"
#define MAX 1024


long fatorial(int n){
    long number = 1;
    for (;n > 1; n--){
        number = number * n;
    }
    return number;
}


long double expoent(double b, double e){
    long double number = 1;
    for (int i = 1; i <= e; i++){
        number = number * b;
    }
    return number;
}


double ratio(double b, double g){
    return b / (b + g);
}


double combination(int x, int n){
    long result = 1;
    int difference = n - x;

    while (n > x){
        result = result * n;
        n--;
    }
    return (double) result / (double) fatorial(difference);
}


long double binomial(int x, int n, double p){
    double q = 1 - p;
    double c = combination(x, n);
    return c * (long double) expoent(p, x) * (long double) expoent(q, (n-x));
}


int main() {
    char buffer[MAX];
    int n = 6;
    double * arr = readDoubleArray(buffer, MAX);
    double boys = arr[0];
    double girls = arr[1];
    double p = ratio(boys, girls);
    long double result = 0;
    for(int x = 3; x <= 6; x++){
        result = result + binomial(x, n, p);
    }

    printf("%1.3Lf", result);
    return 0;
}

