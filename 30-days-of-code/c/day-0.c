#include <stdio.h>

int main() {
    char input_string[105];
    scanf("%[^\n]", input_string);
    printf("Hello, World.\n%s", input_string);
    return 0;
}
