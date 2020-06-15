
/**      
  * ejercicio30.cpp
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
const int TAMANIO = 999;
const int TAMANIO_ABECEDARIO = 'z' - 'a' + 1;

//CLASES
class SecuenciaCaracteres{
	private:
		char cadena_caracteres[TAMANIO];
		int tamanio_cadena;
	public:
		void SetCadenaCaracteres(char p_cadena_caracteres[]){
			for(int i=0; i<tamanio_cadena; i++)
				cadena_caracteres[i] = p_cadena_caracteres[i];
		}
		void SetTamanioCadena(int p_tamanio_cadena){
			tamanio_cadena = p_tamanio_cadena;
		}
		char *GetCadenaCaracteres(){
			return cadena_caracteres;
		}
		int GetTamanioCadena(){
			return tamanio_cadena;
		}
		void LeerCadenaCaracteres(){
			char caracter;
			char p_cadena_caracteres[TAMANIO];
			int p_tamanio_cadena = 0;
			do {
				caracter = cin.get();
				p_cadena_caracteres[p_tamanio_cadena] = caracter;
				p_tamanio_cadena++;
			} while (caracter != '#');
			SetTamanioCadena(p_tamanio_cadena);
			SetCadenaCaracteres(p_cadena_caracteres);
		}
		void MostrarCadenaCaracteres(){
			for(int i=0; i<tamanio_cadena; i++)
				cout << cadena_caracteres[i];
		}
		char MostrarPosicionCadena(int i){
			return cadena_caracteres[i];
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
		<< "         ()__)      |       EJERCCICIO: 30        |       (__()" << endl
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
	SecuenciaCaracteres cadena1;
	SecuenciaCaracteres cadena2;
	bool similares = true;

	// ENTRADA DE DATOS DEL PROGRAMA
	cout << "Introduce la primera cadena de caracteres: ";
	cadena1.LeerCadenaCaracteres();
	cout << "Intoduce la segunda cadena de caracteres: ";
	cadena2.LeerCadenaCaracteres();

	// CUERPO DEL PROGRAMA 
	//comprobamos el principio y el final
	if(cadena1.MostrarPosicionCadena(0) != cadena2.MostrarPosicionCadena(0))
		similares = false;
	else if(cadena1.MostrarPosicionCadena(cadena1.GetTamanioCadena()) != cadena2.MostrarPosicionCadena(cadena2.GetTamanioCadena()))
		similares = false;

	//comprobamos si el resto de letras son las mismas
	for(int i=0; i<cadena1.GetTamanioCadena(); i++)
		

	// SALIDA DE DATOS. 
	cout << "cadena primera: ";
	cadena1.MostrarCadenaCaracteres();
	cout << "\ncadena dos";
	cadena2.MostrarCadenaCaracteres();
	cout << cadena2.MostrarPosicionCadena(0);

	if(similares)
		cout << "\nLas cadenas de caracteres son similares." << endl;
	else
		cout << "\nlas cadenas no son similares." << endl;

	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
