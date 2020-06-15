
/**      
  * ejercicio04.cpp
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

//CLASES
class SecuenciaCaracteres{
	private:
		char cadena[TAMANIO];
	public:
		void GetCadena(char p_cadena[]){
			for(int i=0; i<TAMANIO; i++)
				cadena[i] = p_cadena[i];
		}
		char *SetCadena(){
			return cadena;
		}
		void LeerCadena(){
			char p_cadena[TAMANIO], caracter;
			int total_utizados = 0;
			cout << "Introduce cadena de caracter (cerrar cadena con '#'): ";
			do {
				caracter = cin.get();
				p_cadena[total_utizados] = caracter;
				total_utizados++;
			} while(total_utizados != 100 && caracter != '#');
			if(caracter != '#')
				p_cadena[total_utizados] = '#';
			GetCadena(p_cadena);
		}
		int TamCadena(){
			int tam_cadena = 0;
			while(cadena[tam_cadena] != '#') {
				tam_cadena++;
			}
			return tam_cadena;
		}
		void MostrarCadena(){
			for (int i = 0; i < TamCadena(); ++i)
				cout << "   " << cadena[i];
			cout << endl;
		}
		bool EsPalindromo(){
			for(int i = 0, j = TamCadena()-1; i < TamCadena()/2 && j > TamCadena()/2; i++, j--){
				cout << cadena[i] << cadena[j] <<endl;
				if(cadena[i] != cadena[j])
					return false;
			}
			return true;
		}
		void Invierte(){
			for(int i=0, j=TamCadena()-1; i<=TamCadena()/2; i++, j--)
				IntercambiaComponentes(i,j);
			MostrarCadena();
		}
		int ContarMayusculas(){
			int numero_mayusculas = 0;
			for(int i = 0; i < TamCadena(); i++)
				if(cadena[i] <= 'Z' && cadena[i] >=  'A')
					numero_mayusculas++;
			return numero_mayusculas;
		}
		void IntercambiaComponentes(int x, int y){
			char aux_caracter = cadena[x];
			cadena[x] = cadena[y];
			cadena[y] = aux_caracter;
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
		<< "         ()__)      |       EJERCCICIO: 03        |       (__()" << endl
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
 * Funcion que nos muestra el menu del programa
 * @see Menu
 * @param cadena[] la cadena que quetemos almacenar
 */
void Menu(SecuenciaCaracteres cadena){
	switch(option){
		case 0:
			break;
		case 1:
			cadena.LeerCadena();
			break;
		case 2:
			if(cadena.EsPalindromo())
				cout << "Es un palindromo";
			else
				cout << "No es un palindromo";
			break;
		case 3:
			cadena.Invierte();
			break;
		case 4:
			cout << "Hay " << cadena.ContarMayusculas() << " letras en mayuscula." << endl;
			break;
		case 5:
			cadena.MostrarCadena();
			break;
		case 6:
			int componente1, componente2;
			cout << "Introduce el primer componente a cambiar";
			cin >> componente1;
			cout << "Introduce el segundo componente a cambiar";
			cin >> componente2;
			cadena.IntercambiaComponentes(componente1, componente2);
			cadena.MostrarCadena();
			break;
	}
	if(option != 0){
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
				<< "6. Intercambiar componentes." << endl
				<< "\n\n0. salir" << endl;
			cin >> option;
		} while(option <= 0 && option > 6);
		Menu(cadena);
	}
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	SecuenciaCaracteres cadena;

	// ENTRADA DE DATOS DEL PROGRAMA
	Menu(cadena);

	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
