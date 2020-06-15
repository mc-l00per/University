/** 
  * ejercicio06.cpp
  *
  * Copyright 2016 Antonio Rodríguez Alaminos <aralaminos@correo.ugr.es>
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

/////////////////////////////////////////////////////////////////////////
// DEPENDENCIAS DEL PROGRAMA.
/////////////////////////////////////////////////////////////////////////

#include <iostream> 	//para poder utilizar las entradas y salidas del codigo
#include <cctype>
#include <stdio.h> 		//para el system pause articial
#include <stdlib.h> 	//dependencia para las llamadas system de windows
#include <unistd.h> 	//para poder utilizar el usleep y otros comandos
using namespace std;

/////////////////////////////////////////////////////////////////////////
// DECLARACIÓN DE VARIABLES GLOBALES
/////////////////////////////////////////////////////////////////////////

const int TAM = 100;
const int TAM_PROCESADAS = 'z' - 'a';

/////////////////////////////////////////////////////////////////////////
//CLASES
/////////////////////////////////////////////////////////////////////////

/**
 * Clase con las opciones del menu de presentacion
 * @see Menu
 */
class Menu{
	
	private:
		int option;
	
	public:
		/**
		 * Constructor por defecto
		 * @see Menu
		 */
		Menu() :option(0){			
		}
		/**
		 * Cambiar option
		 * @see Option
		 * @param p_option opcion que queremos tener
		 */
		void Option(int p_option){
			option = p_option;
		}
		/**
		* Introducción personal al programa
		* @see Inicio
		*/
		void Inicio(){
			cout << endl << "\033[31m" << endl << endl << "\t                                              ____   ___" << endl 
			<< "\t  /\\   /\\    ____    /\\   /\\  _____   ___.__. \\   \\ /  /" << endl
			<< "\t /  \\ /  \\ _/ ___\\  /  \\ /  \\ \\__  \\ <   |  |  \\      /" << endl
			<< "\t/    Y    \\\\  \\___ /    Y    \\ / __ \\_\\___  |  /      \\" << endl
			<< "\t\\_/\\___/\\_/ \\___  >\\_/\\___/\\_/(____  // ____| /___/\\   \\" << endl
			<< "\t                \\/                 \\/ \\/            \\__/" << endl << endl
			<< "                           \\ ||| /" << endl
			<< "     .-.________            (o o)                      ________.-." << endl
			<< "----/ \\_)_______)   +--oooO-----------------------+   (_______(_/ \\----" << endl
			<< "   (     ()___)     |                             |      (___()    )" << endl
			<< "         ()__)      |       EJERCCICIO: 06        |       (__()" << endl
			<< " ----\\___()_)       |                             |        (_()___/---" << endl
			<< "                    +-----------------Ooo---------+" << "\033[37m" << endl;
			usleep(2000000);
			system("clear");
		}
		/**
		* Salida personal del programa
		* @see Fin
		*/  
		void Fin(){
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

};

/////////////////////////////////////////////////////////////////////////

/**
 * Clase secuencia de enteros
 * @see SecuenciaEnteros
 */
class SecuenciaEnteros{

	private:
		int enteros[TAM];
		int total_utilizados;

	public:
		/**
		 * Constructor por defecto
		 * @see SecuenciaEnteros
		 */
		SecuenciaEnteros() :total_utilizados(0){

		}
		/**
		 * Almacenas los valores del vector
		 * @see AsignarEnteros
		 * @param p_enteros Vector de enteros que queremos almacenar
		 */
		void AsignarEnteros(int p_enteros[]){
			for(int i=0; i<TotalUtilizados(); i++)
				enteros[i] = p_enteros[i];
		}
		void AsignarTotalUtilizados(int p_total_utilizados){
			total_utilizados = p_total_utilizados;
		}
		void AnaideEntero(){
			int p_enteros[TAM];
			int i = 0, entero;
			do{
				cin >> entero;
				p_enteros[i] = entero;
				i++;
			} while (entero != -1);
			AsignarTotalUtilizados(i);
			AsignarEnteros(p_enteros);
		}
		int TotalUtilizados(){
			return total_utilizados;
		}
		int Elemento(int indice){
			return enteros[indice];
		}
};

/////////////////////////////////////////////////////////////////////////

/**
 * Clase que contiene todo lo relacionado con las cadenas de caracteres
 * @see SecuenciaCaracteres
 */
class SecuenciaCaracteres{
	
	private:
		char cadena[TAM];
		int procesadas[TAM_PROCESADAS];
		int total_utilizados;

	public:
		/**
		 * Constructor por defecto
		 * @see SecuenciaCaracteres
		 */
		SecuenciaCaracteres() :total_utilizados(0){

		}
		/**
		 * Muestra el tamaño total de la cadena
		 * @see TotalUtilizados
		 * @return El tamaño de la cadena
		 */
		int TotalUtilizados(){
			return total_utilizados;
		}
		void AsignarTotalUtilizados(int p_total_utilizados){
			total_utilizados = p_total_utilizados;
		}
		/**
		 * Añade los valores a la cadena privada
		 * @see AsignarCadena
		 * @param p_cadena Cadena que queremos almacenar
		 */
		void AsignarCadena(char p_cadena[]){
			for(int i=0; i<total_utilizados; i++)
				cadena[i] = p_cadena[i];
		}
		/**
		 * Obtiene una cadena para almacenar y su tamaño
		 * @see AnaideCadena
		 */
		void AnaideCadena(){
			char caracter, p_cadena[TAM];
			int p_total_utilizados = 0;
			do {
				cin.get(caracter);
				p_cadena[p_total_utilizados] = caracter;
				p_total_utilizados++;
			} while (caracter != '#');
			AsignarTotalUtilizados(p_total_utilizados-1);
			AsignarCadena(p_cadena);
		}
		/**
		 * Muestra un elemento de la cadena
		 * @see Elemento
		 * @see indice Posicion del elemento que queremos mostrar
		 * @return valor elemento seleccionado
		 */
		char Elemento(int indice){
			return cadena[indice];
		}
		/**
		 * Muestra la cadena introducida
		 * @see MostrarCadena
		 */
		void MostrarCadena(){
			for(int i=0; i<TotalUtilizados(); i++)
				cout << cadena[i];
			cout << endl;
		}
		/**
		 * Eliminar pasando un vector deposiciones
		 * @see EliminarPorPosicion
		 * @param posicion_eliminados
		 */
		void EliminarPorPosicion(SecuenciaEnteros posicion_eliminados){
			char aux_cadena[TAM];
			int i_aux = 0;
			for(int i=0; i<TotalUtilizados(); i++){
				bool eliminar = false;
				for(int j=0; j<posicion_eliminados.TotalUtilizados() && !eliminar; j++){
					if(i == posicion_eliminados.Elemento(j))
						eliminar = true;
				}
				if(!eliminar){
					aux_cadena[i_aux] = cadena[i];
					i_aux++;
				}
			}
			AsignarTotalUtilizados(TotalUtilizados() - posicion_eliminados.TotalUtilizados() + 1);
			AsignarCadena(aux_cadena);
		}
};

/////////////////////////////////////////////////////////////////////////
//FUNCIONES
/////////////////////////////////////////////////////////////////////////

/**
 * Limpiar el buffer
 * @see Limpiar
 */
void Limpiar(){
	cin.ignore(256,'\n');
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

/////////////////////////////////////////////////////////////////////////
//MAIN
/////////////////////////////////////////////////////////////////////////

int main() {
	// DECLARACIÓN DE VARIABLES LOCALES
	Menu menu;
	SecuenciaCaracteres cadena;
	SecuenciaEnteros posicion_eliminados;

	// ENTRADA DE DATOS DEL PROGRAMA
	menu.Inicio();
	cout << "Introduce la cadena: ";
	cadena.AnaideCadena();
	cout << "Introduce la secuencia de caracteres a eliminar.";
	posicion_eliminados.AnaideEntero();

	// CUERPO DEL PROGRAMA 
	cadena.EliminarPorPosicion(posicion_eliminados);

	// SALIDA DE DATOS
	cadena.MostrarCadena();
	
	Pausa();

	// FINAL Y PAUSA DEL SISTEMA.
	menu.Fin();
}

 
