
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
		<< "         ()__)      |       EJERCCICIO: 11        |       (__()" << endl
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
 * Funcion para leer los datos de la primera parte del programa
 * @see leerPrimerCaso
 * @param &entero1
 * @param &entero2
 */
void leerPrimerCaso(int &entero1, int &entero2){
	cout << "Introduce el primer numero entero: ";
	cin >> entero1;
	cout << "Introduce el segundo nuemero entero: ";
	cin >> entero2;
}

/**
 * Funcion para leer los datos de la segunda parte del programa
 * @see leerSegundoCaso
 * @param &entero3
 */
void leerSegundoCaso(int &entero3){
	cout << "Introduce el entero del que se quiere obtener el numero amigo: ";
	cin >> entero3;
}

/**
 * Funcion para mostrar la solucion de la primera parte del problema
 * @see mostrarPrimeraCaso
 * @param amigo
 */
void mostrarPrimerCaso(const bool amigo){
	if(amigo)
		cout << "Los numero introducidos son amigos." << endl;
	else
		cout << "Los numeros introducidos no son amigos." << endl;
}

/**
 * Funcion para mostrar la solucion de la segunda parte del problema
 * @see mostrarSegundoCaso
 * @param entero3
 * @param entero_aux
 * @param tiene_amigo
 */
void mostrarSegundoCaso(const int entero3, const int entero_aux, const bool tiene_amigo){
	if(tiene_amigo)
		cout << "El numero amigo de " << entero3 << " es: " << entero_aux << endl;
	else
		cout << "No tiene numero amigo.";
}

/**
 * Funcion para comprobar si dos numeros son amigos
 * @see amigos
 * @param entero1
 * @param entero2
 * @return true si son amigos fase en caso contrario
 */
bool amigos(const int entero1, const int entero2){
	int contador1 = 0, contador2 = 0;
	for(int i=1; i<entero1; i++)
		if(entero1%i == 0)
			contador1 += i;
	for(int i=1; i<entero2; i++)
		if(entero2%i == 0)
			contador2 += i;
	return (contador1==entero2 && contador2==entero1);
}

/**
 * Funcion para obtener si hay el numero amigo de un numero
 * @see entero3
 * @param entero_aux
 * @param tiene_amigo
 */
void numeroAmigo(const int entero3, int &entero_aux, bool &tiene_amigo){
	int contador1 = 0;
	for(int i=1; i<entero3; i++)
		if(entero3%i == 0)
			contador1 += i;
	entero_aux = contador1;
	tiene_amigo = amigos(entero3, entero_aux);
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	int entero1, entero2, entero3, entero_aux;
	bool amigo, tiene_amigo;

	// ENTRADA DE DATOS DEL PROGRAMA
	leerPrimerCaso(entero1, entero2);

	// CUERPO DEL PROGRAMA 
	amigo = amigos(entero1, entero2); //este se puede hacer como el de abajo que lo veo mas facil pero lo pongo asi para tener los dos casos

	// SALIDA DE DATOS
	mostrarPrimerCaso(amigos);

	// ENTRADA DE DATOS DEL PROGRAMA
	leerSegundoCaso(entero3);

	// CUERPO DEL PROGRAMA 
	numeroAmigo(entero3, entero_aux, tiene_amigo);

	// SALIDA DE DATOS
	mostrarSegundoCaso(entero3, entero_aux, tiene_amigo);

	// FINAL Y PAUSA DEL SISTEMA.
	fin();
}

 
