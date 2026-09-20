#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2;
    int status1, status2;

    child1 = fork();

    if (child1 < 0) {
        perror("fork");
        return 1;
    }

    if (child1 == 0) {
        printf("Child 1 PID: %d\n", getpid());
        sleep(2);
        exit(10);
    }

    child2 = fork();

    if (child2 < 0) {
        perror("fork");
        return 1;
    }

    if (child2 == 0) {
        printf("Child 2 PID: %d\n", getpid());
        sleep(1);
        exit(20);
    }

    waitpid(child2, &status2, 0);

    if (WIFEXITED(status2)) {
        printf("Child 2 exited with status: %d\n", WEXITSTATUS(status2));
    }

    wait(&status1);

    if (WIFEXITED(status1)) {
        printf("Child 1 exited with status: %d\n", WEXITSTATUS(status1));
    }

    printf("Parent PID: %d\n", getpid());

    return 0;
}
