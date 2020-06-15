
/**      
  * ejercicio05.cpp
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
const double poblacion_inicial = 1375570814;
const double segundos_anio = 31536000;
const double nace_persona = 1.87;
const double muere_persona = 3.27;
const double emigra_persona = 71.9;

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
		<< "         ()__)      |       EJERCCICIO: 05        |       (__()" << endl
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
	double tiempo = 0, poblacion_final = 0;

	// ENTRADA DE DATOS DEL PROGRAMA
	tiempo = 2;

	// CUERPO DEL PROGRAMA
	tiempo = tiempo * segundos_anio; 
	poblacion_final = poblacion_inicial + (tiempo / nace_persona) - (tiempo / muere_persona) - (tiempo / emigra_persona);

	// SALIDA DE DATOS
	cout << fixed << "La población final es de: " << poblacion_final << endl;
	
	// FINAL Y PAUSA DEL SISTEMA.
	fin();
}

 
