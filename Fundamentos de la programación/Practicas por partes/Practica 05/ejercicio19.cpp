
/**      
  * ejercicio19.c
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
#include <iostream> //para poder utilizar las entradas y salidas del codigo
#include <cctype>
#include <stdio.h> //para el system pause articial
#include <stdlib.h> //dependencia para las llamadas system de windows
#include <unistd.h> //para poder utilizar el usleep y otros comandos
using namespace std;


// DECLARACIÓN DE VARIABLES GLOBALES


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
		<< "         ()__)      |       EJERCCICIO: 19        |       (__()" << endl
		<< " ----\\___()_)       |                             |        (_()___/---" << endl
		<< "                    +-----------------Ooo---------+" << endl;
	usleep(1000000);
	system("clear");
}

/**
 * Salida personal del programa
 * @see fin
 */  
void fin(){
	cin.ignore(256,'\n');		//limpiamos el buffer de la entrada de teclado
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
	cout << "Press 'Enter' to continue: ... ";
	while ( getchar() != '\n');		//esperamos la introducion de la tecla intro
	exit;							//salimos de la terminal
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	double cantidad, interes, total, anio;
	
	// ENTRADA DE DATOS DEL PROGRAMA
	do {
		cout << endl << "Introduce una cantidad a depositar: ";
		cin >> cantidad;
		if (cantidad < 0){
			cout << endl << "Has introducido mal la cantidad por favor introduce la cantidad correcta tiene que ser mayor que 0" << endl;
		}
	} while (cantidad < 0);
	

	do {
		cout << endl << "Introduce un interes: ";
		cin >> interes;
		if (interes < 0 || interes > 100){
			cout << endl << "Has introducido mal el interes por favor introduce la cantidad correcta tiene que ser mayor que 0 y menor que 100" << endl;
		}
	} while (interes <= 0 && interes >= 100);

	do {
		cout << endl << "Introduce un año: ";
		cin >> anio;
		if (anio < 0){
			cout << endl << "Minimo un año: " << endl;
		}
	} while (anio < 0);
	
	// CUERPO DEL PROGRAMA 
	for (int i = 1; i <= anio; ++i) {
		cantidad = cantidad + (cantidad * (interes / 100));	
		cout << "Total en el año numero " << i << " = " << cantidad << endl;
	}
	
	// FINAL Y PAUSA DEL SISTEMA.
	fin();
}

 
