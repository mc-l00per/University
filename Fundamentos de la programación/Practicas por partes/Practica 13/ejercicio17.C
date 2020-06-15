
/**      
  * ejercicio17.cpp
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
#include <string>
using namespace std;


// DECLARACIÓN DE VARIABLES GLOBALES
const int NUMEROS_CARACTERES_A_COGER = 2;
const char CAMBIO = 'a' - 'A';

//CLASES
class Login{
	//DATOS PRIVADOS DA LA CLASE
	private:
		int num_caracteres_a_coger;
	//DATOS PUBLICOS DE LA CLASE
	public:
		/**
		 * Constructor por defecto de la clase
		 * @see Login
		 * @param numeros_caracteres_a_coger tamaño que tendra cada porción de cadena
		 */
		Login(int numeros_caracteres_a_coger){
			num_caracteres_a_coger = numeros_caracteres_a_coger;
		}
		/**
		 * Comprueba que el caracter sea una mayuscula si la es la transforma en minuscula
		 * @see ComprobarMayusculas
		 * @param p_caracter Caracter que queremos analizar
		 */
		void ComprobarMayusculas(char &p_caracter){
			if(p_caracter>='A' && p_caracter<='Z')
				p_caracter += CAMBIO;
		}
		/**
		 * Genera el nombre de login para el usuario
		 * @see Codifica
		 * @param nombre_completo Es el nombre completo del usuario que usaremos para generar el login
		 * @return cadena_login Es el login generadoo para el usuario
		 */ 
		string Codifica(string nombre_completo){
			string cadena_login;
			int index_login = 0;
			char caracter;
			for(int i=0; i<nombre_completo.size(); i++){
				if(nombre_completo[i] != '#' && nombre_completo[i] != ' ' && index_login < num_caracteres_a_coger){
					caracter = nombre_completo[i];
					ComprobarMayusculas(caracter);
					cadena_login.push_back(caracter);
					index_login++;
				}
				else if(nombre_completo[i] == '#' || nombre_completo[i] == ' ')
					index_login = 0;
			}
			return cadena_login;
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
		<< "         ()__)      |       EJERCCICIO: 17        |       (__()" << endl
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
	Login login(NUMEROS_CARACTERES_A_COGER);
	string nombre_completo;
	char caracter;

	// ENTRADA DE DATOS DEL PROGRAMA
	cout << "Introduce el nombre del usuario, el programa no acepta acentos: ";
	do {
		caracter = cin.get();
		nombre_completo.push_back(caracter);
	} while (caracter != '#');

	// CUERPO DEL PROGRAMA 
	cout << "El nombre de login es: " << login.Codifica(nombre_completo);

	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
