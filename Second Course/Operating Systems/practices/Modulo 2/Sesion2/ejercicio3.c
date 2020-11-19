/**
 * @file ejercicio3.c
 * @brief Aplicación que busca todos los ficheros regulares de un directorio pasado por argumentos que tenga los permisos de ejecución para grupo y otros. Ejecución: <nombre_ejecutable> <nombre_directorio>
 *
 * @author Antonio Rodríguez Alaminos
 */

// librerías necesarías para la aplicación
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>       
#include <stdio.h>

int contador = 0;
long tamTotal = 0;

/**
 * Cuerpo de la aplicación
 * @param  argc número de argumentos
 * @param  argv directorio pasado por argumento. 
 * @return EXIT_SUCCESS (final exitoso) EXIT_FAILURE (final fallido)
 */
int main(int argc, char const *argv[]) {
    //declaracion de variables
    struct dirent *dirent;
    struct stat atri;
    char cad[256];
    DIR *dir;

    //comprobamos los parametros resividos por argumentos
    if (argc != 2) {
        printf("Parametros requeridos: tarea2.c <direccion> \n");
        exit(EXIT_FAILURE);
    }

    //abrimos el directorio
    if ((dir=opendir(argv[1])) == NULL) {
        printf("El directorio %s no se puede abrir \n", argv[2]);
        exit(EXIT_FAILURE);
    }

    printf("Los i-nodos son: \n");

    //leemos el primer i-nodo y mientras queden repetiremos
    while ((dirent = readdir(dir)) != NULL) {
        //almacenamos la la direccion del i-nodo
        sprintf(cad, "%s/%s", argv[1], dirent->d_name);
        //copiamos los atributos del i-nodo
        if (stat(cad, &atri) < 0) {
            printf("Error al abrir el directorio %s\n", cad);
            exit(EXIT_FAILURE);
        }
        //Comprobamos que lo i-nodos no sean directorios.
        if (S_ISREG(atri.st_mode) && atri.st_mode & 011) {
            sprintf(cad, "./%s", dirent->d_name);
            printf("%s %o \n", cad, atri.st_mode & 0777); // muestro los permisos con 0777
            tamTotal += atri.st_size; // guardamos el tamaño en bytes de todos los archivos
            contador++;
        }
    }
    
    printf("Existen %o archivos regulares con permiso x para grupo y otros. \nEl tamaño total ocupado por dichos archivos es %o bytes \n", contador, tamTotal);

    return EXIT_SUCCESS;
}