
/**      
  * ejercicio07.cpp
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
#include <cmath>
#include <limits>
using namespace std;


// DECLARACIÓN DE VARIABLES GLOBALES
const int INF = numeric_limits<int>::max();
int option;

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
		<< "         ()__)      |       EJERCCICIO: 07        |       (__()" << endl
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
 * Funcion para leer la informacion
 * @see leerInformacion
 * @param &k
 * @param &a
 * @param &r
 */
void leerInformacion(int &k, int &a, int &r){
	do{
		cout << "Introduce un valor para r: ";
		cin >> r;
		if(r<0)
			cout << "El valor no puede ser inferior." << endl;
	} while(r < 0);

	do{
		cout << "Introduce el valor de a: ";
		cin >> a;
		if(r<0)
			cout << "El valor no puede ser inferior." << endl;
	} while(a < 0);

	do{
		cout << "Introduce el valor para el k: ";
		cin >> k;
		if(r<0)
			cout << "El valor no puede ser inferior." << endl;
	} while(k < 0);
}

/**
 * Funcion para sumar hasta un tope k
 * @see sumaHasta
 * @param k
 * @param a
 * @param r
 * @param &result
 */
void sumaHasta(const int k, const int a, const int r, double &result){
	for (int i = 0; i < k; ++i) 
		result += a * pow(r, i);
}

/**
 * Funcion para multiplicas hasta un tope k
 * @see productoHasta
 * @param k
 * @param a
 * @param r
 * @param &result
 */
void productoHasta(const int k, const int a, const int r, double &result){
	for (int i = 0; i < k; ++i) 
		result *= sqrt(pow((a * result), k));
}

/**
 * Funcion para sumar hasta el infinito
 * @see sumaHastaInfinito
 * @param a
 * @param r
 * @param &result
 */
void sumaHastaInfinito(const int a, const int r, double &result){
	for(int i = 0; i < INF; ++i)
		result += a / (1 - r);
}

/**
 * Funcion para mostrar el menu de seleccion de opciones
 * @see mostrarMenu
 */
void mostrarMenu(int &k, int &a, int &r, double &result){
	system("clear");
	cout << "Selecciona una opción:" << endl
		<< "\t1.\tSuma hasta un tope." << endl
		<< "\t2.\tProducto hasta un tope." << endl
		<< "\t3.\tSuma hasta el infinito." << endl << endl
		<< "\t4.\tIntroducir nuevos datos." << endl
		<< "\t5.\tSalir." << endl;
	cin >> option;
	calcular(k, a, r, result, option);
}

/**
 * Funcion para calcular los valores que necesitamos
 * @see calcular
 * @param k
 * @param a
 * @param r
 * @param result
 * @param option
 */
void calcular(int k, int a, int r, double &result, int option){
	switch (option){
		case 1:
			sumaHasta(k, a, r, result);
			cout << "\n\nEl valor de la suma hasta " << k << " es: " << result << endl;
			cin.ignore(256,'\n');
			cout << "\n\nPress 'Enter' to continue: ... ";
			while (getchar() != '\n');
			mostrarMenu(k, a, r, result);
			break;
		case 2:
			productoHasta(k, a, r, result);
			cout << "\n\nEl valor de la producto hasta " << k << " es: " << result << endl;
			cin.ignore(256,'\n');
			cout << "\n\nPress 'Enter' to continue: ... ";
			while (getchar() != '\n');
			mostrarMenu(k, a, r, result);
			break;
		case 3:
			sumaHastaInfinito(a, r, result);
			cout << "\n\nEl valor de la suma hasta el infinito es: " << result << endl;
			cin.ignore(256,'\n');
			cout << "\n\nPress 'Enter' to continue: ... ";
			while (getchar() != '\n');
			mostrarMenu(k, a, r, result);
			break;
		case 4:
			leerInformacion(k, a, r);
			cin.ignore(256,'\n');
			cout << "\n\nPress 'Enter' to continue: ... ";
			while (getchar() != '\n');
			mostrarMenu(k, a, r, result);
			break;
		case 5:
			break;
	}
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	int k, a, r;
	double result = 0;

	// ENTRADA DE DATOS DEL PROGRAMA
	leerInformacion(k, a, r);

	// CUERPO DEL PROGRAMA y SALIDA DE DATOS 
	mostrarMenu(k, a, r, result);

	// FINAL Y PAUSA DEL SISTEMA.
	fin();
}
