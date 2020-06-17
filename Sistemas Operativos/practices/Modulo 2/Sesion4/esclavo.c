/**
 * @file esclavo.c
 * @brief  El programa esclavo tiene como argumentos el extremo inferior y superior del intervalo
 *         sobre el que buscará números primos. Para identificar un número primo utiliza el
 *         siguiente método concreto: un número n es primo si no es divisible por ningún k tal que
 *         2 < k <= sqrt(n), donde sqrt corresponde a la función de cálculo de la raíz cuadrada
 *         (consulte dicha función en el manual).
 *         El esclavo envía al maestro cada primo encontrado como un dato entero (4 bytes) que
 *         escribe en la salida estándar, la cuál se tiene que encontrar redireccionada a un cauce sin 
 *         nombre. Los dos cauces sin nombre necesarios, cada uno para comunicar cada esclavo con el 
 *         maestro, los creará el maestro inicialmente. Una vez que un esclavo haya calculado y 
 *         enviado (uno a uno) al maestro todos los primos en su correspondiente intervalo 
 *         terminará.
 *         
 * @author Antonio Rodríguez Alaminos
 */


#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<math.h> // necesita insertar el parametro -lm en la compilacion

int esPrimo(int n){
    int primo=1;
    for (int i = 2; i <= sqrt(n) && primo; ++i) {
        if (n%i==0)
            primo=0;
    }
    return primo;
}

int main(int argc, char const *argv[]) {
    int min,max;

    if (argc < 3) {
        perror("param");
        exit(EXIT_FAILURE);
    }

    min=atoi(argv[1]);
    max=atoi(argv[2]);
    
    for (int i = min; i < max; ++i) {
        if (esPrimo(i)){
            if((write(STDOUT_FILENO,&i,sizeof(int)))<0){
                perror("write");
                exit(EXIT_FAILURE);
            }
        }
    }
    
    return EXIT_SUCCESS;
}