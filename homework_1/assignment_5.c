#include <stdio.h>

int main() {
    char string[] = "Hello";
    char *pointer = string;
    printf("String: ");
    while (*pointer != '\0') {
        printf("%c", *pointer);
        pointer++;
    }
    printf("\n");

    pointer  = string;
    int count = 0;
    while (*pointer != '\0') {
        count++;
        pointer++;
    }
    printf("Number of characters: %d\n", count);
    return 0;
}
