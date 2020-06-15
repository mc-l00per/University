
/**      
  * ejercicio12.cpp
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
#include <math.h>		//dependencia para operaciones matemáticas
using namespace std;


// DECLARACIÓN DE VARIABLES GLOBALES
const double PI = 3.1415927;

//FUNCIONES
/**
 * Introducción personal al programa
 * @see inicio
 */
void inicio(){
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
		<< "         ()__)      |       EJERCCICIO: 12        |       (__()" << endl
		<< " ----\\___()_)       |                             |        (_()___/---" << endl
		<< "                    +-----------------Ooo---------+" << endl;
	usleep(2000000);
	system("clear");
}

/**
 * Salida personal del programa
 * @see fin
 */  
void fin(){
	cin.ignore(256,'\n');
	cout << "Press 'Enter' to continue: ... ";
	while ( getchar() != '\n');
	system("clear");
	cout << endl << endl << "\t@@@@@@@  @@@  @@@  @@@@@@@@     @@@@@@@@  @@@  @@@  @@@@@@@" << endl;
	cout << "\t@@@@@@@  @@@  @@@  @@@@@@@@     @@@@@@@@  @@@@ @@@  @@@@@@@@" << endl;
	cout << "\t  @@!    @@!  @@@  @@!          @@!       @@!@!@@@  @@!  @@@" << endl;
	cout << "\t  !@!    !@!  @!@  !@!          !@!       !@!!@!@!  !@!  @!@" << endl;
	cout << "\t  @!!    @!@!@!@!  @!!!:!       @!!!:!    @!@ !!@!  @!@  !@!" << endl;
	cout << "\t  !!!    !!!@!!!!  !!!!!:       !!!!!:    !@!  !!!  !@!  !!!" << endl;
	cout << "\t  !!:    !!:  !!!  !!:          !!:       !!:  !!!  !!:  !!!" << endl;
	cout << "\t  :!:    :!:  !:!  :!:          :!:       :!:  !:!  :!:  !:!" << endl;
	cout << "\t   ::    : :  :::  :: ::::      :: ::::   ::   ::   ::::  ::" << endl;
	cout << "\t   :      :   : :  : :: ::      : :: ::   ::   :    :: : :" << endl << endl << endl;
	usleep(2000000);	
	exit;
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	double gaussiana, media, desviacion, abscisa;
	
	// ENTRADA DE DATOS DEL PROGRAMA
	cout << "Introduce el valor de la media o esperanza: ";
	cin >> media;
	cout << endl << "Introduce el valor de la desviación: ";
	cin >> desviacion;
	cout << endl << endl <<"Ahora introduce el valor para la abscisa: ";
	cin >> abscisa;
	
	// CUERPO DEL PROGRAMA 
	gaussiana= 1 / (desviacion * sqrt(2 * PI)) * exp(-1/2 * pow((abscisa - media)/desviacion, 2));
	
	// SALIDA DE DATOS
	cout << endl << endl << "\t El valor de la gaussiana es de: " << gaussiana << endl << endl;

	// FINAL Y PAUSA DEL SISTEMA.
	fin();
}

 
