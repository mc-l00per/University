/**
 * @file ejercicio2.c
 * @brief Aplicacion que se le pasan por argumentos una direccion y permisos para cambiar los permisos de todos los ficheros regulares que no sean direcctorios.
 * Forma de ejecución: <nombre_ejecutable> <direcion_directorio> <permisos(XXXX)>
 *
 * @author Antonio Rodríguez Alaminos
 */

//librerias necesarias para la compilacion
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include<fcntl.h>       
#include<stdio.h>
#include<stdlib.h>

/**
 * @see main
 * @brief Cuerpo del programa
 * @param  argc numero de parametros pasados como argumentos
 * @param  argv parametros pasados por argumentos
 * @return      EXIT_FAILURE (salida erronea del programa) :: EXIT_SUCCESS (Salida exitosa del programa)
 */
int main(int argc, char const *argv[]){
    //declaracion de variables
    char cad[256], cad2[256];
    struct dirent *dirent;
    struct stat atri;
    DIR *dir;

    //comprobamos los parametros resividos por argumentos
    if (argc != 3) {
        printf("Parametros requeridos: tarea2.c <direccion> <permisos> \n");
        exit(EXIT_FAILURE);
    }else if (argv[2][4] != '\0') { // el segundo argumento tiene que tener 4 digitos
        printf("Parametros requeridos: tarea2.c <direccion> <XXXX> \n");
        exit(EXIT_FAILURE);
    }

    //abrimos el directorio
    if ((dir=opendir(argv[1])) == NULL) {
        printf("El directorio %s no se puede abrir \n", argv[2]);
        exit(EXIT_FAILURE);
    }

    //leemos el primer i-nodo y mientras queden repetiremos
    while ((dirent = readdir(dir)) != NULL) { // mientras pueda leer el directorio
        //almacenamos la la direccion del i-nodo
        sprintf(cad, "%s/%s", argv[1], dirent->d_name);//home/ejercicio2(*...)
        //copiamos los atributos del i-nodo
        if (stat(cad, &atri) < 0) { //copia los atributos de //home/ejercicio2 a &atri
            printf("Error al abrir los atributos del i-nodo %s\n", cad);
            exit(EXIT_FAILURE);
        }
        //Comprobamos que lo i-nodos no sean directorios.
        if (S_ISREG(atri.st_mode) && !S_ISDIR(atri.st_mode)) {
            //guardamos el nombre del i-nodo y sus permisos antes de guardarlos
            sprintf(cad2, "%s: %o", dirent->d_name, atri.st_mode & 0777);
            //Cambiamos los permisos del programa
            if (chmod(cad, (long int) strtol(argv[2], NULL, 8))) {
                printf("Error en el cambio de permisos. \n");
                exit(EXIT_FAILURE);
            }
            //actualizamos los valores de atri ya que ahora son diferentes
            if (stat(cad, &atri) < 0) {
                printf("Error al abrir el directorio %s\n", cad);
                exit(EXIT_FAILURE);
            }
            //imprimimos el resultado
            printf("%s -> %o \n", cad2, atri.st_mode & 0777);
        }
    }
    
    return EXIT_SUCCESS;
}