
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
int entero1, entero2;
const char CAMBIO = 'a' - 'A';

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

/**
 * Funcion para introducir datos
 * @see Introducir_numero
 */
void Introducir_numero(){
	cout << "Introduce el primer entero: ";
	cin >> entero1;
	cout << "Introduce el segundo entero: ";
	cin >> entero2;
}

/**
 * Funcion para sumar enteros
 * @see Suma
 * @param ent1 Valor del entero1
 * @param ent2 Valor del entero2
 * @return result resultado de la suma de los dos valores
 */
int Suma (int ent1, int ent2) {
	int result = ent1 + ent2;
	cout << "El valor de la suma es: " << result << endl;
}

/**
 * Funcion para multiplicar enteros
 * @see Producto
 * @param ent1 Valor del entero1
 * @param ent2 Valor del entero2
 * @return result resultado de la multiplicación de los dos valores
 */
int Producto (int ent1, int ent2) {
	int result = ent1 * ent2;
	return result;
}

/**
 * Funcion para calcular el mayor de los enteros
 * @see Maximo
 * @param ent1 Valor del entero1
 * @param ent2 Valor del entero2
 * @return result resultado del mayoor de los dos valores
 */
int Maximo(int ent1, int ent2){
	if (ent1 > ent2)
		return ent1;
	else
		return ent2
}

/**
 * Comprobar que la letra este en mayuscula sino la transforma
 * @see Comprobar_entrada
 * @param opcion Opcion elegida
 * @return opcion la letra transformada de forma que la reconosca el programa.
 */
char Comprobar_entrada (opcion){
	if (opcion >= 'a' || opcion <= 'z')
		opcion -= CAMBIO;
	return opcion;
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	char opcion;

	// ENTRADA DE DATOS DEL PROGRAMA
	do {
		cout << "---------------------" << endl
			<< "I. Introducir números. " << endl
			<< "S. Suma. " << endl
			<< "P. Producto. " << endl
			<< "M. Máximo. " << endl
			<< "R. SaliR. " << endl
			<< "---------------------" << endl;
		cin >> opcion;
		opcion = Comprobar_entrada(opcion);

		switch (opcion){
			case 'I':
				Introducir_numero();
				break;
			case 'S':
				Suma(entero1, entero2);
				break;
			case 'P':
				Producto(entero1, entero2);
				
		}
	} while (opcion != 'R');

	// CUERPO DEL PROGRAMA 
	
	// SALIDA DE DATOS

	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
