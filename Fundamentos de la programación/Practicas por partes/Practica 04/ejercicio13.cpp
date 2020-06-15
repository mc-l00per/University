
/**      
  * ejercicio13.cpp
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
double retencion = 20.5;
const int SALARIO_MINIMO = 20000;

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
		<< "         ()__)      |       EJERCCICIO: 13        |       (__()" << endl
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
	cout << "Press 'Enter' to continue: ... ";
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
	exit(0);
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	double renta_bruta, renta_neta;
	bool autonomo, pensionista, soltero;
	int estado_civil, estado_trabajo;
	int edad;

	// ENTRADA DE DATOS DEL PROGRAMA
	cout << "Introduce la renta bruta: ";
	cin >> renta_bruta;
	cout << "Edad: ";
	cin >> edad;
	
	do {
		cout << "Si es soltero introduce '1' si no '0': ";
		cin >> estado_civil;			
	} while (estado_civil > 1 || estado_civil < 0);
	
	do {
		cout << "Si es autonomo introduce '1' si no '0': ";
		cin >> estado_trabajo;			
	} while (estado_trabajo > 1 || estado_trabajo < 0);

	// CUERPO DEL PROGRAMA
	//comprobamos estado civil 
	if (estado_civil == 1)
		soltero = true;
	else
		soltero = false;

	//comprobamos si es autonomo
	if (estado_trabajo == 1)
		autonomo = true;
	else
		autonomo = false;

	//comprobamos si es pensionista
	if (edad > 65)
		pensionista = true;
	else
		pensionista = false;

	//calculamos la retención a aplicar
	if (!autonomo) {
		if (!pensionista) {
			retencion += 2;
			if (renta_bruta < SALARIO_MINIMO)
				retencion += 2;
			else if (!soltero && renta_bruta > SALARIO_MINIMO)
				retencion += 2.5;
			else if (soltero && renta_bruta > SALARIO_MINIMO)
				retencion += 3;
		else 
			retencion += 1;	
	}else 
		retencion -= 3;
	}	
	
	//aplicamos la retención
	renta_neta = renta_bruta - renta_bruta*retencion/100;

	// SALIDA DE DATOS
	cout << "La renta final es de: " << renta_neta << endl;

	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
