
/**      
  * ejercicio00.cpp
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
double const TARIFA_BASE = 150;
double const DISTANCIA_MINIMA = 200;

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
		<< "         ()__)      |       EJERCCICIO: 16        |       (__()" << endl
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
	cin.ignore(256,'\n');
	cout << "\n\nPress 'Enter' to continue: ... ";
	while ( getchar() != '\n');
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
	exit;
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	double distancia, precio_viaje, precio_viaje_total, precio_viaje_total2;
	bool previo = false;
	char caracter;

	// ENTRADA DE DATOS DEL PROGRAMA
	cout << "Introduce la distancia del viaje: ";
	cin >> distancia;
	
	do {
		cout << "Itroduce una 'y' si es un cliente previo 'n' si no lo es: ";
		cin >> caracter;
		if(caracter == 'y')
			previo = true;
	} while (caracter != 'y' || caracter != 'n');

	// CUERPO DEL PROGRAMA 
	if (distancia<200)
		precio_viaje=TARIFA_BASE;
	else {
		precio_viaje=TARIFA_BASE;
		for (int i = distancia; i > DISTANCIA_MINIMA; --i)
			precio_viaje += 0.10;
	}

	precio_viaje_total = precio_viaje;

	if(distancia>600 && distancia<1100)
		precio_viaje_total += precio_viaje * 0.03;
	else if(distancia>1100)
		precio_viaje_total += precio_viaje * 0.04;
	else if(previo)
		precio_viaje_total += precio_viaje * 0.05;
		
	precio_viaje_total2 = precio_viaje;
	if(distancia>600 && distancia<1100)
		precio_viaje_total2 += precio_viaje * 0.03;
	else if(distancia>1100)
		precio_viaje_total2 += precio_viaje * 0.04;
	else if(((distancia>600 && distancia<1100) || (distancia>1100)) && previo)
		precio_viaje_total2 += precio_viaje * 0.05;

	// SALIDA DE DATOS
	cout << "Precio para el caso A: " << precio_viaje_total << endl
		<< "Precio para el caso B: " << precio_viaje_total2 << endl;
	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
