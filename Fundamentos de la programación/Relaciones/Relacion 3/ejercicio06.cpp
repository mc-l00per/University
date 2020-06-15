
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
using namespace std;


// DECLARACIÓN DE VARIABLES GLOBALES

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

/**
 * Funcion para calcular las horas extra
 * @see HorasExtras
 * @param horas_total
 * @return horas extra
 */
int HorasExtras(int horas_total){
	return horas_total - 40;
}

/**
 * Funcion para calcular el salario de las horas extra
 * @see SalarioExtra
 * @param horas_extra
 * @param tarifa
 * @return salario de las horas extra
 */
double SalarioExtra(int horas_extra, double tarifa){
	if(horas_extra>40)
		return (HorasExtras(horas_extra) * (tarifa + tarifa * 0.5));
	else
		return 0.0;
}

/**
 * Funcion para calcular el salario base
 * @see SalarioBase
 * @param horas_total
 * @param tarifa
 * @return salario base
 */
double SalarioBase(int horas_total, double tarifa){
	if(horas_total>40)
		return 40 * tarifa;
	else
		return horas_total * tarifa;
}

/**
 * Funcion para calcular el salario total
 * @see SalarioTotal
 * @param horas_total
 * @param tarifa
 * @return salario total
 */
double SalarioTotal(int horas_total, double tarifa){
	return SalarioBase(horas_total, tarifa) + SalarioExtra(horas_total, tarifa);
}

/**
 * Funcion para obtener datos
 * @see LeerDatos
 * @param &horas_total
 * @param &tarifa
 */
void LeerDatos(int &horas_total, double &tarifa){
	do{
		cout << "Introduce las horas cotizadas: ";
		cin >> horas_total;
		if(horas_total<0)
			cout << "No se admiten horas negativas." << endl;
	} while (horas_total<0);

	do{
		cout << "Introduce la tarifa: ";
		cin >> tarifa;
		if(horas_total<0)
			cout << "No se admiten tarifa negativas." << endl;
	} while (tarifa<0);
}

/**
 * Funcion para mostrar los datos obtenidos
 * @see MostrarDastos
 * @param salario_total
 */
void MostrarDastos(double salario_total){
	cout << "El salario final es  de: " << salario_total << endl;
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	double salario_total, tarifa;
	int horas_total;

	// ENTRADA DE DATOS DEL PROGRAMA
	LeerDatos(horas_total, tarifa);

	// CUERPO DEL PROGRAMA 
	salario_total = SalarioTotal(horas_total, tarifa);

	// SALIDA DE DATOS
	MostrarDastos(salario_total);

	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
