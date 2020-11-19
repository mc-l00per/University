//Antonio
//Rodríguez Alaminos

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]){

	struct dirent *dirent;
    struct stat atri;
    pid_t childpid;
    DIR *dir;
    int cause[2], estado, fd;
	char rutaTmp[PATH_MAX], buffer[PATH_MAX];
	umask(0);
	
	
	//comprobamos los parametros pasados por argumentos
	if (argc < 2) {
        perror("param");
        exit(EXIT_FAILURE);
    }

	//fichero para los errores
	char rutaerror[PATH_MAX];
	strcpy(rutaerror,argv[1]);
	strcat(rutaerror,".err");
	
	if( (fd=open(rutaerror,O_CREAT|O_TRUNC|O_WRONLY,S_IRGRP|S_IWGRP|S_IRUSR|S_IWUSR))<0) {
		perror("\nError en open");
		exit(EXIT_FAILURE);
	}
	
	dup2(fd,STDERR_FILENO);
	
	//abrimos el directorio
    if ((dir=opendir("/tmp/chequeos")) == NULL) {
        perror("El directorio no se puede abrir. \n");
        exit(EXIT_FAILURE);
    }
	
	//leemos el primer i-nodo y mientras queden repetiremos
    while ((dirent = readdir(dir)) != NULL) {
    	
        //copiamos los atributos del i-nodo
        sprintf(rutaTmp,"/tmp/chequeos/%s",dirent->d_name);
        if (stat(rutaTmp, &atri) < 0) {
            perror("Error al abrir los atributos del i-nodo. \n");
            exit(EXIT_FAILURE);
        }
        //Comprobamos que lo i-nodos no sean directorios.
        if (S_ISREG(atri.st_mode)) {
        	//generamos los hijos
        	if ((childpid = fork()) == -1) {
			    perror("No se a podido crear el hijo.\n");
			    exit(EXIT_FAILURE);
			}

			//waitpid(-1, &estado, 1);

			if (childpid==0){ 
				// cerramos el descriptor de lectura
				close(cause[0]);
				// duplico la salida de pantalla y redirecciono
				dup2(cause[1],STDOUT_FILENO);
				//ejecutamos el fichero regular pasandole como parametro el argumento pasado
				if((execlp(rutaTmp, rutaTmp, argv[1], NULL))<0){
					perror("No se a podido ejecutar el hijo.\n");
			    	exit(EXIT_FAILURE);
				}
			} else {
			    waitpid(childpid,0,0);
			    // se cierra el descriptor de escritura
				close(cause[1]);
				// leemos mientras queden primos por la salida de esclavo1
				while(read(cause[0], buffer, PATH_MAX)==0){
				    printf("\n %s \n",buffer);
				}
				// cerramos el descriptor de lectura
				close(cause[0]);
			}
            
        }
    }
    
    close(fd);  
	return EXIT_SUCCESS;
}
