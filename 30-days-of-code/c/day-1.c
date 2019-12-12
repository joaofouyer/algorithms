#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

int main() {
    int i = 4, j;
    double d = 4.0, e;
    char s[] = "42 ";
    char buf[MAX];

    scanf("%d\n", &j);
    e = (double) atof(fgets(buf, MAX, stdin));
    scanf("%[^\n]", buf);

    printf("%d", i + j);
    printf("\n%.1f", d + e);
    printf("\n%s%s", s, buf);

    return 0;
}