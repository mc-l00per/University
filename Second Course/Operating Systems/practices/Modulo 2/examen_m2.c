//Andrés Guerrero Pinteño grupo A3

#include<sys/types.h>	
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/mman.h>
#include <string.h>
#include <signal.h>
#define ARCHIVO_FIFO "Comunicacion"

static int signal_recibida = 0;

static void manejador (int sig)
{
          signal_recibida = 1;
}

int main(int argc, char *argv[]){

DIR *dir;
struct dirent *entry;
struct stat atributos;
pid_t pid;
int fd, leidos, size, archivo;
long i_nodo;
char buffer[80];
char *memorigen;

struct sigaction sa;
sa.sa_handler=manejador;
sa.sa_flags=0;
sigaction( SIGINT, &sa, NULL);

sleep(2); //Para comprobar que usando control+c no puede ser interrumpido el proceso.

umask(0);
mkfifo(ARCHIVO_FIFO,0777);

if((fd=open(ARCHIVO_FIFO,O_RDWR)) <0){
	perror("open");
	exit(-1);
}

if((pid=fork())<0){
	perror("fork");
	exit(1);
}
if(pid == 0){
leidos=read(fd,buffer,10);
printf("\nEl archivo es: %s\n", buffer);

if((archivo=open(argv[1],O_RDWR)) <0){
	perror("open");
	exit(-1);
}
memorigen=(char *) mmap(0, size+10, PROT_READ|PROT_WRITE, MAP_SHARED, archivo, 0);
if(memorigen == MAP_FAILED){
	perror("Fallo mapeando el archivo de entrada");
	exit(2);
}
strcpy(memorigen, "REVISADO");
}

else{

if((dir=opendir(".")) == NULL){
	printf("Error: No se puede abrir el directorio\n");
	exit(-1);
}

while((entry=readdir(dir)) != NULL){
	if(strcmp(argv[1], entry->d_name) == 0){
		if(stat(argv[1],&atributos) < 0) {
			printf("\nError al intentar acceder a los atributos de: %s\n", entry->d_name);
			perror("Error en lstat\n");
		}
		if(!((atributos.st_mode & S_IRGRP) && (atributos.st_mode & S_IRUSR)){
			if(chmod(argv[1], S_IRGRP | S_IRWXU | S_IROTH) < 0) {
				perror("\nError en chmod para archivo1");
				exit(-1);
			}
		}
	i_nodo=atributos.st_ino;
	size=atributos.st_size;
    	printf("Nombre de archivo: %s Numero de i-nodos: %lu Tamano: %d\n\n", entry->d_name, i_nodo, size);    	
	write(fd,entry->d_name,20);
}
}
}
}


