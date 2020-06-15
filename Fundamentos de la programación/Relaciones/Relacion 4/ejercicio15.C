/**      
  * ejercicio15.cpp
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
const int IRPF=21;

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
			<< "         ()__)      |       EJERCCICIO: 15        |       (__()" << endl
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
		/**
		* Pausa del sistema, mas intro para continuar
		* @see Pausa
		*/
		void Pausa(){
			cin.ignore(256,'\n');
			cout << "\n\nPress 'Enter' to continue: ... ";
			while ( getchar() != '\n');
		}
};

/////////////////////////////////////////////////////////////////////////

class RentaBruta{
	
	private:
		double renta;
		int retencion;
		bool autonomo;
		bool pensionista;
		bool soltero;
		
		/**
		 * comprueba y asigna el valor de S o N
		 * @see ComprobarSN
		 * @param option opcion que queremos asignar
		 * @return true si el valor es SI, false en caso contrario
		 */
		bool ComprobarSN(char option){
			if (option == 's' || option == 'S')
				return true;
			else if (option == 'n' || option == 'N')		
				return false;
		}

	public:
		/**
		 * constructor por defecto
		 * @see RentaBruta
		 */
		RentaBruta() :retencion(IRPF){}
		/**
		 * almacenar renta
		 * @see IngresarRenta
		 * @param p_renta
		 */
		void IngresarRenta(double p_renta){
			renta = p_renta;
		}
		/**
		 * Lee el valor que tendra la renta inicial
		 * @see LeerRenta
		 */
		void LeerRenta(){
			double p_renta;
			cin >> p_renta;
			IngresarRenta(p_renta);
		}
		/**
		 * Muestra el valor de la renta
		 * @see MostrarRenta
		 * @return el valor que tiene almacenado la variable renta
		 */
		double MostrarRenta(){
			return renta;
		}
		/**
		 * Alamcena el valor true o false para el autonomo
		 * @see IngresarAutonomo
		 * @param es_autonomo variable que contiene el char S o N
		 */
		void IngresarAutonomo(char es_autonomo){
			autonomo = ComprobarSN(es_autonomo);
		}
		/**
		 * Lee los valores de autonomo por teclado
		 * @see LeerAutonomo
		 */
		void LeerAutonomo(){
			char es_autonomo;
			cin >> es_autonomo;
			if(es_autonomo != 's' && es_autonomo != 'S' && es_autonomo != 'n' && es_autonomo != 'N')
				LeerAutonomo();
			else
				IngresarAutonomo(es_autonomo);
		}
		/**
		* Muestra el valor almacenado para la variable autonomo
		* @see MostrarAutonomo
		* @return true si es autonomo false en caso contratio
		*/
		bool MostrarAutonomo(){
			return autonomo;
		}
		/**
		 * Alamcena el valor true o false para el pensionista
		 * @see IngresarPensionista
		 * @param estado variable que contiene el estado
		 */
		void IngresarPensionista(bool estado){
			pensionista = estado;
		}
		/**
		 * Lee los valores de pensionista por teclado
		 * @see LeerPensionista
		 */
		void LeerPensionista(){
			int edad;
			cin >> edad;
			if(edad>65)
				IngresarPensionista(true);
			else
				IngresarPensionista(false);
		}
		/**
		* Muestra el valor almacenado para la variable pensionista
		* @see MostrarPensionista
		* @return true si es pensionista false en caso contratio
		*/
		bool MostrarPensionista(){
			return pensionista;
		}
		/**
		 * Alamcena el valor true o false para el soltero
		 * @see IngresarSoltero
		 * @param estado variable que contiene el char S o N
		 */
		void IngresarSoltero(char estado){
			soltero = ComprobarSN(estado);
		}
		/**
		 * Lee los valores de soltero por teclado
		 * @see LeerSoltero
		 */
		void LeerSoltero(){
			char estado;
			cin >> estado;
			if(estado != 's' && estado != 'S' && estado != 'n' && estado != 'N')
				LeerSoltero();
			else
				IngresarSoltero(estado);
		}
		/**
		* Muestra el valor almacenado para la variable soltero
		* @see MostrarSoltero
		* @return true si es soltero false en caso contratio
		*/
		bool MostrarSoltero(){
			return soltero;
		}
		/**
		 * calcula la renta final de la persona
		 * @see RentaFinal
		 */
		double RentaFinal(){
			double renta_final = MostrarRenta();
			if(MostrarAutonomo())
				retencion -= 3;
			else if(MostrarPensionista())
				retencion += 1;
			else{
				retencion += 2;
				if(MostrarRenta() < 20000)
					retencion += 2;
				else
					if(!MostrarSoltero() && MostrarRenta() > 20000)
						retencion += 2.5;
					else if(MostrarSoltero() && MostrarRenta() > 20000)
						retencion += 3;
			}
			return MostrarRenta() - ((MostrarRenta() * retencion) / 100);
		}
};

/////////////////////////////////////////////////////////////////////////
//FUNCIONES
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
//MAIN
/////////////////////////////////////////////////////////////////////////
int main() {
	// DECLARACIÓN DE VARIABLES LOCALES
	Menu menu;
	RentaBruta renta;

	// ENTRADA DE DATOS DEL PROGRAMA
	menu.Inicio();
	cout << "Introduce la renta del cliente:";
	renta.LeerRenta();
	cout << "Introduce si el cliente es autonomo S o N";
	renta.LeerAutonomo();
	cout << "Introduce si el cliente es soltero S o N";
	renta.LeerSoltero();
	cout << "Introduce la edad del cliente";
	renta.LeerPensionista();

	// CUERPO DEL PROGRAMA 
	
	// SALIDA DE DATOS
	cout << "La renta final es de: " << renta.RentaFinal() << endl << flush;
	menu.Pausa();

	// FINAL Y PAUSA DEL SISTEMA.
	menu.Fin();
}

 
