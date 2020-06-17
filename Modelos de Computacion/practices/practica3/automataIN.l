                 /*----- Sección de Declaraciones --------------*/

%{
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int tiempoIntervalo = 0;
int tiempo = 0;
int contador = 1;
char charTimeInit[11];
char charTimeEnd[11];
bool tieneNombre = false;
void escribirNombre(char* dato1, int tam);
void escribirInicio(char* dato1, int tam);
void escribirFin(char* dato1, int tam);

%}

initTime            ("*** BEGIN OF EXPERIMENT ")
fechaDia            {initTime}([a-zA-Z]{3})
fechaMes            {fechaDia}.([a-zA-Z]{3})
fechaDiaNum         {fechaMes}.([0-9]{2})
hora                {fechaDiaNum}.([0-9]{2}\:[0-9]{2}\:[0-9]{2})
cet                 {hora}.([a-zA-Z]{3})
initProceso         {cet}.([0-9]{4})

initNombre           ("The name is: ")
nombreProceso       {initNombre}([a-zA-Z]+).([a-zA-Z]+)* 
     
endTime             ("*** END OF EXPERIMENT ")
endfechaDia         {endTime}([a-zA-Z]{3})
endfechaMes         {endfechaDia}.([a-zA-Z]{3})
endfechaDiaNum      {endfechaMes}.([0-9]{2})
endhora             {endfechaDiaNum}.([0-9]{2}\:[0-9]{2}\:[0-9]{2})
endcet              {endhora}.([a-zA-Z]{3})
endProceso          {endcet}.([0-9]{4})

%%
                 /*----- Sección de Reglas ----------------*/

{initProceso}               { escribirInicio(yytext, yyleng); } 
{nombreProceso}             { escribirNombre(yytext, yyleng); } 
{endProceso}                { escribirFin(yytext, yyleng); } 
.                           {}
\n                          {}
%%
                /*----- Sección de Procedimientos --------*/

int main (int argc, char *argv[]){
  if (argc == 2)  {
    yyin = fopen (argv[1], "rt");

    if (yyin == NULL)    {
      printf ("El fichero %s no se puede abrir\n", argv[1]);
      exit (-1);
    }
  }
  else yyin = stdin;

  yylex ();
  printf ("\n");
  printf ("\n --> Tiempo Final: %is", tiempo);
  printf ("\n");

  return 0;
}

void escribirInicio(char* dato1, int tam){
  char* tipo = "Inicio: ";
  char* aux;
  bool encontrado = 0;
  char letra;
  int tamanio = 32;

  printf ("\n## Inicio Proceso: %i ## \n", contador);
  printf ("\n%s",tipo);

  aux = dato1;

  for(int i=24; i < strlen(dato1); i++){
    letra = dato1[i];
    printf ("%c",letra);
  }

  for(int i=0; i < 11; i++){
    letra = aux[tamanio];
    charTimeInit[i] = letra;
    tamanio++;
  }
}

void escribirFin(char* dato1, int tam){
  char* tipo = "Fin: ";
  bool encontrado = 0;
  char letra;
  char* aux;
  int tamanio = 30;

  if (tieneNombre != true){
    printf ("\nNombre: No tiene nombre. ");
  }

  printf ("\n%s",tipo);

  aux = dato1;

  for(int i=22; i < strlen(dato1); i++){
    letra = dato1[i];
    printf ("%c",letra);
  }

  for(int i=0; i < 11; i++){
    letra = aux[tamanio];
    charTimeEnd[i] = letra;
    tamanio++;
  }

  tiempoTotal();

  printf ("\n \n## Fin Proceso: %i ## \n \n################################# \n", contador);
  
  tieneNombre = false;

  contador++;
}

void escribirNombre(char* dato1, int tam){
  char* tipo = "Nombre: ";
  bool encontrado = 0;
  char letra;

  printf ("\n%s",tipo);

  for(int i=13; i < strlen(dato1); i++){
    letra = dato1[i];
    printf ("%c",letra);
  }

  tieneNombre = true;
}

void tiempoTotal(){
  int tamanio = 0, tiempoTotalInit = 0, tiempoTotalEnd = 0;
  char CdiaInit[2], CdiaEnd[2], ChoraInit[2], ChoraEnd[2], CminInit[2], CminEnd[2], CsegInit[2], CsegEnd[2];

  for(int i = 0; i < 2; i++){
    CdiaInit[i] = charTimeInit[tamanio];
    CdiaEnd[i] = charTimeEnd[tamanio];
    tamanio++;
  }
  
  tamanio++;

  for(int i = 0; i < 2; i++){
    ChoraInit[i] = charTimeInit[tamanio];
    ChoraEnd[i] = charTimeEnd[tamanio];
    tamanio++;
  }

  tamanio++;

  for(int i = 0; i < 2; i++){
    CminInit[i] = charTimeInit[tamanio];
    CminEnd[i] = charTimeEnd[tamanio];
    tamanio++;
  }

  tamanio++;

  for(int i = 0; i < 2; i++){
    CsegInit[i] = charTimeInit[tamanio];
    CsegEnd[i] = charTimeEnd[tamanio];
    tamanio++;
  }
  
  tiempoTotalInit = atoi(CdiaInit)*24*60*60;
  tiempoTotalInit += atoi(ChoraInit)*60*60;
  tiempoTotalInit += atoi(CminInit)*60;
  tiempoTotalInit += atoi(CsegInit);

  tiempoTotalEnd = atoi(CdiaEnd)*24*60*60;
  tiempoTotalEnd += atoi(ChoraEnd)*60*60;
  tiempoTotalEnd += atoi(CminEnd)*60;
  tiempoTotalEnd += atoi(CsegEnd);

  tiempoIntervalo = tiempoTotalEnd - tiempoTotalInit;

  tiempo += tiempoIntervalo;

  printf ("\n   --> Tiempo Proceso: %is", tiempoIntervalo);
}