
/**      
  * ejercicio06.cpp
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
#include <chrono>
using namespace std;


// DECLARACIÓN DE VARIABLES GLOBALES
const int TAMANIO = 999;
int option = 1;

//CLASES

/**
 * Clase que agrupa todas la funciones de  tiempo que se utilizaran en la practica
 * @see Cronometro
 */
class Cronometro{
	//VARIABLES PRIVADAS DE LA CLASE
	private:
		typedef std::chrono::time_point<std::chrono::steady_clock> Punto_en_el_Tiempo;
		typedef chrono::duration <double, nano> IntervaloTiempo;
		Punto_en_el_Tiempo inicio;
		Punto_en_el_Tiempo final;
	//VARIABLES Y FUNCIONES PUBLIC
	public:
		/**
		 * Funcion para reiniciar el cronometro
		 * @see Reset
		 */
		void Reset(){
			inicio = chrono::steady_clock::now();
		}
		/**
		 * Calcula el valor que a transcurrido desde el reset
		 * @see MiliSegundosTrancurridos
		 * return El tiempo en milisegundos trancurrido desde el reset
		 */
		double MiliSegundosTranscurridos(){
			final = chrono::steady_clock::now();
			IntervaloTiempo diferencia = final - inicio;
			return diferencia.count() / 1e+6;
		}
};

/**
 * Clase que agrupa todas las funciones para poder trabajar con una secuencia de caracteres
 * @see SecuenciaCaracteres
 */
class SecuenciaCaracteres{
	//VARIABLES PRIVADAS DE LA CLASE
	private:
		char cadena[TAMANIO];
		int total_utilizados;
	//VARIABLES Y FUNCIONES PUBLIC
	public:
		/**
		 * Función para introducir una cadena quedando el valor almacenado en cadena
		 * @see GetCadena
		 */
		void GetCadena(char p_cadena[]){
			for(int i=0; i<total_utilizados; i++)
				cadena[i] = p_cadena[i];
		}
		/**
		 * Función para introducir total utilizandos quedando el valor almacenado en total_utilizados
		 * @see GetTotalUtilizados
		 */
		void GetTotalUtilizados(int p_total_utilizados){
			total_utilizados = p_total_utilizados;
		}
		/**
		 * Funcion para leer la cadena desde teclado
		 * @see LeerCadena
		 */
		void LeerCadena(){
			char p_cadena[TAMANIO], caracter;
			int p_total_utilizados = 0;
			cout << "Introduce cadena de caracter (cerrar cadena con '#'): ";
			do {
				caracter = cin.get();
				p_cadena[p_total_utilizados] = caracter;
				p_total_utilizados++;
			} while(total_utilizados != TAMANIO && caracter != '#');
			GetTotalUtilizados(p_total_utilizados);
			GetCadena(p_cadena);
		}
		/**
		 * Muestra la cadena de caracteres
		 * @see MostrarCadena 
		 */
		void MostrarCadena(){
			for (int i = 0; i < total_utilizados; ++i)
				cout << "   " << cadena[i];
			cout << endl;
		}
		/**
		 * Comprueba si la cadena es un palindromo
		 * @see EsPalindromo
		 * @return true si es palindromo false en caso contrario
		 */
		bool EsPalindromo(){
			for(int i = 0, j = total_utilizados-1; i < total_utilizados/2 && j > total_utilizados/2; i++, j--){
				cout << cadena[i] << cadena[j] <<endl;
				if(cadena[i] != cadena[j])
					return false;
			}
			return true;
		}
		/**
		 * Invierte la cadena de caracteres y muestra la cadena combertida
		 * @see Invierte
		 */
		void Invierte(){
			for(int i=0, j=total_utilizados-1; i<total_utilizados/2; i++, j--)
				IntercambiaComponentes(i,j);
		}
		/**
		 * Cuentas las mayusculas que tenemos en la cadena
		 * @see ContarMayusculas
		 * @return Devuelve el número de mayusculas que tenemos
		 */
		int ContarMayusculas(){
			int numero_mayusculas = 0;
			for(int i = 0; i < total_utilizados; i++)
				if(cadena[i] <= 'Z' && cadena[i] >=  'A')
					numero_mayusculas++;
			return numero_mayusculas;
		}
		/**
		 * Intercambia dos componentes conociendo sus posiciones
		 * @see IntercambiaComponentes
		 * @param x Posicion de uno de los componentes que queremos cambiar
		 * @param y Posicion del otro componente que queremos intercambiar
		 */
		void IntercambiaComponentes(int x, int y){
			char aux_caracter = cadena[x];
			cadena[x] = cadena[y];
			cadena[y] = aux_caracter;
		}
		/**
		 * Elimina el elemento de una posicion concreta
		 * @see Eliminar
		 */
		void Elimina(int i){
			while(cadena[i] != '#'){
				cadena[i] = cadena[i+1];
				i++;
			}
			cadena[i] = '#';
			total_utilizados--;
		}
		/**
		 * Eliminar todas las mayusculas de un vector
		 * @see EliminarMayusculas
		 */
		void EliminarMayusculas(){
			int i = 0;
			while(i<total_utilizados)
				if(cadena[i] >= 'A' && cadena[i] <= 'Z')
					Elimina(i);
				else
					i++;
		}
		/**
		 * Eliminar mayusculas de forma eficiente
		 * @see EliminarMayusculasEficiente
		 */
		void EliminarMayusculasEficiente(){
			char p_cadena[TAMANIO];
			int posicion_lectura = 0, posicion_escritura = 0;
			for(int i=0; i<total_utilizados; i++){
				if(cadena[posicion_lectura] >= 'a' && cadena[posicion_lectura] <= 'z'){
					p_cadena[posicion_escritura] = cadena[posicion_lectura];
					posicion_lectura++;
					posicion_escritura++;
				}
				else
					posicion_lectura++;
			}
			GetCadena(p_cadena);
		}
		/**
		 * Elimina los caracteres repetidos
		 * @see EliminarRepetidosA
		 */
		void EliminarRepetidosA(){
			char sin_repetir[TAMANIO];
			int p_total_utilizados = 1;
			bool esta = false;
			for(int i=0; i<total_utilizados; i++){
				for(int j=0; j<p_total_utilizados; j++){
					if(cadena[i] == sin_repetir[j])
						esta = true;
				}
				if(!esta){
					sin_repetir[p_total_utilizados] = cadena[i];
					p_total_utilizados++;
				}
			}
			GetTotalUtilizados(p_total_utilizados);
			GetCadena(sin_repetir);
		}
		/**
		 * Elimina los caracteres repetidos
		 * @see EliminarRepetidosB
		 */
		void EliminarRepetidosB(){
			for(int i=0; i<total_utilizados; i++)
				for(int j=i+1; j<total_utilizados; j++)
					if(cadena[i] == cadena[j])
						Elimina(j);
		}
		/**
		 * Compara los dos tipo de calculo de mayuscula y muestra ambos resultados por pantalla
		 * @see CompararEliminadorMayusculas
		 */
		void CompararEliminadorMayusculas(){
			SecuenciaCaracteres p_cadena;
			p_cadena.GetTotalUtilizados(total_utilizados);
			p_cadena.GetCadena(cadena);
			Cronometro crono;
			crono.Reset();
			EliminarMayusculas();
			cout << "Tiempo tardado para mayusculas sin eficiencia: " 
				<< crono.MiliSegundosTranscurridos() << endl;
			MostrarCadena();
			crono.Reset();
			p_cadena.EliminarMayusculasEficiente();
			cout << "Tiempo tardado para mayusculas con eficiencia: " 
				<< crono.MiliSegundosTranscurridos() << endl;
			p_cadena.MostrarCadena();
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
		<< "         ()__)      |       EJERCCICIO: 06        |       (__()" << endl
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
	cout << "\n\nPress 'Enter' to indiceinue: ... ";
	while ( getchar() != '\n');
}

/**
 * Funcion que nos muestra el menu del programa
 * @see Menu
 * @param cadena la cadena que quetemos almacenar
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
			Pausa();
			break;
		case 3:
			cadena.Invierte();
			Pausa();
			break;
		case 4:
			cout << "Hay " << cadena.ContarMayusculas() << " letras en mayuscula." << endl;
			Pausa();
			break;
		case 5:
			cadena.MostrarCadena();
			Pausa();
			break;
		case 6:
			int componente1, componente2;
			cout << "Introduce el primer componente a cambiar";
			cin >> componente1;
			cout << "Introduce el segundo componente a cambiar";
			cin >> componente2;
			cadena.IntercambiaComponentes(componente1, componente2);
			cadena.MostrarCadena();
			Pausa();
			break;
		case 7:
			cadena.EliminarMayusculas();
			cadena.MostrarCadena();
			Pausa();
			break;
		case 8:
			cadena.EliminarRepetidosA();
			cadena.MostrarCadena();
			Pausa();
			break;
		case 9:
			cadena.CompararEliminadorMayusculas();
			Pausa();
			break;
	}
	if(option != 0){
		system("clear");
		do {
			cout << "Selecciona una de estas opcicones:" << endl
				<< "1. Introducir una cadena." << endl
				<< "2. Comprobar si es palindromo." << endl
				<< "3. Invertir la cadena." << endl
				<< "4. Contar mayusculas" << endl
				<< "5. Mostrar cadena." << endl
				<< "6. Intercambiar componentes." << endl
				<< "7. Eliminar mayusculas." << endl
				<< "8. Eliminar reperidos." << endl
				<< "9. Comprobar eficiencia de eliminar mayusculas" << endl
				<< "\n\n0. salir" << endl;
			cin >> option;
		} while(option <= 0 && option > 9);
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

 
