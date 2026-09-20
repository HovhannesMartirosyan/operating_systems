#include <stdio.h>
#include <stdlib.h>

void first_message() {
    printf("First cleanup function\n");
}

void second_message() {
    printf("Second cleanup function\n");
}

int main() {
    atexit(first_message);
    atexit(second_message);

    printf("Program is running\n");
    printf("Exiting now...\n");
    exit(0);
}
