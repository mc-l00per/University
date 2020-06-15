
/**      
  * ejercicio09.cpp
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
const int AMPLITUD = 'a' - 'A';
enum class TIPO{
	mayuscula, minuscula, otro_caracter
};

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
		<< "         ()__)      |       EJERCCICIO: 09        |       (__()" << endl
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
	exit;
}

/**
 * Funcion para comprobar si una letra es mayuscula
 * @see capitalizacion
 * @param una_letra
 * @return tipo de letra
 */
TIPO capitalizacion(char una_letra){
	if(una_letra >= 'a' && una_letra)
		return TIPO::minuscula;
	else if(una_letra >= 'A')
		return TIPO::mayuscula;
	else
		return TIPO::otro_caracter;
}

/**
 * Funcion para combertir letras en mayuscula
 * @see convierte_a_Mayuscula
 * @param caracter
 * @return caracter
 */
char convierte_a_Mayuscula(char &caracter){
	if(capitalizacion(caracter) == TIPO::minuscula)
		return 	caracter + AMPLITUD;
	else
		return caracter;
}

/**
 * Funcion para combertir letras en mayuscula
 * @see convierte_a_Mayuscula
 * @param caracter
 * @return caracter
 */
char convierte_a_Minuscula(char &caracter){
	if(capitalizacion(caracter) == TIPO::mayuscula)
		return 	caracter - AMPLITUD;
	else
		return caracter;
}

/**
 * Funcion para combertir letras
 * @see cambiaMayusculaMinuscula
 * @param caracter
 * @return caracter
 */
char cambiaMayusculaMinuscula(char &caracter){
	if(capitalizacion(caracter) == TIPO::mayuscula)
		return convierte_a_Minuscula(caracter);
	else if(capitalizacion(caracter) == TIPO::minuscula)
		return convierte_a_Mayuscula(caracter);
	else 
		return caracter;
}

/**
 * Funcion para leer caracteres
 * @see leerCaracter
 */
void leerCaracter(char &caracter){
	cout << "Introduce un caracter: ";
	cin >> caracter;
}

/**
 * Funcion para mostrar caracter
 * @see mostrarCaracter
 */
void mostrarCaracter(const char caracter){
	cout << "El caracter transformado es: " << caracter << endl;
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	char caracter;

	// ENTRADA DE DATOS DEL PROGRAMA
	leerCaracter(caracter);

	// CUERPO DEL PROGRAMA 
	cambiaMayusculaMinuscula(caracter);

	// SALIDA DE DATOS
	mostrarCaracter(caracter);
	
	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
