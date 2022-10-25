#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("Hello from pid(%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        printf("Hello from child pid(%d)\n", (int)getpid());
    } else {
        int rc_wait = wait(NULL);
        printf("Hello from parent pid(%d) of child pid(%d)\n", (int)getpid(), rc);
    }
    return 0;
}