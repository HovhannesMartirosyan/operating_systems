#include <stdio.h>

int main() {
    int numbers[5] = {1,2,3,4,5};
    int *pointer = numbers;

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(pointer + i));
    }
    for (int i = 0; i < 5; i++) {
        *(pointer + i) += 10;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(pointer + i));
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    return 1;

}
