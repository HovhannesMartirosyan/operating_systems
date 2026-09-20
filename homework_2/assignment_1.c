#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        exit(0);
    } else {
        printf("Parent PID: %d\n", getpid());
    }

    return 0;
}
