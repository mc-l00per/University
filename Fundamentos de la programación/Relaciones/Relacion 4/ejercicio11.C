
/**      
  * ejercicio11.cpp
  *
  * Copyright 2015 Antonio Rodríguez Alaminos <aralaminos@correo.ugr.es>
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation; either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
  * MA 02110-1301, USA.
  */


 // DEPENDENCIAS DEL PROGRAMA.
#include <iostream> 	//para poder utilizar las entradas y salidas del codigo
#include <cctype>
#include <stdio.h> 		//para el system pause articial
#include <stdlib.h> 	//dependencia para las llamadas system de windows
#include <unistd.h> 	//para poder utilizar el usleep y otros comandos
using namespace std;


// DECLARACIÓN DE VARIABLES GLOBALES

//FUNCIONES
/**
 * Introducción personal al programa
 * @see Inicio
 */
void Inicio(){
	cout << "\t                                              ____   ___" << endl 
		<< "\t  /\\   /\\    ____    /\\   /\\  _____   ___.__. \\   \\ /  /" << endl
		<< "\t /  \\ /  \\ _/ ___\\  /  \\ /  \\ \\__  \\ <   |  |  \\      /" << endl
		<< "\t/    Y    \\\\  \\___ /    Y    \\ / __ \\_\\___  |  /      \\" << endl
		<< "\t\\_/\\___/\\_/ \\___  >\\_/\\___/\\_/(____  // ____| /___/\\   \\" << endl
		<< "\t                \\/                 \\/ \\/            \\__/" << endl << endl
		<< "                           \\ ||| /" << endl
		<< "     .-.________            (o o)                      ________.-." << endl
		<< "----/ \\_)_______)   +--oooO-----------------------+   (_______(_/ \\----" << endl
		<< "   (     ()___)     |                             |      (___()    )" << endl
		<< "         ()__)      |       EJERCCICIO: 11        |       (__()" << endl
		<< " ----\\___()_)       |                             |        (_()___/---" << endl
		<< "                    +-----------------Ooo---------+" << endl;
	usleep(2000000);
	system("clear");
}

/**
 * Salida personal del programa
 * @see Fin
 */  
void Fin(){
	Pausa();
	system("clear");
		cout << endl << endl << "\t@@@@@@@  @@@  @@@  @@@@@@@@     @@@@@@@@  @@@  @@@  @@@@@@@" << endl
		<< "\t@@@@@@@  @@@  @@@  @@@@@@@@     @@@@@@@@  @@@@ @@@  @@@@@@@@" << endl
		<< "\t  @@!    @@!  @@@  @@!          @@!       @@!@!@@@  @@!  @@@" << endl
		<< "\t  !@!    !@!  @!@  !@!          !@!       !@!!@!@!  !@!  @!@" << endl
		<< "\t  @!!    @!@!@!@!  @!!!:!       @!!!:!    @!@ !!@!  @!@  !@!" << endl
		<< "\t  !!!    !!!@!!!!  !!!!!:       !!!!!:    !@!  !!!  !@!  !!!" << endl
		<< "\t  !!:    !!:  !!!  !!:          !!:       !!:  !!!  !!:  !!!" << endl
		<< "\t  :!:    :!:  !:!  :!:          :!:       :!:  !:!  :!:  !:!" << endl
		<< "\t   ::    : :  :::  :: ::::      :: ::::   ::   ::   ::::  ::" << endl
		<< "\t   :      :   : :  : :: ::      : :: ::   ::   :    :: : :" << endl << endl << endl;
	usleep(2000000);	
	exit(0);
}

/**
 * Pausa del sistema, mas intro para continuar
 * @see Pausa
 */
void Pausa(){
	cin.ignore(256,'\n');
	cout << "\n\nPress 'Enter' to indiceinue: ... ";
	while ( getchar() != '\n');
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	char cadena[TAM], caracter;
	int cont = 0;
	int mayusculas[TOTAL_MAYUSCULA];

	// ENTRADA DE DATOS DEL PROGRAMA
	cout << "Introduce la cadena de caracteres: ";
	do {
		caracter = cin.get();
		cadena[cont] = caracter;
		cont++;
	} while (cont < TAM && caracter != '.');

	// CUERPO DEL PROGRAMA 
	for(int i=0; i<TOTAL_MAYUSCULA; i++)
		mayusculas[i] = 0;
	cont = 0;
	for(char i = 'A'; i <= 'Z'; i++){
		for(int z=0; cadena[z] != '.'; z++){
			if(i == cadena[z])
				mayusculas[cont] += 1;
		}	
		cont++;		
	}

	// SALIDA DE DATOS
	cont = 0;
	for(char i = 'A'; i <= 'Z'; i++){
		if(mayusculas[cont] > 0)
			cout << i << " == " << mayusculas[cont] << endl;
			cont++;					
	}
	
	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
