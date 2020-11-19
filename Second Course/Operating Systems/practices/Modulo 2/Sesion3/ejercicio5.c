/**
 * @file ejercicio4.c
 * @brief Aplicacion que lanza cinco procesos hijos, Cada uno de ellos se identificara en la salida estandar, mostrando un mensaje del tipo:
 * "Soy el hijo PID". 
 * El proceso padre tendra que esperar la finalización del proceso hijo y  lanzar un mensaje del tipo:
 * "Acaba de fianalizar mi hijo con <PID>"
 * Sólo me queda <NUM_HIJOS> hijos vivos
 *
 * Pero en este caso primero esperará a los hijos 1,3,5 y luego a los 2,4
 *
 * @author Antonio Rodríguez Alaminos
 */

//libreria necesarias para la compilación
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>
#include <stdlib.h>

int vivos= 5;
int nimpares = 3;
int impar = 0;

int main(int argc, char *argv[]){
    
    int nprocs = 5, estado;
    int i;
    pid_t childpid[nprocs];

    for( i=0; i<nprocs; i++){
        if((childpid[i] = fork())<0){  
            perror("Fallo en la creacion del hijo");
            exit(-1);
        }else if(childpid[i] == 0){
            printf("Soy el hijo %i\n", getpid());
            exit(1);
        }
    }
    

    for(i = 1; i<nprocs; i = i+2){
        if(waitpid(childpid[i],0,0) > 0){
            vivos--;
                printf("Acaba de finalizar mi hijo con PID %i\n", childpid[i]);
                printf("Solo quedan %i hijos vivos\n", vivos);
        }
    }
    
    for(i = 0;i<nprocs; i = i+2){
        if(waitpid(childpid[i],0,0) > 0){
                vivos--;
                printf("Acaba de finalizar mi hijo con PID %i\n", childpid[i]);
                printf("Solo quedan %i hijos vivos\n", vivos);
        }
    }
    return 0;
}