
/**      
  * ejercicio19.cpp
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
#include <cmath>
#include <limits>

using namespace std;


// DECLARACIÓN DE VARIABLES GLOBALES

// CLASES
class ProgresionGeometrica{
	//Variables privativas del objeto
	private:
		double a;
		double r;
		double k;
		double tope;
	//Variables publicas y funciones del objeto
	public:
		/**
		 * Constructor por defecto de la clase
		 * @see ProgresionGeometrica
		 */
		ProgresionGeometrica(double p_a, double p_r, double p_k){
			a = p_a;
			r = p_r;
			k = p_k;
		}
		/**
		 * Funcion para añadir el valor del tope de la sucesion que queremos mostrar
		 * @see GetValorTope
		 * @ param p_tope Valor que tendra el tope de datos que queremos mostrar
		 */
		void GetValorTope(int p_tope){
			if(tope<=k)
				tope = p_tope;
		}
		/**
		 * Funcion para obtener el valor de k-esimo termino
		 * @see Termino
		 * @param k_esimo Posicion que quetemos obtener
		 */
		double Termino(int k_esimo){
			return a * pow(r, k_esimo*1.0);
		}
		double SumaHastaInfinito(){
			double result = a;
			for(int i=0; i<numeric_limits<double>::max(); i++)
				result += pow(r, i)*a;
			return result;
		}
		double SumaHasta(){
			double result = a;
			for(int i=0; i<k; i++)
				result += pow(r, i)*a;
			return result;
		}
		double MultiplicaHasta(){
			double result = a, a_ans=a;
			for(int i=0; i<k; i++){
				a_ans = sqrt(pow(a * a_ans, i));
				result *= a_ans;
			}
			return result;
		}
		void MuestraHastaTope(){
			double result = a;
			for(int i=0; i<tope; i++){
				result += Termino(i);
				cout << "El valor en el paso " << i << " es: " << Termino(i) << endl;
			}
			cout << "El valor total hasta el tope introducido de la progresion es: " << result << endl;
		}
};

//FUNCIONES GLOBALES
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
		<< "         ()__)      |       EJERCCICIO: 19        |       (__()" << endl
		<< " ----\\___()_)       |                             |        (_()___/---" << endl
		<< "                    +-----------------Ooo---------+" << endl;
	usleep(2000000);
	system("clear");
}

/**
 * Salida personal del programa
 * @see Finb
 */
void Fin(){
	cin.ignore(256,'\n');
	cout << "\n\nPress 'Enter' to continue: ... ";
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

void LeerDatos(double &a, double &r, double &k){
	cout << "Introduce el valor para a:";
	cin >> a;
	cout << "Introduce el valor para r:";
	cin >> r;
	cout << "Introduce el valor para k:";
	cin >> k;
}

void LeerTopeMuestra(int &tope){
	cout << "Introduce el valor para tope:";
	cin >> tope;
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	double a, r, k;
	int tope;

	// ENTRADA DE DATOS DEL PROGRAMA
	LeerDatos(a,r,k);
	ProgresionGeometrica progresion_geometrica(a,r,k);
	LeerTopeMuestra(tope);
	progresion_geometrica.GetValorTope(tope);
	
	// SALIDA DE DATOS
	cout << "El valor total de la progresion total es: " << progresion_geometrica.SumaHasta() <<endl;
	progresion_geometrica.MuestraHastaTope();
	cout << endl;


	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
