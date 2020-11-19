/**
 * @file ejercicio1.c
 * @brief aplicacion que genera un hijo para comprobar que un numero pasado por argumento es par y mientras el padre comprueba que es divisible por 4
 *
 * @author Antonio Rodríguez Alaminos
 */

//libreria necesarias para la compilación
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {
    pid_t pid;

    if ((pid=fork())<0) {
        perror("Error en el fork \n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        if (((long int) strtol(argv[1], NULL, 10)%2)==0) 
            printf("Es par. \n");
        else
            printf("No es par. \n");
    }else {
        if (((long int) strtol(argv[1], NULL, 10)%4)==0)
            printf("Es divisible por 4\n");
        else
            printf("No es divisible por 4\n");
    }

    return EXIT_SUCCESS;
}