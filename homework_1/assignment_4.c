#include <stdio.h>

int main() {
    int n = 10;

    int *pointer = &n;
    int **double_pointer = &pointer;

    printf("Value using pointer: %d\n", *pointer);
    printf("Value using double-pointer: %d\n", **double_pointer);

    return 0;
}
