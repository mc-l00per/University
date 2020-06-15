
/**      
  * ejercicio20.cpp
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
  * along long with this program; if not, write to the Free Software
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
const int TAM = 100;

//CLASES
/**
 * Clase que agrupa las funciones para trabajar con enteros
 * @see SecuenciaEnteros
 */
class SecuenciaEnteros{
	//DATOS PRIVADOS DE LA CLASE
	private:
		int cadena_enteros[TAM];
		int total_tutilizados;
	//DATOS PUBLICOS DE LA CLASE
	public:
		/**
		 * Introducion del valor privado cadena
		 * @see GetCadenaEnteros
		 */
		void GetCadenaEnteros(int p_cadena_enteros[]){
			for(int i=0; i<total_tutilizados; i++)
				cadena_enteros[i] = p_cadena_enteros[i];
		}
		/**
		 * Introducimos el valor privado total_utilizados
		 * @see GetTotalUtilizados
		 */
		void GetTotalUtilizados(int p_total_tutilizados){
			total_tutilizados = p_total_tutilizados;
		}
		/**
		 * Funcion que lee desde tecclado la cadenas de caracteres
		 * @see LeerCadenaEnteros
		 */
		void LeerCadenaEnteros(){	
			long long int entero;
			cout << "Introduce una cadena de enteros: ";
			cin >> entero;
			CrearCadenaEnteros(entero);
		}
		/**
		 * Mecanismos para fraccionar el entero introducido en la cadena de enteros y
		 * calcula el total utilizados
		 * @see CrearCadenaEnteros
		 * @param entero numero entero que forman la cadena de datos
		 */ 
		void CrearCadenaEnteros(long long int entero){
			int p_cadena_enteros[TAM];
			CalcularTotalUtilizados(entero);
			for(long long int i=CalcularDivisor(entero), j=0; i>0; i/=10,  j++){
				p_cadena_enteros[j] = entero/i;
				entero%=i;
			}
			GetCadenaEnteros(p_cadena_enteros);
		}
		/**
		 * Nos calcular el tamaño real que tiene el vector
		 * @see CalcularTotalUtilizados
		 * @param entero Manda la cadena de numero a un sin combertir a cadena de enteros
		 * @return Devuelve el tamaño maximo que puede tener la cadena
		 */
		void CalcularTotalUtilizados(long long int p_entero){
			int p_total_tutilizados = 0;
			while(p_entero > 1){
				p_entero /= 10;
				p_total_tutilizados++;
			}
			GetTotalUtilizados(p_total_tutilizados);
		}
		long long int CalcularDivisor(long long int p_entero){
			long long int divisor = 1;
			while(p_entero > 10){
				p_entero /= 10;
				divisor *= 10;
			}
			return divisor;
		}
		void MostrarCadena(){
			for(int i=0; i<total_tutilizados; i++)
				cout << "   " << cadena_enteros[i];
			cout << endl;
		}
		int SecuenciaAscendentes(){
			int contador_cadenas_ascendentes = 1;
			for(int i=0; i<total_tutilizados-1; i++){
				if(cadena_enteros[i] > cadena_enteros[i+1])
					contador_cadenas_ascendentes++;
			}
			return contador_cadenas_ascendentes;
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
		<< "         ()__)      |       EJERCCICIO: 20        |       (__()" << endl
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

/**
 * Pausa del sistema, mas intro para continuar
 * @see Pausa
 */
void Pausa(){
	cin.ignore(256,'\n');
	cout << "\n\nPress 'Enter' to indiceinue: ... ";
	while ( getchar() != '\n');
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	SecuenciaEnteros secuencia_enteros;

	// ENTRADA DE DATOS DEL PROGRAMA
	secuencia_enteros.LeerCadenaEnteros();

	// SALIDA DE DATOS
	cout << "El  número de cadenas accendentes introducidas son: " << secuencia_enteros.SecuenciaAscendentes() << endl;
	
	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
