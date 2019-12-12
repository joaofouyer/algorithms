#include <stdio.h>
#include <stdlib.h>
#define MAX 64

int main() {
    char buffer[MAX];
    double meal_cost = (double) atof(fgets(buffer, MAX, stdin));
    double tip_percent = (double) atof(fgets(buffer, MAX, stdin));
    double tax_percent = (double) atof(fgets(buffer, MAX, stdin));
    double total_cost = meal_cost + (meal_cost * tip_percent / 100) + (meal_cost * tax_percent / 100);

    printf("\n%.0f",total_cost);

    return 0;
}