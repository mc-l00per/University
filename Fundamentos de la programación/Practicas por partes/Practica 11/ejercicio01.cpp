
/**      
  * ejercicio01.cpp
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
const int TAMANIO = 100;
int option = 1;

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
		<< "         ()__)      |       EJERCCICIO: 01        |       (__()" << endl
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

/**
 * Función para introducir los datos de la cadena caracter por caracter hasta obtener #
 * @see LeerCadena
 * @param cadena[] parametro donde almacenamos la cadena obtenida;
 */
void LeerCadena(char cadena[]){
	int total_utizados = 0;
	char caracter;
	cout << "Introduce cadena de caracter: ";
	do {
		caracter = cin.get();
		cadena[total_utizados] = caracter;
		total_utizados++;
	} while(total_utizados != 100 && caracter != '#');
	if(caracter != '#')
		cadena[total_utizados] = '#';
}

/**
 * Funcion para calcular el tamaño de la cadena
 * @see TamCadena
 * @param cadena[] cadena a la que le vamos a calcular el valor
 * @return tamaño de la cadena
 */
int TamCadena(const char cadena[]){
	int tam_cadena = 0;
	while(cadena[tam_cadena] != '#') {
		tam_cadena++;
	}
	return tam_cadena;
}

/**
 * Funcion para mostrar la cadena de caracteres
 * @see MostrarCadena
 * @param cadena[]
 * @return devuelbe el contenido de la cadena
 */
void MostrarCadena(const char cadena[]){
	for (int i = 0; i < TamCadena(cadena); ++i)
		cout << "   " << cadena[i];
	cout << endl;
}

/**
 * Funcion para comprobar si es un palindromo
 * @see EsPalindromo
 * @param cadena[]
 */
void EsPalindromo(const char cadena[]){
	int tam_cadena = TamCadena(cadena)-1;
	bool es_palindromo = true;
	for(int i = 0, j = tam_cadena; i < tam_cadena/2 && j > tam_cadena/2; i++, j--)
		if(cadena[i] != cadena[j]){
			es_palindromo = false;
		}
	if(es_palindromo)
		cout << "Es palindromo" << endl;
	else 
		cout << "No es palindromo" << endl;
}

/**
 * Función para invertir la cadena de caracteres
 * @see InvertirCadena
 * @param cadena[] cadena que vamos a invertir
 */
void InvertirCadena(char cadena[]){
	char cadena_aux[TAMANIO];
	for(int i=0, j=TamCadena(cadena)-1; i<=TamCadena(cadena) && j>=0; i++, j--){
		cadena_aux[i] = cadena[j];
	}
	if(TamCadena(cadena)%2 != 0)
		cadena_aux[(TamCadena(cadena)/2)+1] = cadena[(TamCadena(cadena)/2)+1];
	cadena_aux[TamCadena(cadena)] = '#';
	MostrarCadena(cadena_aux);
}

/**
* Función para contar cuantas mayusculas se han introducido
* @see ContarMayusculas
* @param cadena[] cadena de caracteres donde estan las mayusculas que queremos contar
* @return numero de mayusculas
*/
void ContarMayusculas(char cadena[]){
	int numero_mayusculas = 0;
	for(int i = 0; i < TamCadena(cadena); i++)
		if(cadena[i] <= 'Z' && cadena[i] >=  'A')
			numero_mayusculas++;
	cout << "El número de mayusculas es: " << numero_mayusculas << endl;
}

/**
 * Funcion que nos muestra el menu del programa
 * @see Menu
 * @param cadena[] la cadena que quetemos almacenar
 */
void Menu(char cadena[]){
	cin.ignore(256,'\n');
	cout << "Press 'Enter' to continue: ... ";
	while ( getchar() != '\n');
	system("clear");
	do {
		cout << "Selecciona una de estas opcicones:" << endl
			<< "1. Introducir una cadena." << endl
			<< "2. Comprobar si es palindromo." << endl
			<< "3. Invertir la cadena." << endl
			<< "4. Contar mayusculas" << endl
			<< "5. Mostrar cadena." << endl
			<< "\n\n0. salir" << endl;
		cin >> option;
	} while(option < 0 && option > 5);
	//Computos(cadena);
	switch(option){
		case 0:
			break;
		case 1:
			LeerCadena(cadena);
			Menu(cadena);
			break;
		case 2:
			EsPalindromo(cadena);
			Menu(cadena);
			break;
		case 3:
			InvertirCadena(cadena);
			Menu(cadena);
			break;
		case 4:
			ContarMayusculas(cadena);
			Menu(cadena);
			break;
		case 5:
			MostrarCadena(cadena);
			Menu(cadena);
			break;
	}
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	char cadena[TAMANIO];

	// ENTRADA DE DATOS DEL PROGRAMA
	cout << "Introduce la cadena de caracteres: " << endl;
	LeerCadena(cadena);
	Menu(cadena);

	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
