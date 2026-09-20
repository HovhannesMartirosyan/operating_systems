#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child = fork();

    if (child < 0) {
        perror("fork");
        return 1;
    }

    if (child == 0) {
        printf("Child PID: %d\n", getpid());
        exit(0);
    } else {
        printf("Parent PID: %d\n", getpid());

        wait(NULL);

        printf("Child process was collected\n");
    }

    return 0;
}
