
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
double capital, retencion = 20.5;
const char CAMBIO = 'a' - 'A';
char caracter;
const int SALARIO_MINIMO = 20000.0;
bool soltero, autonomo, pensionista;
int edad;

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
	exit(0);
}

/**
 * Funcion para comprobar si es si o no
 * @see comprobarCaracter
 * @param caracter caracter a comprobar
 * @return true si es si false si es no
 */
bool comprobarCaracter(char caracter){
	if(caracter == 's')
		caracter -= CAMBIO;
	else if(caracter == 'n')
		caracter -= CAMBIO;
	return (caracter == 'S');
}

/**
 * Funicon para comprobar si es pensionista
 * @see esPensionista
 * @return true si es jubilado(mayor de 65 años), false en caso contrario.
 */
 bool esPensionista(){
 	return edad > 65;
 }

/**
 * Funcion para leer informacion
 * @see leerInformacion
 */
void leerInformacion(){
	do{
		cout << "Introduce la renta bruta: ";
		cin >> capital;
	} while (capital < 0);

	do{
		cout << "Edad: ";
		cin >> edad;
	} while (edad < 0);
	pensionista = esPensionista();
	
	do {
		cout << "Si es soltero introduce 's' si no 'n': ";
		cin >> caracter;			
	} while (caracter != 's' && caracter != 'n' && caracter != 'S' && caracter != 'N');
	soltero = comprobarCaracter(caracter);

	do {
		cout << "Si es autonomo introduce 's' si no 'n': ";
		cin >> caracter;			
	} while ((caracter != 's' && caracter != 'n') && (caracter != 'S' && caracter != 'N'));
	autonomo = comprobarCaracter(caracter);
}

/**
 * Función para calcular el capital final
 * @see calcularCapital
 * @return Devuelve el capital final despues de introducir la retención
 */
double calcularCapital(){
	//calculamos la retención
	if (!autonomo) {
		if (!pensionista) {
			retencion += 2;
			if (capital < SALARIO_MINIMO)
				retencion += 2;
			else if (!soltero && capital > SALARIO_MINIMO)
				retencion += 2.5;
			else if (soltero && capital > SALARIO_MINIMO)
				retencion += 3;
		else 
			retencion += 1;	
	}else 
		retencion -= 3;
	}	
	//aplicamos la retención
	return capital - capital*retencion/100;
}

/**
 * Función para mostrar la informacion obtenida
 * @see mostrarSalida
 * @param capital_final
 */
void mostrarSalida(double capital_final){
	cout << "La renta final es de: " << capital_final << endl;
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	double capital_final;

	// ENTRADA DE DATOS DEL PROGRAMA
	leerInformacion();

	// CUERPO DEL PROGRAMA 
	capital_final = calcularCapital();

	// SALIDA DE DATOS
	mostrarSalida(capital_final);

	// FINAL Y PAUSA DEL SISTEMA.
	fin();
}

