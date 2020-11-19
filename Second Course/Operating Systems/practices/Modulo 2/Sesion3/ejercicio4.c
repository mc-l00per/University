/**
 * @file ejercicio4.c
 * @brief Aplicacion que lanza cinco procesos hijos, Cada uno de ellos se identificara en la salida estandar, mostrando un mensaje del tipo:
 * "Soy el hijo PID". 
 * El proceso padre tendra que esperar la finalización del proceso hijo y  lanzar un mensaje del tipo:
 * "Acaba de fianalizar mi hijo con <PID>"
 * Sólo me queda <NUM_HIJOS> hijos vivos
 *
 * @author Antonio Rodríguez Alaminos
 */

//libreria necesarias para la compilación
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int vivos = 5;

int main(int argc, char const *argv[]) {
    pid_t childpid;
    int nprocs = 5, estado;

    for (int i = 0; i < nprocs; ++i) {
        if ((childpid = fork()) == -1) {
            fprintf(stderr, "No se a podido crear el hijo %d: %s\n", i,strerror(errno));
            exit(EXIT_FAILURE);
        }

        waitpid(childpid, &estado, 1);

        if (childpid) 
            break;
        else {
            vivos--;
            printf("Acaba de finalizar mi hijo con <%o> \nSólo me quedan <%o> hijos vivos \n", getpid(), vivos);
        }
    }

    if (childpid){
        printf("==>\tSoy el hijo <%o>\n", getpid());
        exit(EXIT_SUCCESS);        
    }else
        waitpid(childpid, &estado, 1);        

    return EXIT_SUCCESS;
}