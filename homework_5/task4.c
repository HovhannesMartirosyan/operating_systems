#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int size = 3;

    char **strings = malloc(size * sizeof(char *));

    if (strings == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        strings[i] = malloc(51 * sizeof(char));

        if (strings[i] == NULL) {
            printf("Memory allocation failed.\n");

            for (int j = 0; j < i; j++) {
                free(strings[j]);
            }

            free(strings);
            return 1;
        }
    }

    printf("Enter 3 strings:\n");

    for (int i = 0; i < 3; i++) {
        fgets(strings[i], 51, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0';
    }

    char **temp = realloc(strings, 5 * sizeof(char *));

    if (temp == NULL) {
        printf("Memory reallocation failed.\n");

        for (int i = 0; i < 3; i++) {
            free(strings[i]);
        }

        free(strings);
        return 1;
    }

    strings = temp;

    for (int i = 3; i < 5; i++) {
        strings[i] = malloc(51 * sizeof(char));

        if (strings[i] == NULL) {
            printf("Memory allocation failed.\n");

            for (int j = 0; j < i; j++) {
                free(strings[j]);
            }

            free(strings);
            return 1;
        }
    }

    printf("Enter 2 more strings:\n");

    for (int i = 3; i < 5; i++) {
        fgets(strings[i], 51, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0';
    }

    printf("All strings: ");

    for (int i = 0; i < 5; i++) {
        printf("%s ", strings[i]);
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        free(strings[i]);
    }

    free(strings);

    return 0;
}
