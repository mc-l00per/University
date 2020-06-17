#include<sys/types.h>	
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<dirent.h>
#include<stdlib.h>
#include <sys/mman.h>

int main(){

DIR *dir;
struct dirent *entry;
struct stat atributos;
pid_t pid;
int fd[2], leidos;
long i_nodo;
char buffer[80];
pipe(fd);

if((pid=fork())<0){
	perror("fork");
	exit(1);
}
if(pid == 0){
close(fd[1]);
while(leidos){
leidos=read(fd[0],buffer,10);
printf("\nLos archivos regulares son: %s\n", buffer);
}
}

else{

if((dir=opendir(".")) == NULL){
	printf("Error: No se puede abrir el directorio\n");
	exit(-1);
}

while((entry=readdir(dir)) != NULL){

if(stat(entry->d_name,&atributos) < 0) {
	printf("\nError al intentar acceder a los atributos de: %s\n", entry->d_name);
	perror("Error en lstat\n");
}
if(S_ISREG(atributos.st_mode)){
    	i_nodo=atributos.st_ino;
    	printf("Nombre de archivo: %s Numero de i-nodos: %lu UID: %d\n\n", entry->d_name, i_nodo, getuid());
	close(fd[0]);
	write(fd[1],entry->d_name,10);
}
}
}
}
