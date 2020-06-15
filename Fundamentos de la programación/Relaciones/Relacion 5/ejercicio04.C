/** 
  * ejercicio04.cpp
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
			<< "         ()__)      |       EJERCCICIO: 04        |       (__()" << endl
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
			ObtenerProcesada();
		}
		/**
		 * Comprueba si dos cadenas son similares
		 * @see EssimilarQue
		 * @return true si son similares false en caso contrario
		 */
		bool EsSimilarQue(SecuenciaCaracteres p_cadena){
			bool es_similar_que = true;
			
			if(TotalUtilizados() != p_cadena.TotalUtilizados())
				es_similar_que = false;
			else if(Elemento(0) != p_cadena.Elemento(0))
				es_similar_que = false;
			else if(Elemento(TotalUtilizados()-1) != p_cadena.Elemento(TotalUtilizados()-1)){
				es_similar_que = false;
			}
			else if(!ProcesadasIguales(p_cadena))
				es_similar_que = false;

			return es_similar_que;
		}
		/**
		 * Comprueba si dos cadenas tinen el mismo numero de letras
		 * @see ProcesadasIguales
		 * @param p_cadena Cadena que queremos comparar
		 * @return true si son iguales false en caso contrario
		 */
		bool ProcesadasIguales(SecuenciaCaracteres p_cadena){
			for(int i=0; i<TAM_PROCESADAS; i++)
				if(ElementoProcesada(i) != p_cadena.ElementoProcesada(i))
					return false;
								
			return true;
		}
		/**
		 * Genera un vector que almacena cuantas letras tiene la cadena 
		 * @see ObtenerProcesada
		 */
		void ObtenerProcesada(){
			for(int i=0; i<TAM_PROCESADAS; i++)
				procesadas[i] = 0;
			for(int j=0; j<TotalUtilizados(); j++){
				char car_min = 'a';
				char car_may = 'A';
				for(int i=0; i<TAM_PROCESADAS; i++){
					if(Elemento(j)== car_min || Elemento(j)==car_may){
						procesadas[i]++;
						car_min++;
						car_may++;
					}
					else{
						car_min++;
						car_may++;
					}
				}
			}
		}
		/**
		 * Muestra cuantas letras hay para ese indice
		 * @see ElementoProcesada
		 * @param indice posicion de la letra que queremos comprobar
		 * @return cuantas letras hay como esa
		 */
		int ElementoProcesada(int indice){
			return procesadas[indice];
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
		 * Muestra la procesada
		 * @see MostrarProcesada
		 */
		 void MostrarProcesada(){
		 	for(int i=0; i<TAM_PROCESADAS; i++)
		 		cout << ElementoProcesada(i) << "   ";
		 	cout << endl;
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
	SecuenciaCaracteres cadena1, cadena2;

	// ENTRADA DE DATOS DEL PROGRAMA
	menu.Inicio();
	cout << "Introduce la cadena 1: ";
	cadena1.AnaideCadena();

	//limpio el buffer de enter
	Limpiar();

	cout << "Introduce la cadena 2: ";
	cadena2.AnaideCadena();

	// CUERPO DEL PROGRAMA 
	//cadena1.MostrarProcesada();
	//cadena2.MostrarProcesada();

	// SALIDA DE DATOS
	if(cadena1.EsSimilarQue(cadena2))
		cout << "Si son similares.";
	else
		cout << "No son similares.";
	
	Pausa();

	// FINAL Y PAUSA DEL SISTEMA.
	menu.Fin();
}

 
