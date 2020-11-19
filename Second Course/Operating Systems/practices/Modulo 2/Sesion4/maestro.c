/**
 * @file maestro.c
 * @brief  El intervalo de números naturales donde calcular los número primos se pasará como
 *         argumento al programa maestro. El maestro creará dos procesos esclavos y dividirá el
 *         intervalo en dos subintervalos de igual tamaño pasando cada subintervalo como
 *         argumento a cada programa esclavo. Por ejemplo, si al maestro le proporcionamos el
 *         intervalo entre 1000 y 2000, entonces un esclavo debe calcular y devolver los números
 *         primos comprendidos en el subintervalo entre 1000 y 1500, y el otro esclavo entre 1501
 *         y 2000. El maestro creará dos cauces sin nombre y se encargará de su redirección para
 *         comunicarse con los procesos esclavos. El maestro irá recibiendo y mostrando en
 *         pantalla (también uno a uno) los números primos calculados por los esclavos en orden
 *         creciente.
 *
 * @author Antonio Rodríguez Alaminos
 */


#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(int argc, char const *argv[]) {
    int fd1[2],fd2[2];
    pid_t pid_esclavo1, pid_esclavo2;
    char cad_inicio[256], cad_fin[256];
    int min, max, primo_escalvo1, primo_esclavo2;

    if (argc < 3) {
        perror("Error en parametros");
        exit(EXIT_FAILURE);
    }

    // se recogen los rangos de busqueda
    min=atoi(argv[1]);
    max=atoi(argv[2]);

    // generamos los dos causes de comunicacion que necesitamos con los esclavos
    pipe(fd1);
    pipe(fd2);

    // iniciamos los procesos esclavos
    if ((pid_esclavo1=fork()) < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid_esclavo1 == 0){
        // cerramos el descriptor de lectura
        close(fd1[0]);
        // duplico la salida de pantalla y redirecciono
        dup2(fd1[1],STDOUT_FILENO);
        //generamos la cadena char para el final
        sprintf(cad_fin,"%d", ((min+max)/2));
        execlp("./esclavo", "esclavo1", argv[1], cad_fin, NULL);
    }else{
        // se cierra el descriptor de escritura
        close(fd1[1]);
        // leemos mientras queden primos por la salida de esclavo1
        while(read(fd1[0], &primo_escalvo1, sizeof(int))){
            printf("\e[34m%d\e[0m ",primo_escalvo1);
        }
        // cerramos el descriptor de lectura
        close(fd1[0]);
        printf("\n");
    }

    if ((pid_esclavo2=fork()) < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    if(pid_esclavo2 == 0){
        // cerramos el descriptor de lectura
        close(fd2[0]);
        // duplico la salida de pantalla y redirecciono
        dup2(fd2[1],STDOUT_FILENO);
        //generamos la cadena char para el final
        sprintf(cad_inicio,"%d", (((min+max)/2)+1));
        if (execlp("./esclavo", "esclavo2", cad_inicio, argv[2], NULL)<0){
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    }else{
        // se cierra el descriptor de escritura
        close(fd2[1]);
        // leemos mientras queden primos por la salida de esclavo1
        while(read(fd2[0], &primo_esclavo2, sizeof(int))){
            printf("\e[33m%d\e[0m ",primo_esclavo2);
        }
        // cerramos el descriptor de lectura
        close(fd2[0]);
        printf("\n");
    }

    return EXIT_SUCCESS;
}