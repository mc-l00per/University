
/**      
  * ejercicio01.cpp
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

// CLASES

class Alumno_FP {
	private:
		string nombre, apellido, dni;
		double teoria = 0.0;
		double parcial_pract1 = 0.0; 
		double parcial_pract2 = 0.0; 
		double participacion_clase = 0.0;

	public:
		Alumno_FP(string p_nombre, string p_apellido, string p_dni){
			nombre = p_nombre;
			apellido = p_apellido;
			dni = p_dni;
		}
		
		double PorcentajeTeoria(){
			return 0.7;
		}
		double PorcentajePract1(){
			return 0.05;
		}
		double PorcentajePract2(){
			return 0.15;
		}
		double PorcentajeParticipacionClase(){
			return 0.1;
		}

		void SetNotaTeoria(double p_teoria){
			teoria = p_teoria;
		}
		
		void SetNotasPracticas(double p_parcial_pract1, double p_parcial_pract2){
			parcial_pract1 = p_parcial_pract1;
			parcial_pract2 = p_parcial_pract2;
		}

		void SetNotaParticipacionClase(double p_participacion_clase){
			participacion_clase = p_participacion_clase;
		}

		string GetNombre() {
			return nombre;
		}

		string GetApellido(){
			return apellido;
		}

		string GetDni() {
			return dni;
		}

		double GetNotaTeoria(){
			return teoria;
		}

		double GetNotaParcialPract1(){
			return parcial_pract1;
		}

		double GetNotaParcialPract2(){
			return parcial_pract2;
		}

		double GetNotaParticipacionClase(){
			return participacion_clase;
		}

		double NotaFinal(){
			return parcial_pract1 * PorcentajePract1() + parcial_pract2 * PorcentajePract2() +
				teoria * PorcentajeTeoria() + participacion_clase * PorcentajeParticipacionClase();
		}
};

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
		<< "         ()__)      |       EJERCCICIO: 18        |       (__()" << endl
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
	exit;
}


int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	Alumno_FP alumno("Antonio", "Rodríguez Alaminos", "74725175-S");

	alumno.SetNotasPracticas(10, 0);
	alumno.SetNotaTeoria(0);
	alumno.SetNotaParticipacionClase(10);

	// ENTRADA DE DATOS DEL PROGRAMA
	
	// CUERPO DEL PROGRAMA 
	
	// SALIDA DE DATOS
	cout << "La nota final seria: " << alumno.NotaFinal() << endl;

	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
