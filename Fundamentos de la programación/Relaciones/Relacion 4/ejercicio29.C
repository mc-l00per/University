
/**      
  * ejercicio29.cpp
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
const int FIL = 50;
const int COL = 30;

//CLASES
class TableroBuscaMinas {
	private:
		bool matrizTablero[FIL][COL];
	public:
		TableroBuscaMinas(){
			InitTablero();
		}
		void InitTablero(){
			for(int i=0; i<FIL; i++)
				for(int j=0; j<COL; j++)
					matrizTablero[i][j] = false;
		}
		void IncluirMina(int i, int j){
			matrizTablero[i][j] = true;
		}		
		int ComprobarCasilla(int i, int j){
			int total_bombas = 0;
			if(matrizTablero[i][j] == true)
				return -1;
			else{
				if(i==0 && j==0){
					for(int z=i, y=j; z < i+1 && y < j+1; z++, y++)
						if(matrizTablero[z][y] == true)
							total_bombas++;
					return total_bombas;
				}else if(i==0 && j==COL-1){
					for(int z=i, y = j-1; z < i+1 && y<COL; z++, y++)
						if(matrizTablero[z][y] == true)
							total_bombas++;
					return total_bombas;
				}else if(i==FIL-1 && j==COL-1){
					for(int z=i-1, y=j-1; z<FIL && y<COL; z++, y++)
						if(matrizTablero[z][y] == true)
							total_bombas++;
					return total_bombas;
				}else if(i==COL-1 && j==0){
					for(int z=i-1, y=j; z<FIL && y<j+1; z++, y++)
						if(matrizTablero[z][y] == true)
							total_bombas++;
					return total_bombas;
				}else
					for(int z=i-1, y=j-1; z<i+1; z++, y++)
						if(matrizTablero[z][y] == true)
							total_bombas++;
					return total_bombas;
			}
		}
		void MostrarTablero(){
			for(int i=0; i<FIL; i++){
				for(int j=0; j<COL; j++)
					cout << " " << matrizTablero[i][j];
				cout << endl;
			}
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
		<< "         ()__)      |       EJERCCICIO: 29        |       (__()" << endl
		<< " ----\\___()_)       |                             |        (_()___/---" << endl
		<< "                    +-----------------Ooo---------+" << endl;
	usleep(2000000);
	system("clear");
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

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	TableroBuscaMinas tablero;

	// ENTRADA DE DATOS DEL PROGRAMA
	
	// CUERPO DEL PROGRAMA 
	tablero.IncluirMina(0,0);

	// SALIDA DE DATOS
	tablero.MostrarTablero();
	cout << "\nTotal Bombas: " << tablero.ComprobarCasilla(1,1) << endl;
 
	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
