/**
 *  @brief Aplicación que acepte como argumentos el nombre de un programa, sus argumentos si los tiene, y opcionalmente la cadena "bg". Tiene que ejecutar el programa pasado como primer argumento en "foregraund" sino tiene la cadena "bg"
 */

//libreria necesarias para la compilación
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

extern char **environ;

/**
 * Cuerpo del programa
 * @param  argc número introducido por argumentos
 * @param  argv parametros pasador por argumentos
 * @return  EXIT_SUCCESS, EXIT_FAILURE
 */
int main(int argc, char const *argv[]) {
    pid_t childpid[strtol(argv[2], NULL, 10)];
    char cad[256], cad2[256], cad3[256];
    int estado, contador=0;
    //printf("%o\n", argc);
    if (argc > 4 || argc < 3) {
        printf(" - Error en la ejecución del programa. \nOpciones: \n \t<nombre_ejecutable> <nombre_programa_hijo> <número_de_ejecuciones>\t ==> foreground\n \t<nombre_ejecutable> <nombre_programa_hijo> <número_de_ejecuciones> <bg>\t ==> background \n");
        exit(EXIT_FAILURE);
    }

    sprintf(cad, "./%s", argv[1]);
    sprintf(cad2, "%s", argv[1]);

    for (int i = 0; i <  (long int) strtol(argv[2], NULL, 10); ++i) {
        if ((childpid[i]=fork())<0) {
            printf("Error al generar el hijo %o\n", i );
            exit(EXIT_FAILURE);
        }else if (childpid[i]) {
            sprintf(cad3, "%o", getpid());
            printf("%s %s %s \n", cad, cad2, cad3);
            if( (execl(cad2, cad, cad3, NULL)<0)) {
                perror("\nError en el execl");
                exit(EXIT_FAILURE);
            }
        }else if (argv[3] == "bg")
            waitpid(childpid[i], &estado, 1);
    }
    return EXIT_SUCCESS;
}