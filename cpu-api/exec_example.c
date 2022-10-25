#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("Hello from pid(%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    }
    else if (rc == 0)
    {
        printf("Hello from child pid(%d)\n", (int)getpid());
        char *myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("README.md");
        myargs[2] = NULL; // marks end
        execvp(myargs[0], myargs);
        printf("this line should not print out!\n");
    }
    else
    {
        int rc_wait = wait(NULL);
        printf("Hello from parent pid(%d) of child pid(%d)\n", (int)getpid(), rc);
    }
    return 0;
}