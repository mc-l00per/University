
/**      
  * ejercicio28.cpp
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
const int FIL = 50;
const int COL = 30;

//CLASES

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
		<< "         ()__)      |       EJERCCICIO: 28        |       (__()" << endl
		<< " ----\\___()_)       |                             |        (_()___/---" << endl
		<< "                    +-----------------Ooo---------+" << endl;
	usleep(2000000);
	system("clear");
}

/**
 * Pausa del sistema, mas intro para continuar
 * @see Pausa
 */
void Pausa(){
	cin.ignore(256,'\n');
	cout << "\n\nPress 'Enter' to continue: ... ";
	while ( getchar() != '\n');
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

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	double original[FIL][COL];
	double suavisada[FIL][COL];
	int numero_filas_n, media = 0.0;

	// ENTRADA DE DATOS DEL PROGRAMA
	do{
		cout << "Introduce el número de filas: ";
		cin >> numero_filas_n;
	} while(numero_filas_n>FIL);
	cout << "Introduce los valores de la matriz original: ";
	for(int i=0; i<numero_filas_n; i++)
		for(int j=0; j<numero_filas_n; j++)
			cin >> original[i][j];

	// CUERPO DEL PROGRAMA 
	//copiamos la matriz suavizada primero totalmente simetrica
	for(int i=0, z=numero_filas_n-1; i<numero_filas_n; i++, z--)
		for(int j=0, x=numero_filas_n-1; j<numero_filas_n; j++, x--)
			suavisada[z][x] = original[i][j];
	//introducimos la diagonal original
	for(int i=0, j=0; i<numero_filas_n; i++, j++)
		suavisada[i][j] = original[i][j];
	//triangulo superior
	for(int i=0; i<numero_filas_n; i++){
		for(int j=0; j<numero_filas_n; j++)
			media += original[i][j];
		for(int z=i+1; z<numero_filas_n; z++)
			suavisada[i][z] = media/numero_filas_n;
		media = 0;
	}

	// SALIDA DE DATOS
	system("clear");
	cout << "Matriz original:" << endl;
	for(int i=0; i<numero_filas_n; i++){
		for(int j=0; j<numero_filas_n; j++)
			cout << original[i][j] << "   ";
		cout << "\n";
	}
	cout << "\nMatriz suavisada:" << endl;
	for(int i=0; i<numero_filas_n; i++){
		for(int j=0; j<numero_filas_n; j++)
			cout << suavisada[i][j] << "   ";
		cout << "\n";
	}

	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
