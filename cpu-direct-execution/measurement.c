#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int start = gettimeofday(NULL, NULL);
    // TODO
    int duration = gettimeofday(NULL, NULL) - start;
    printf("duration = %d\n", duration);
}