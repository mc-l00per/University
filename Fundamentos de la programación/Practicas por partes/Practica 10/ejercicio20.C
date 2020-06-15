
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
using namespace std;


// DECLARACIÓN DE VARIABLES GLOBALES
const double PI = 3.14159,
	B0 = 0.2316419,
	B1 = 0.319381530,
	B2 = -0.356563782,
	B3 = 1.781477937,
	B4 = -1.821255978,
	B5 = 1.330274429;

//DECLARACION DE CLASES
class Gaussiana{
	private:
		double x;
		double esperanza;
		double desviacion;
		double n;
	public:
		void GetValorN(int p_n){
			n = p_n;
		}
		void GetValorX(int p_x){
			x = p_x;
		}
		void GetValorDesviacion(int p_desviacion){
			desviacion = p_desviacion;
		}
		void GetValorEsperanza(int p_esperanza){
			esperanza = p_esperanza;
		}
		void LeerDatos(){
			double p_x, p_desviacion, p_esperanza;
			cout << "Introduce el valor para la esperanza:";
			cin >> p_esperanza;
			cout << "Introduce el valor para la desviacion: ";
			cin >> p_desviacion;
			cout << "Introduce el valor para x:";
			cin>>p_x; 
			GetValorX(p_x);
			GetValorEsperanza(p_esperanza);
			GetValorDesviacion(p_desviacion);
		}
		void LeerValorNTeclado(){
			int p_n;
			cout << "Introduce el valor para n:";
			cin>>p_n; 
			GetValorN(p_n);
		}
		double CalcularGaussiana(){
			return (1/(desviacion*sqrt(2*PI))) * exp((-0.5*pow((x - esperanza)/desviacion, 2)));
		}
		void MostrarValorGaussianaNVeces(){
			LeerValorNTeclado();
			for(int i=0; i<=n; i++){
				GetValorX(i);
				cout << "El valor para la absica: " << x << " es: " << CalcularGaussiana() << endl;
			}
		}
		double CdfX(){
			double t = 1/(1+B0*x);
			double constante = (B1*t)+(B2*pow(t,2))+(B3*pow(t,3))+(B4*pow(t,4))+(B5*pow(t,5));
			return 1 - CalcularGaussiana()*constante;
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

void Menu(int option){
	bool  salir = false;
	switch(option){
		case 1:
			gausiana.LeerDatos();
		case 2:
			cout << "El valor para la gausiana de " << gausiana.SetX() << ": "
			<< gausiana.CalcularGaussiana() << endl;
		case 3:
			gausiana.MostrarValorGaussianaNVeces();
		case 4:

	}
	if(!salir){
		cout << "Selecciona una opcion:" << endl
			<< "1. Introducir nuevos datos" << endl
			<< "2. Calcular Gaussiana" << endl
			<< "3. Calcular Gausiana  con n abcisas" << endl
			<< "4. Obteber CDF(x)" << endl
			<< "5. Camviar el valor de X" << endl
			<< "\n\t0. Salir";
		cin >> option;
		Menu(option);
	}
}
int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	int option;
	Gaussiana gausiana;

	// ENTRADA DE DATOS DEL PROGRAMA
	gausiana.LeerDatos();

	// CUERPO DEL PROGRAMA 
	Menu(option);

	// SALIDA DE DATOS

	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
