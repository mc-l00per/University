/**
 * 
 */

//libreria necesarias para la compilación
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    pid_t childpid = 1;

    for (int i=1; i < 21; i++) { 
        if ((childpid= fork()) == -1) { 
            fprintf(stderr, "Could not create child %d: %s\n",i,strerror(errno));
            exit(EXIT_FAILURE);
        } 
        if (!childpid) 
            break;
        printf("pid del proceso hijo: %d \t pid del proceso padre: %d \n", getpid(), getppid());
    }

    return 0;
}