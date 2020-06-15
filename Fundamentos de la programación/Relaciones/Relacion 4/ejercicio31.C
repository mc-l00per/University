
/**      
  * ejercicio31.cpp
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
//#include <String>
using namespace std;


// DECLARACIÓN DE VARIABLES GLOBALES
const int TAMANIO = 30;

//CLASES
class SecuenciaEnteros{
	private:
		int cadena_enteros[TAMANIO];
		int tamanio_cadena_enteros;
	public:
		void Error(string error){
			cout << "Se produjo un error: " << error << endl;
		}
		void SetCadenaEnteros(int p_cadena_enteros[], int p_tamanio_cadena_enteros){
			if(TAMANIO>p_tamanio_cadena_enteros){
				for(int i=0; i<p_tamanio_cadena_enteros; i++)
					cadena_enteros[i] = p_cadena_enteros[i];
			}else {
				Error("Introducir cadena enteros.");
				LeerCadenaEnteros();
			}

		}
		void SetTamanioCadenaEnteros(int p_tamanio_cadena_enteros){
			tamanio_cadena_enteros = p_tamanio_cadena_enteros;
		}
		void LeerCadenaEnteros(){
			int p_cadena_enteros[TAMANIO];
			int p_tamanio_cadena_enteros = 0;
			int entero;
			cout << "Introduce la cadena de enteros(termina con -1): ";
			do {
				cin >> entero;
				p_cadena_enteros[p_tamanio_cadena_enteros] = entero;
				p_tamanio_cadena_enteros++;
			} while (entero != -1);
			SetTamanioCadenaEnteros(p_tamanio_cadena_enteros);
			SetCadenaEnteros(p_cadena_enteros, p_tamanio_cadena_enteros);
		}
};
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
		<< "         ()__)      |       EJERCCICIO: 31        |       (__()" << endl
		<< " ----\\___()_)       |                             |        (_()___/---" << endl
		<< "                    +-----------------Ooo---------+" << endl;
	usleep(2000000);
	system("clear");
}

/**
 * Pausa del sistema, mas intro para continuar
 * @see Pausa
 */
void Pausa(){
	cin.ignore(256,'\n');
	cout << "\n\nPress 'Enter' to continue: ... ";
	while ( getchar() != '\n');
}

/**
 * Salida personal del programa
 * @see Fin
 */  
void Fin(){
	Pausa();
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
	char vector_class[TAMANIO];
	SecuenciaEnteros enteros;

	// ENTRADA DE DATOS DEL PROGRAMA
	vector_class[0] = 'h';
	vector_class[1] = 'o';
	vector_class[2] = 'l';
	vector_class[3] = 'a';

	// CUERPO DEL PROGRAMA 
	
	// SALIDA DE DATOS
	for(int i=0; i<4; i++)
		cout << vector_class[i];
	

	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
