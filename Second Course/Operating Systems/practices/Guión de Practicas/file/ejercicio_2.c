#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>   
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

int main(int argc, char const *argv[]) { 
    //declaramos los ficheros que utilizaremos
    int fread, fwrite, numbytestmp = 0, contador = 1;
    char buffer[80];

    
    //comprobamos los argumentos pasados al programa  
    if(argc < 2) {
        fread = STDIN_FILENO;
    }else{
        //apertura o generacion del fichero de salida
        if((fread=open(argv[1],O_RDONLY)) < 0) {
            perror("\nError en open read");
            exit(EXIT_FAILURE);
        }
    }

     //apertura o generacion del fichero de salida
    if((fwrite=open("salida.txt",O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR)) < 0) {
        perror("\nError en open write");
        exit(EXIT_FAILURE);
    }

    //reservamos un trozo para el codigo que se requiere introducir al final
    if(lseek(fwrite,80,SEEK_SET) < 0) {
        perror("\nError en el desplazamiento(lseek)");
        exit(EXIT_FAILURE);
    }

    //lectura mientras de pueda del fichero se almacena en ftmp
   while ((numbytestmp = read(fread, &buffer, 80)) > 0){
        //introducimos el numero de bloque
        char titulo[16];
        if((sprintf(titulo, "\nBloque %i \n", contador)) < 0){
            perror("\nError en la inserción del titulo");
            exit(EXIT_FAILURE);
        }
        if (write(fwrite, &titulo, sizeof(titulo)) < 0) {
            perror("\nError en el write de la inserción del tituto ");
            exit(EXIT_FAILURE);
        }
        
        //pasamos a introducir los 80 bytes correspondientes por bloque
        if ((write(fwrite, &buffer, numbytestmp)) < 0) {
            perror("\nError en la inserción del buffer");
            exit(EXIT_FAILURE);
        }

        contador++;
    }

    //introducimos el titulo inicial
    char buffer2[40];
    if((sprintf(buffer2, "El número de bloques total es de: %i.\n", contador-1)) < 0){
        perror("\nError en la inserción del titulo inicial.");
        exit(EXIT_FAILURE);
    }
    if(lseek(fwrite,0,SEEK_SET) < 0){
        perror("\nError en el desplazamiento de la inserción del titulo final.");
        exit(EXIT_FAILURE);
    }
   if((write(fwrite, &buffer2, sizeof(buffer2))) < 0) {
        perror("\nError en la inserción del titulo final.");
        exit(EXIT_FAILURE);
    }

    //cerramos los fichero abiertos
    close(fread);
    close(fwrite);

    return EXIT_SUCCESS;
}