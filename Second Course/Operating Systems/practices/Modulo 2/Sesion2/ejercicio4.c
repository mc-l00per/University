/**
 * @file ejercicio4.c
 * @brief Aplicación que busca todos los ficheros regulares de un directorio pasado por argumentos que tenga los permisos de ejecución para grupo y otros. Ejecución: <nombre_ejecutable> <nombre_directorio> utilizando la libreria 'ftw.h'
 *
 * @author Antonio Rodríguez Alaminos
 */

// librerías necesarías para la aplicación
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>       
#include <stdio.h>
#include <ftw.h>

int contador = 0;
long tamTotal = 0;

/**
 * pasa recursivamente entre los i-nodos  TIERNE QUE DEVOLVER 0  
 * @param  path  ruta del i-nodo
 * @param  stat  atributos del i-nodo
 * @param  flags 10
 * @param  ftw   puntero a la estructura
 * @return       [description]
 */
int visitar(const char *path, const struct stat *stat, int flags, struct FTW *ftw) {
    if (S_ISREG(stat->st_mode) && stat->st_mode & 011) {
        printf("%s %o \n", path, stat->st_mode & 0777);
        tamTotal += stat->st_size;
        contador++;
    }

    return 0;
}

/**
 * Cuerpo de la aplicación
 * @param  argc número de argumentos
 * @param  argv directorio pasado por argumento. 
 * @return EXIT_SUCCESS (final exitoso) EXIT_FAILURE (final fallido)
 */
int main(int argc, char const *argv[]) {
    printf("Los i-nodos son: \n");
    if (nftw(argc >= 2 ? argv[1] : ".", visitar, 10, 0) != 0)
        perror("nftw");
    
    printf("Existen %o archivos regulares con permiso x para grupo y otros. \nEl tamaño total ocupado por dichos archivos es %o bytes \n", contador, tamTotal);
    
    return EXIT_SUCCESS;
}